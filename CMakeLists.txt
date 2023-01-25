cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_DIR} cmake_helpers/helpers.cmake)

project(hello_world)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

add_executable(${PROJECT_NAME} ${_BASE_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
#set (CMAKE_CXX_STANDARD 17)
#enable_target_warnings(${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall -Wextra -Wpedantic
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})