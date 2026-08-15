#include <stdint.h>

extern "C" {

    void core_init() {
            // Placeholder: will initialize SNES core later
    }

    void core_load_rom(const uint8_t* data, int size) {
            // Placeholder: will load ROM into emulator
    }

    void core_run_frame() {
            // Placeholder: will run one frame of emulation
    }

    uint8_t* core_get_framebuffer() {
            // Placeholder: will return framebuffer pointer
            return nullptr;
    }

    uint8_t* core_get_memory() {
            // Placeholder: will return SNES memory pointer
            return nullptr;
    }
}
