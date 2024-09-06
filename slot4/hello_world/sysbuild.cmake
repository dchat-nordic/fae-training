ExternalZephyrProject_Add(
  APPLICATION remote_hello
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../remote_hello
  BOARD ${SB_CONFIG_REMOTE_BOARD_NAME}
)