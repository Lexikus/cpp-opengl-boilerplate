cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME OpenGL)
set(PROJECT_VERSION 0.0.1)

set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_PATH ${CURRENT_PATH}/src)
set(VENDOR_PATH ${CURRENT_PATH}/vendor)

set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)
if (UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra)
endif (UNIX)

add_executable(${PROJECT_NAME} ${SOURCE_PATH}/main.cpp)

# glfw
# lib requirements for linux: xorg-dev libglu1-mesa-dev
add_subdirectory(${VENDOR_PATH}/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})

# glad
add_subdirectory(${VENDOR_PATH}/glad)
target_link_libraries(${PROJECT_NAME} glad)

# glm
set(GLM_TEST_ENABLE CACHE BOOL OFF)
add_subdirectory(${VENDOR_PATH}/glm)
target_link_libraries(${PROJECT_NAME} glm)