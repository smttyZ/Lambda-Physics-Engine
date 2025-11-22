add_library(scenes STATIC
    src/SceneFactory.cpp
)

target_include_directories(scenes
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(scenes
    PUBLIC engine
)

target_compile_features(scenes PUBLIC cxx_std_23)
