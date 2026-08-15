cmake_minimum_required(VERSION 3.20)
project(BrowserSMW_TAS)

set(CMAKE_CXX_STANDARD 17)

# Placeholder for SNES Core
add_subdirectory(core)

# WebAssembly Output
set(CMAKE_EXECUTABLE_SUFFIX ".wasm")

# Build-Goal for Web
add_executable(browser_tas
    web/main.cpp
    )

    target_link_libraries(browser_tas PRIVATE core)
