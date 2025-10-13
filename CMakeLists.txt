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

target_include_directories(physics_engine PRIVATE ${PROJECT_SOURCE_DIR})

install(TARGETS physics_engine
  RUNTIME DESTINATION bin
)

message(STATUS "Configured ${PROJECT_NAME} v${PROJECT_VERSION}")
