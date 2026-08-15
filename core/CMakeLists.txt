cmake_minimum_required(VERSION 3.15)
project(Snes9xCore LANGUAGES C CXX)

# 🔍 Alle Snes9x‑Core Dateien einsammeln
file(GLOB_RECURSE SNES9X_SRC
    "src/snes9x/apu/*.cpp"
    "src/snes9x/common/*.cpp"
    "src/snes9x/data/*.cpp"
    "src/snes9x/jma/*.cpp"
    "src/snes9x/filter/*.cpp"
    "src/snes9x/*.cpp"
)

# WASM‑Ordner einbinden
add_subdirectory(wasm)

# 🧱 Core‑Bibliothek erstellen
add_library(core
    ${SNES9X_SRC}
)

# WASM‑Teil mit Core verlinken
target_link_libraries(core PRIVATE wasm_core)

# 📁 Include‑Verzeichnisse
target_include_directories(core PUBLIC
    include
    src/snes9x
)

# ⚙️ Emscripten Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
