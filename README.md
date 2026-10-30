# Render-Engine-C

A highly optimized, lightweight C11 rendering and image processing engine. Designed strictly for raw performance, zero-cost abstractions, and robust memory safety.

## Technical Architecture
- **SIMD-Ready Memory Architecture**: Pixel buffers are dynamically allocated with 32-byte alignment strides to support seamless AVX/SSE vectorization out of the box.
- **Zero External Dependencies**: Core processing algorithms rely exclusively on standard C libraries (`stdint.h`, `stddef.h`), ensuring absolute portability across bare-metal and POSIX systems.
- **Integer Arithmetic Optimizations**: Avoids costly floating-point operations in core CPU compute shaders (e.g., utilizing bitwise shifts for luminosity and color-space conversions).

## Build Instructions

### Using CMake (Recommended)
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./Render-Engine-C
