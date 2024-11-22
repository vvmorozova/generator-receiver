cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
project(receiver)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

find_package (SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIRS})
target_link_libraries (${PROJECT_NAME} ${SQLITE3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC sqlite3)

target_link_libraries(${PROJECT_NAME} PRIVATE utils)
