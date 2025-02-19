# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(joystick_led)

pico_sdk_init()

add_executable(joystick_led
    src/main.c
    src/adc.c
    src/pwm.c
    src/i2c_display.c
    src/buttons.c
)

pico_enable_stdio_usb(joystick_led 1)
pico_enable_stdio_uart(joystick_led 0)

target_link_libraries(joystick_led
    pico_stdlib
    hardware_adc
    hardware_pwm
    hardware_i2c
)

target_include_directories(joystick_led PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

pico_add_extra_outputs(joystick_led)

