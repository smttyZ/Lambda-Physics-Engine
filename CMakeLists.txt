cmake_minimum_required(VERSION 3.25)
project(LambdaPhysicsEngine VERSION 0.1.0 LANGUAGES CXX)

# Global settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)
option(ENABLE_CLANG_TIDY "Run clang-tidy if available" OFF)
option(BUILD_TESTS "Build tests" ON)

# Common warning flags
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
if (ENABLE_WARNINGS_AS_ERRORS)
    add_compile_options(-Werror)
endif()

# Clang-tidy hook (optional)
if (ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if (CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()

# Subdirectories
add_subdirectory(external/kalon)   # vendored interface lib
add_subdirectory(engine)
add_subdirectory(scenes)
add_subdirectory(cli)

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Top-level executable
add_executable(lambda_physics src/main.cpp)
target_link_libraries(lambda_physics
    PRIVATE engine scenes cli
)

target_include_directories(lambda_physics
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
