# PhysicsEngine

A small C++ physics engine example project. The repository contains a simple simulation implemented in `main.cpp` and uses CMake as the build system. The application renders using SDL2 and produces the `physics_engine` executable.

## Requirements

* CMake (>= 3.10)
* A C++ compiler with C++17 support (GCC, Clang, MSVC)
* make / a build tool provided by your system
* SDL2 development libraries (libsdl2-dev on Debian/Ubuntu)

On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install -y build-essential cmake libsdl2-dev
```

On other Linux distros, install the equivalent SDL2 development packages.

## Build (recommended)

A helper script `build.sh` is provided to simplify tasks. It builds the project into the `build/` folder.

Common usages:

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove the build directory
./build.sh --pedantic # Enable extra compiler warnings
./build.sh --install  # Install the built binary (system install)
```

## Build (manual via CMake)

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j$(nproc)
```

Executable will be at `build/physics_engine`.

## Run

From the repository root:

```bash
./build/physics_engine
```

## Project layout

* `CMakeLists.txt` - top-level CMake configuration
* `main.cpp` - example entry point and minimal physics simulation/rendering
* `build.sh` - convenience script
* `build/` - out-of-source build artifacts

## Development notes

* Default C++ standard: C++17
* `ENABLE_PEDANTIC` option toggles extra compiler warnings
* For larger projects, consider `src/`, `include/`, `tests/` and CI/tests

## Contribution

* Open an issue for features or bugs
* Create a branch, add code/tests
* Keep builds out-of-source
* Follow existing CMake conventions

## License

See the `LICENSE` file.

## Contact

Open an issue for help or discussion.
