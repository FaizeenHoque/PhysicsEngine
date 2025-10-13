#!/usr/bin/env bash
set -euo pipefail

# Simple build helper for the PhysicsEngine project
# Usage:
#   ./build.sh            # configure & build Release
#   ./build.sh --debug    # configure & build Debug
#   ./build.sh --clean    # remove build directory
#   ./build.sh --install  # install after build (may require sudo)
#   ./build.sh --pedantic # enable extra warnings

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

BUILD_TYPE=Release
DO_CLEAN=0
DO_INSTALL=0
PEDANTIC=OFF

print_help() {
  cat <<EOF
Usage: $0 [options]

Options:
  --debug        Build with Debug configuration
  --release      Build with Release configuration (default)
  --clean        Remove the build directory
  --install      Run 'cmake --install' after building
  --pedantic     Enable extra compiler warnings
  -h, --help     Show this help message
EOF
}

while [[ ${#} -gt 0 ]]; do
  case "$1" in
    --debug)
      BUILD_TYPE=Debug; shift;;
    --release)
      BUILD_TYPE=Release; shift;;
    --clean)
      DO_CLEAN=1; shift;;
    --install)
      DO_INSTALL=1; shift;;
    --pedantic)
      PEDANTIC=ON; shift;;
    -h|--help)
      print_help; exit 0;;
    *)
      echo "Unknown option: $1" >&2; print_help; exit 1;;
  esac
done

if [[ $DO_CLEAN -eq 1 ]]; then
  echo "Removing build directory: $BUILD_DIR"
  rm -rf "$BUILD_DIR"
  exit 0
fi

mkdir -p "$BUILD_DIR"
pushd "$BUILD_DIR" >/dev/null

CMFLAGS=( -DCMAKE_BUILD_TYPE=${BUILD_TYPE} )
if [[ "${PEDANTIC}" == "ON" ]]; then
  CMFLAGS+=( -DENABLE_PEDANTIC=ON )
fi

echo "Configuring (build type=${BUILD_TYPE})..."
cmake .. "${CMFLAGS[@]}"

echo "Building..."
cmake --build . -- -j"$(nproc)"

if [[ $DO_INSTALL -eq 1 ]]; then
  echo "Installing..."
  cmake --install .
fi

popd >/dev/null

echo "Build complete. Executable is at: $BUILD_DIR/physics_engine"
