# 🔧 WASM build configuration for Snes9x Core

cmake_minimum_required(VERSION 3.15)

# Dieses CMake wird vom übergeordneten core/CMakeLists.txt eingebunden.
# Deshalb definieren wir hier KEIN eigenes Projekt.

# 🧩 WASM‑Quellen
set(WASM_SRC
    wasm_main.cpp
    wasm_bindings.cpp
)

# 🧱 Library hinzufügen (wird im Parent mit core verlinkt)
add_library(wasm_core STATIC ${WASM_SRC})

# 📁 Include‑Verzeichnisse
target_include_directories(wasm_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/snes9x
)

# ⚙️ Emscripten‑Flags
set_target_properties(wasm_core PROPERTIES
    COMPILE_FLAGS "-O3 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1"
)
