cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(main
    main.c
#     usb_descriptors.c
)

# Make sure TinyUSB can find tusb_config.h
target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib pico_unique_id tinyusb_device tinyusb_board)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)