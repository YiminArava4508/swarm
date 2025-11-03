# Swarm OpenGL Sample

Minimal OpenGL starter that uses CMake and GLFW to open a window and clear the screen. The layout is meant to be a clean base that you can expand with your own rendering code, asset loaders, and build targets.

```
swarm
├── CMakeLists.txt
├── cmake/
│   └── Dependencies.cmake
├── include/
│   └── .gitkeep
├── shaders/
│   ├── simple.frag
│   └── simple.vert
├── src/
│   └── main.cpp
└── README.md
```

## Prerequisites

- A C++17 capable compiler (MSVC 2019+, Clang, or GCC).
- CMake 3.16 or newer.
- Python is **not** required because the example sticks to core OpenGL calls.

On Linux, install system OpenGL drivers and build tooling (e.g. `build-essential mesa-utils libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev`). On macOS the Xcode command-line tools are sufficient. On Windows, use MSVC via Visual Studio or clang-cl.

## Configure & Build

```bash
cmake -S . -B build
cmake --build build
```

You can then run the sample application:

```bash
./build/swarm_app    # On Windows use build/Debug/swarm_app.exe
```

The executable copies the `shaders/` directory next to the binary during the build step so you can load them at runtime once you add shader compilation code.

## Next Steps

- Add your own headers in `include/` and source files in `src/`.
- Extend `CMakeLists.txt` to pull in GLAD or another loader if you need modern OpenGL function pointers.
- Implement shader compilation and actual drawing using the provided sample shader files.
