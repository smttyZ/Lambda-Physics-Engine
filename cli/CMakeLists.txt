# CLI submodule

add_library(cli STATIC
        src/CLIManager.cpp
)

target_include_directories(cli
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(cli
        PUBLIC kalon
)