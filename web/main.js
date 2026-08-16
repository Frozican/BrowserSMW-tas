// 🧱 WebAssembly-Modul laden
import initWasm from "./wasm-loader.js";

const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");
const WIDTH = 256;
const HEIGHT = 224;

let wasm;
let framebuffer;

// 🚀 Initialisierung
async function start() {
  wasm = await initWasm();

  // Core initialisieren
  wasm.instance.exports.core_init();

  // Hauptloop starten
  requestAnimationFrame(loop);
}

// 🎮 Frame-Schleife
function loop() {
  wasm.instance.exports.core_run_frame();
  const ptr = wasm.instance.exports.core_get_framebuffer();
  framebuffer = new Uint8Array(wasm.instance.exports.memory.buffer, ptr, WIDTH * HEIGHT * 4);

  // Frame auf Canvas zeichnen
  const imageData = new ImageData(new Uint8ClampedArray(framebuffer), WIDTH, HEIGHT);
  ctx.putImageData(imageData, 0, 0);

  requestAnimationFrame(loop);
}

// 🧩 Starten
start();
