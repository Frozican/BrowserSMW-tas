#include <emscripten.h>
#include <stdint.h>

extern "C" {

EMSCRIPTEN_KEEPALIVE
void wasm_init() {
    core_init();
}

EMSCRIPTEN_KEEPALIVE
void wasm_load_rom(uint8_t* data, int size) {
    core_load_rom(data, size);
}

EMSCRIPTEN_KEEPALIVE
void wasm_run_frame() {
    core_run_frame();
}

EMSCRIPTEN_KEEPALIVE
uint8_t* wasm_get_framebuffer() {
    return core_get_framebuffer();
}

EMSCRIPTEN_KEEPALIVE
uint8_t* wasm_get_memory() {
    return core_get_memory();
}

}
