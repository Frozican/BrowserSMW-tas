#pragma once

void core_init();
void core_load_rom(const unsigned char* data, int size);
void core_run_frame();
unsigned char* core_get_framebuffer();
unsigned char* core_get_memory();
