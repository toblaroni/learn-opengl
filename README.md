
# OpenGL Test

A small C++ project for experimenting with OpenGL on macOS using GLFW and CMake.

## Requirements

* macOS
* C++17 compiler
* CMake
* GLFW

Install dependencies with Homebrew:

```bash
brew install cmake glfw
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/opengl_test
```

## Purpose

This project is a starting point for revising:

* OpenGL
* GLSL shaders
* Vertex buffers
* 3D transformations
* Cameras and projection
* Basic graphics programming
