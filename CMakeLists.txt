cmake_minimum_required(VERSION 3.3)
project(final-project CXX)
include(.eecs211/cmake/CMakeLists.txt)

set(MODEL_SRC
        src/model.cpp
        src/geometry.cpp
        src/ball.cpp
        src/Controller.cpp
        src/view.cpp
        )

add_program(main
    src/main.cpp
    ${MODEL_SRC})
target_link_libraries(main ge211)

add_test_program(model_test
    test/model_test.cpp
    ${MODEL_SRC})
target_link_libraries(model_test ge211)
