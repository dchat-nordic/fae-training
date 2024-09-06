#include <zephyr/kernel.h>

int main(void)
{
	printk("Hello world from nRF54H20 remote cpu\n");

	while(1) {
		printk("%s is active for %u seconds\n", CONFIG_BOARD_TARGET, k_uptime_seconds());
		k_msleep(1000);
	}

        return 0;
}
