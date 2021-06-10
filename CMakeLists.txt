cmake_minimum_required(VERSION 3.6)
project(noble_chat CXX)

configure_file(NobleConfig.h.in NobleConfig.h)

add_executable(noble_chat main.cpp)
target_include_directories(noble_chat
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
        # NobleConfig.h
        "${PROJECT_BINARY_DIR}"
)

add_subdirectory("${PROJECT_SOURCE_DIR}/deps/sleepy-discord")
target_link_libraries(noble_chat sleepy-discord)