#include <stdint.h>
#include "snes9x.h"
#include "memmap.h"
#include "apu.h"
#include "gfx.h"

#include <emscripten/emscripten.h>

extern "C" {

// Emulator initialisieren
EMSCRIPTEN_KEEPALIVE
void core_init() {
    S9xInit();
    S9xInitSound(0);
    Memory.Init();
}

// ROM aus Buffer laden
EMSCRIPTEN_KEEPALIVE
void core_load_rom(uint8_t* data, int size) {
    // Falls Snes9x keine direkte Buffer-Funktion hat,
    // kannst du hier temporär eine Datei simulieren.
    // Für viele Forks gibt es aber sowas wie:
    // Memory.LoadROMFromBuffer(data, size);

    Memory.LoadROMFromBuffer(data, size);
}

// Einen Frame ausführen
EMSCRIPTEN_KEEPALIVE
void core_run_frame() {
    S9xMainLoop();
}

// Framebuffer zurückgeben (für Canvas)
EMSCRIPTEN_KEEPALIVE
uint8_t* core_get_framebuffer() {
    return GFX.Screen; // typischerweise 256x224, 16-bit oder 32-bit
}

// Zugriff auf RAM (für TAS / Tools)
EMSCRIPTEN_KEEPALIVE
uint8_t* core_get_memory() {
    return Memory.RAM;
}

}
