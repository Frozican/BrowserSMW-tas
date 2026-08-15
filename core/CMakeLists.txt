cmake_minimum_required(VERSION 3.20)

project(SMWCore)

add_library(core
    wasm/wasm_main.cpp
        wasm/wasm_bindings.cpp
        )

        target_include_directories(core PUBLIC include)
        