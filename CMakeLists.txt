cmake_minimum_required(VERSION 3.25)

project(LambdaPhysicsEngine
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lambda_physics
        src/main.cpp
        physics/include/PhysicsWorld.hpp
        physics/include/scenes/IScene.hpp
        physics/include/scenes/SEmpty.hpp
        physics/include/scenes/Scene.hpp
        physics/include/scenes/SceneFactory.hpp
        physics/src/SceneFactory.cpp
        physics/include/scenes/SCradle.hpp
        physics/src/SCradle.cpp
)

# Disable Kalon tests when building as a dependency
set(KALON_ENABLE_TESTS OFF CACHE BOOL "Disable Kalon tests")

add_subdirectory(external/kalon)
add_subdirectory(cli)

target_link_libraries(lambda_physics
        PUBLIC kalon
        PUBLIC cli
)

target_include_directories(lambda_physics
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

