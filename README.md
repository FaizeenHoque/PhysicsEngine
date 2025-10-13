# PhysicsEngine

Small physics engine project. This repository currently contains a single `main.cpp` and a CMake-based build system.

## Requirements

- CMake (>= 3.10)
- A C++ compiler supporting C++17 (GCC, Clang, MSVC)

On Linux you can install the dependencies with your package manager, for example:

```bash
# Debian/Ubuntu
sudo apt update && sudo apt install -y build-essential cmake

# Fedora
sudo dnf install -y @development-tools cmake
```

## Quick build

There are two simple ways to build the project.

1) Use the included helper script (recommended):

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove build directory
./build.sh --pedantic # Enable extra warnings
./build.sh --install  # Install the built binary
```

2) Use CMake directly:

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j$(nproc)
```

The resulting executable will be at `build/physics_engine`.

## Notes

- The top-level `CMakeLists.txt` sets the default C++ standard to C++17 and provides an `ENABLE_PEDANTIC` option to enable extra compiler warnings.
- The `build.sh` script is a convenience wrapper that supports cleaning, different build types, and optional installation.

## Next steps (suggestions)

- Add unit tests and enable `ctest`/`CTest` integration
- Add a CI workflow (GitHub Actions) to build on push and PRs
- Add additional source files and a proper project layout (src/, include/, tests/)

If you want, I can add any of the suggested next steps.
