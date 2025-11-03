# Swarm OpenGL Sample

Minimal OpenGL starter that uses CMake and GLFW to open a window and clear the screen. The layout is meant to be a clean base that you can expand with your own rendering code, asset loaders, and build targets.

```
swarm
├── include/
│   └── .gitkeep
├── res/
|   └── shaders/
│       └── simple.frag
│       └── simple.vert
├── src/
│   └── main.cpp
|   .gitignore
├── CMakeLists.txt
└── README.md
```

## Prerequisites

- A C++17 capable compiler.
- CMake 3.15 or newer.
- Python is **not** required because the example sticks to core OpenGL calls.

On Linux, install system OpenGL drivers and build tooling (e.g. `sudo apt install build-essential libgl1-mesa-glx libglu1-mesa libglew-dev libglfw3 libglfw3-dev`).

## Configure & Build

```bash
cd build
cmake ..
make
```

You can then run the sample application:

```bash
./build/swarm
```

The executable copies the `shaders/` directory next to the binary during the build step so you can load them at runtime once you add shader compilation code.

## Next Steps

- Add your own headers in `include/` and source files in `src/`.
- Extend `CMakeLists.txt` to pull in GLAD or another loader if you need modern OpenGL function pointers.
- Implement shader compilation and actual drawing using the provided sample shader files.
