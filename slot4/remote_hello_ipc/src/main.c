#include <string.h>
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/ipc/ipc_service.h>

K_SEM_DEFINE(bound_sem, 0, 1);

static void bound_cb(void *priv)
{
	k_sem_give(&bound_sem);
}

static void recv_cb(const void *data, size_t len, void *priv)
{
	/* Data received */
}

static struct ipc_ept_cfg ept0_cfg = {
	.name = "ept0",
	.cb = {
		.bound	 = bound_cb,
		.received = recv_cb,
	},
};

int main(void)
{
	const struct device *inst0;
	unsigned char message[100];
	struct ipc_ept ept0;
	int ret;

	inst0 = DEVICE_DT_GET(DT_NODELABEL(ipc1));
	ret = ipc_service_open_instance(inst0);
	ret = ipc_service_register_endpoint(inst0, &ept0, &ept0_cfg);

	k_sem_take(&bound_sem, K_FOREVER);
	
	while(1) {
		sprintf(message, "%s is active for %u seconds\n", CONFIG_BOARD_TARGET, k_uptime_seconds());
		ret = ipc_service_send(&ept0, &message, strlen(message)+1);
		k_msleep(1000);
	}

	return 0;
}
