# Project Architecture

## Overview
BrowserSMW-TAS is a modular web-based tool for creating and editing tool-assisted speedruns (TAS) of Super Mario World.

## Modules
- **Core** – SNES emulator compiled to WebAssembly.
- **TAS Engine** – Handles frame advance, savestates, and input injection.
- **Scripts** – Custom `.mwtas` scripting system with Lua runtime.
- **Movies** – Import/export of `.smv`, `.lsmv`, and `.mwtas` files.
- **UI** – Piano Roll, overlay, and script editor.
- **Web** – Entry point and glue code for browser execution.

## Goals
- Full TAS functionality in browser and mobile.
- Compatibility with existing SMW TAS formats.
- Extensible scripting and visualization system.
