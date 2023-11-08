cmake_minimum_required(VERSION 3.26)
project(SFML_GameEngine)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include")
set(SFML_LIB_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib")

include_directories( ${SFML_INCLUDE_DIR} )
link_directories( ${SFML_LIB_DIR} )

add_executable(SFML_GameEngine main.cpp
        class/GameObject.cpp
        class/GameObject.h
        class/EventManager.cpp
        class/EventManager.h
)

target_link_libraries( ${PROJECT_NAME} sfml-graphics-d sfml-main-d sfml-system-d sfml-window-d )

#Add .dll files in cmake-build-debug folder (sfml-graphics-d-2.dll for example)
