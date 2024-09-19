ExternalZephyrProject_Add(
  APPLICATION remote_hello
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../remote_hello
  BOARD nrf54h20dk/nrf54h20/cpurad
)

ExternalZephyrProject_Add(
  APPLICATION remote_hello_ipc
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../remote_hello_ipc
  BOARD nrf54h20dk/nrf54h20/cpuppr
)
