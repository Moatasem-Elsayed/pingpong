set(FILES
    main.cpp
    paddle.cpp
    ball.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)
