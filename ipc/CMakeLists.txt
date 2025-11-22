add_library(ipc STATIC)

target_include_directories(ipc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ipc
    PUBLIC engine scenes
)

target_compile_features(ipc PUBLIC cxx_std_23)
