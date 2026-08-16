export default async function initWasm() {
  const response = await fetch("browser_tas.wasm");
  const bytes = await response.arrayBuffer();
  const wasm = await WebAssembly.instantiate(bytes, {});
  return wasm;
}
