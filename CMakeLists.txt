cmake_minimum_required(VERSION 3.10)

project(PhysicsEngine VERSION 0.1 LANGUAGES CXX)

# Allow the user to override the C++ standard; default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# Default to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Add a simple option to enable extra warnings
option(ENABLE_PEDANTIC "Enable pedantic warnings and extra warnings" OFF)
if(ENABLE_PEDANTIC)
  if(MSVC)
    add_compile_options(/W4 /permissive-)
  else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)
  endif()
endif()

set(SOURCES
  ${PROJECT_SOURCE_DIR}/main.cpp
)

add_executable(physics_engine ${SOURCES})

# Ensure target uses the requested C++ standard
target_compile_features(physics_engine PRIVATE cxx_std_17)
target_include_directories(physics_engine PRIVATE ${PROJECT_SOURCE_DIR})

# Try to find SDL2 via CMake package first, then fall back to pkg-config
find_package(SDL2 REQUIRED)
if(TARGET SDL2::SDL2)
  target_link_libraries(physics_engine PRIVATE SDL2::SDL2)
  target_include_directories(physics_engine PRIVATE ${SDL2_INCLUDE_DIRS})
else()
  # Fallback: try pkg-config
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(SDL2_PKG REQUIRED sdl2)
  if(SDL2_PKG_FOUND)
    target_include_directories(physics_engine PRIVATE ${SDL2_PKG_INCLUDE_DIRS})
    target_link_libraries(physics_engine PRIVATE ${SDL2_PKG_LIBRARIES})
    target_compile_options(physics_engine PRIVATE ${SDL2_PKG_CFLAGS_OTHER})
  else()
    message(FATAL_ERROR "SDL2 not found. Install SDL2 development headers or provide SDL2 package for CMake.")
  endif()
endif()

install(TARGETS physics_engine
  RUNTIME DESTINATION bin
)

message(STATUS "Configured ${PROJECT_NAME} v${PROJECT_VERSION}")
