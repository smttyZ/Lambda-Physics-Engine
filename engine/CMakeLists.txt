add_library(engine STATIC
    src/PhysicsWorld.cpp
)

target_include_directories(engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(engine PUBLIC cxx_std_23)
