# PhysicsEngine

Small physics engine project. This repository currently contains a single `main.cpp` and a CMake-based build system.

## Requirements

- CMake (>= 3.10)
- A C++ compiler supporting C++17 (GCC, Clang, MSVC)

On Linux you can install the dependencies with your package manager, for example:

# PhysicsEngine

A small C++ physics engine example project. The repository contains a single `main.cpp` and a CMake-based build system that produces a `physics_engine` executable.

## Summary

This project demonstrates a minimal C++ project layout using CMake. It is intended as a starting point for experimenting with physics simulations, adding features, and learning how to organize C++ projects.

## Requirements

- CMake (>= 3.10)
- A C++ compiler with C++17 support (GCC, Clang, MSVC)
- make / a build tool provided by your system

This project uses SDL2 for windowing and rendering (see `main.cpp`). On Debian/Ubuntu install SDL2 development packages:

```bash
sudo apt install -y libsdl2-dev
```

On Debian/Ubuntu the required packages can be installed with:

```bash
sudo apt update
sudo apt install -y build-essential cmake
```

## Build (recommended)

A helper script `build.sh` is provided to simplify common tasks. It will configure and build the project into the `build/` folder.

# PhysicsEngine

A small C++ physics engine example project. The repository contains a simple simulation implemented in `main.cpp` and uses CMake as the build system. The application renders using SDL2 and produces the `physics_engine` executable when built.

## Summary

This project is a minimal starting point for experimenting with physics simulations and C++ project layout using CMake.

## Requirements

- CMake (>= 3.10)
- A C++ compiler with C++17 support (GCC, Clang, MSVC)
- make / a build tool provided by your system
- SDL2 development libraries (libsdl2-dev on Debian/Ubuntu)

On Debian/Ubuntu you can install the required packages with:

```bash
sudo apt update
sudo apt install -y build-essential cmake libsdl2-dev
```

On other Linux distros install the equivalent development packages (e.g. `SDL2-devel` on Fedora/CentOS).

## Build (recommended)

A helper script `build.sh` is provided to simplify common tasks. It configures and builds the project into the `build/` folder.

# PhysicsEngine

A small C++ physics engine example project. The repository contains a simple simulation implemented in `main.cpp` and uses CMake as the build system. The application renders using SDL2 and produces the `physics_engine` executable when built.

## Summary

This project is a minimal starting point for experimenting with physics simulations and C++ project layout using CMake.

## Requirements

- CMake (>= 3.10)
- A C++ compiler with C++17 support (GCC, Clang, MSVC)
- make / a build tool provided by your system
- SDL2 development libraries (libsdl2-dev on Debian/Ubuntu)

On Debian/Ubuntu you can install the required packages with:

```bash
sudo apt update
sudo apt install -y build-essential cmake libsdl2-dev
```

On other Linux distros install the equivalent development packages (e.g. `SDL2-devel` on Fedora/CentOS).

## Build (recommended)

A helper script `build.sh` is provided to simplify common tasks. It configures and builds the project into the `build/` folder.

Common usages:

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove the build directory
./build.sh --pedantic # Enable extra compiler warnings
./build.sh --install  # Install the built binary (system install)
```

## Build (manual via CMake)

If you prefer to use CMake directly:

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j$(nproc)
```

After a successful build the executable will be at `build/physics_engine`.

## Run

From the repository root (example):

```bash
./build/physics_engine
```

If you installed the project with `./build.sh --install`, the binary may be available in the system install prefix.

## Project layout

- `CMakeLists.txt` - top-level CMake configuration
- `main.cpp` - example entry point and minimal physics simulation/rendering (uses SDL2)
- `build.sh` - convenience script to configure/build/clean
- `build/` - out-of-source build artifacts (generated)

## Development notes

- The top-level `CMakeLists.txt` sets the default C++ standard to C++17 and exposes an `ENABLE_PEDANTIC` option to toggle extra warnings.
- For larger work, consider reorganizing into `src/`, `include/`, and `tests/` and adding CI/tests.

## Contribution

Contributions are welcome. Suggested workflow:

- Open an issue describing the feature or bug
- Create a branch, add code and tests
- Keep builds out-of-source (use the `build/` directory)
- Follow the existing CMake conventions

## License

See the `LICENSE` file in the project root for license terms.

## Contact

Open an issue if you need help or want to discuss changes.

- Create a branch, add code and tests
- Keep builds out-of-source (use the `build/` directory)
- Follow the existing CMake conventions

## License

See the `LICENSE` file in the project root for license terms.

## Contact

Open an issue if you need help or want to discuss changes.

A helper script `build.sh` is provided to simplify common tasks. It configures and builds the project into the `build/` folder.

Common usages:

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove the build directory
./build.sh --pedantic # Enable extra compiler warnings
./build.sh --install  # Install the built binary (system install)
```

## Build (manual via CMake)

If you prefer to use CMake directly:

```bash
mkdir -p build
cd build
# PhysicsEngine

A small C++ physics engine example project. The repository contains a simple simulation implemented in `main.cpp` and uses CMake as the build system. The application renders using SDL2 and produces the `physics_engine` executable when built.

## Summary

This project is a minimal starting point for experimenting with physics simulations and C++ project layout using CMake.

## Requirements

- CMake (>= 3.10)
- A C++ compiler with C++17 support (GCC, Clang, MSVC)
- make / a build tool provided by your system
- SDL2 development libraries (libsdl2-dev on Debian/Ubuntu)

On Debian/Ubuntu you can install the required packages with:

```bash
sudo apt update
sudo apt install -y build-essential cmake libsdl2-dev
```

On other Linux distros install the equivalent development packages (e.g. `SDL2-devel` on Fedora/CentOS).

## Build (recommended)

A helper script `build.sh` is provided to simplify common tasks. It configures and builds the project into the `build/` folder.

Common usages:

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove the build directory
./build.sh --pedantic # Enable extra compiler warnings
./build.sh --install  # Install the built binary (system install)
```

## Build (manual via CMake)

If you prefer to use CMake directly:

```bash
mkdir -p build
cd build
# PhysicsEngine

A small C++ physics engine example project. The repository contains a simple simulation implemented in `main.cpp` and uses CMake as the build system. The application renders using SDL2 and produces the `physics_engine` executable when built.

## Summary

This project is a minimal starting point for experimenting with physics simulations and C++ project layout using CMake.

## Requirements

- CMake (>= 3.10)
- A C++ compiler with C++17 support (GCC, Clang, MSVC)
- make / a build tool provided by your system
- SDL2 development libraries (libsdl2-dev on Debian/Ubuntu)

On Debian/Ubuntu you can install the required packages with:

```bash
sudo apt update
sudo apt install -y build-essential cmake libsdl2-dev
```

On other Linux distros install the equivalent development packages (e.g. `SDL2-devel` on Fedora/CentOS).

## Build (recommended)

A helper script `build.sh` is provided to simplify common tasks. It configures and builds the project into the `build/` folder.

Common usages:

```bash
./build.sh            # Configure & build Release
./build.sh --debug    # Configure & build Debug
./build.sh --clean    # Remove the build directory
./build.sh --pedantic # Enable extra compiler warnings
./build.sh --install  # Install the built binary (system install)
```

## Build (manual via CMake)

If you prefer to use CMake directly:

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j$(nproc)
```

After a successful build the executable will be at `build/physics_engine`.

## Run

From the repository root (example):

```bash
./build/physics_engine
```

If you installed the project with `./build.sh --install`, the binary may be available in the system install prefix.

## Project layout

- `CMakeLists.txt` - top-level CMake configuration
- `main.cpp` - example entry point and minimal physics simulation/rendering (uses SDL2)
- `build.sh` - convenience script to configure/build/clean
- `build/` - out-of-source build artifacts (generated)

## Development notes

- The top-level `CMakeLists.txt` sets the default C++ standard to C++17 and exposes an `ENABLE_PEDANTIC` option to toggle extra warnings.
- For larger work, consider reorganizing into `src/`, `include/`, and `tests/` and adding CI/tests.

## Contribution

Contributions are welcome. Suggested workflow:

- Open an issue describing the feature or bug
- Create a branch, add code and tests
- Keep builds out-of-source (use the `build/` directory)
- Follow the existing CMake conventions

## License

See the `LICENSE` file in the project root for license terms.

## Contact

Open an issue if you need help or want to discuss changes.
