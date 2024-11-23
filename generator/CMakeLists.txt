cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
project(generator)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE utils)

add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "0" > ${CMAKE_BINARY_DIR}/.matrixID
    COMMENT "Creating .matrixID file with value 0"
)