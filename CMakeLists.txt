cmake_minimum_required(VERSION 3.14)
project(pingPong)
set(CMAKE_CXX_FLAGS "-g")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_subdirectory(src)
file(COPY Textures/ DESTINATION ${CMAKE_BINARY_DIR})

# file(COPY ${CMAKE_BINARY_DIR}/src/pingPong DESTINATION ${CMAKE_BINARY_DIR}/)
set_target_properties(pingPong PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)