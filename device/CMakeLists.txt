add_library(device_leds_board INTERFACE)
add_library(device::leds_board ALIAS device_leds_board)
file(GLOB device_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.c)
target_sources(device_leds_board INTERFACE
        ${device_SOURCES}
)
target_include_directories(device_leds_board INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)