# BrowserSMW-TAS

A fully browser-based TAS editor for **Super Mario World** and its ROM hacks.

## 🎯 Features
- Piano Roll editor
- Lua scripting (.mwtas)
- Movie import/export (.smv, .lsmv)
- Hitbox and sprite overlay
- Mobile support
- Frame-accurate input editing
- Savestates and ghost replays

## 🧩 Project structure
| Folder | Description |
|---------|--------------|
| `core/` | SNES emulator compiled to WebAssembly |
| `tas/` | TAS engine (frame advance, input injection) |
| `scripts/` | Custom script system (.mwtas) |
| `movies/` | Movie import/export support |
| `ui/` | Piano Roll, overlay, and editor UI |
| `web/` | Browser entry point |
| `docs/` | Technical documentation |

## 🚀 Build instructions
1. Compile the SNES core (Snes9x or bsnes) to WebAssembly.  
2. Open `web/index.html` in your browser.  
3. Load a `.mwtas` script and start TAS playback.

## 🧠 License
MIT License – free to use, modify, and distribute.
