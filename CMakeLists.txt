cmake_minimum_required(VERSION 3.20)
project(BrowserSMW_TAS LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🔧 SNES‑Core einbinden
add_subdirectory(core)

# 🌐 WebAssembly‑Output
set(CMAKE_EXECUTABLE_SUFFIX ".wasm")

# 🧱 Web‑Build‑Target
add_executable(browser_tas
    web/main.cpp
    )

# 🔗 Core‑Bibliothek verlinken
target_link_libraries(browser_tas PRIVATE core)

# 📁 Include‑Verzeichnisse
target_include_directories(browser_tas PRIVATE
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/core/src/snes9x
)

# ⚙️ Emscripten‑Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s USE_SDL=2 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")

# 📦 Ausgabeverzeichnis
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
