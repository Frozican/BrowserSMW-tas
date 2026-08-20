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

extern "C" {
        EMSCRIPTEN_KEEPALIVE
        int load_rom(uint8_t* data, int size) {
                // 🧩 ROM-Daten in den Emulator laden
                // Hier später: Header prüfen, Speicher kopieren, Core vorbereiten
                // Für jetzt nur Dummy-Rückgabe
                return 1; // 1 = Erfolg
        }
}
