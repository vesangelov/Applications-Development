cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

project(hello_world LANGUAGES CXX)

if(UNIX)
#set(SDL2_image_name SDL2_image)
#set(SDL2_ttf_name SDL2_ttf)
#set(SDL2_mixer_name SDL2_mixer)

elseif(WIN32 OR APPLE)
#set(SDL2_image_name SDL2_IMAGE)
#set(SDL2_ttf_name SDL2_TTF)
#set(SDL2_mixer_name SDL2_MIXER)
endif()

#find_package(SDL2 REQUIRED)
#find_package(${SDL2_image_name} REQUIRED)
#find_package(${SDL2_image_name} REQUIRED)
#find_package(${SDL2_mixer_name} REQUIRED)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(hello_world ${_BASE_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_link_libraries(hello_world PUBLIC SDL2 SDL2_image SDL2_ttf SDL2_mixer)

target_include_directories(${PROJECT_NAME} 
                          PRIVATE
                          ${SDL2_INCLUDE_DIR}
                          ${SDL2_IMAGE_INCLUDE_DIR}
                          ${SDL2_TTF_INCLUDE_DIR}
                          ${SDL2_MIXER_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} 
                          PRIVATE
                          ${SDL2_INCLUDE_DIR}
                          ${SDL2_IMAGE_INCLUDE_DIR}
                          ${SDL2_TTF_INCLUDE_DIR}
                          ${SDL2_MIXER_INCLUDE_DIR})