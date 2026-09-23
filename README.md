# Render-Engine-C ⚙️

> A high-performance, dependency-free image processing engine built from scratch in pure C.

**Render-Engine-C** is a CLI-based tool designed for fast algorithmic pixel manipulation and strict memory management. By bypassing heavy modern frameworks, this project focuses on raw computational speed, direct memory access via pointers, and efficient CPU-level image transformations.

##  Core Objectives
* **Zero Bloat:** Built entirely in standard C using minimal external headers (e.g., `stb_image` for I/O) to maintain total control over execution logic.
* **Memory Safety:** Strict allocation and deallocation protocols (`malloc`/`free`) rigorously tested against memory leaks and segmentation faults.
* **Algorithmic Manipulation:** From simple pixel-by-pixel color conversions to complex mathematical convolution matrices (blur, edge detection).
* **CLI-First Architecture:** A robust command-line interface parsing standard POSIX arguments for seamless integration into larger automated pipelines, sub-processes, or web backends.

##  Architecture Overview
The engine is decoupled into three primary subsystems:
1. **CLI Parser:** Securely handles `argc`/`argv` inputs, sanitizes arguments, handles missing flags, and manages file I/O operations gracefully.
2. **Memory Manager:** Dynamically allocates the heap for 1D pixel buffers representing 2D image matrices ($W \times H \times C$).
3. **Render Core:** The algorithmic heart where mathematical kernels (e.g., Sobel, Gaussian) are applied directly to the `unsigned char` buffers.

##  Getting Started

### Prerequisites
* GCC compiler
* Standard C libraries

### Compilation
Clone the repository and compile the engine using strict flags to ensure memory-safe execution:
```bash
git clone [https://github.com/julesdevs/Render-Engine-C.git](https://github.com/julesdevs/Render-Engine-C.git)
cd Render-Engine-C
gcc -Wall -Wextra -Werror src/main.c -o render-engine
