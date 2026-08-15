#include <emscripten/emscripten.h>

extern "C" {
        void core_init();
        void core_run_frame();
}

int main() {
        // 🧩 Emulator initialisieren
        core_init();

        // 🚀 JS ruft später core_run_frame() selbst auf,
        // daher bleibt main hier leer.
        return 0;
}
