# Auto generated by Nixsm
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.9)

project(threadedWordFisher)

if(CMAKE_COMPILER_IS_GNUCXX OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -fvisibility=hidden")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
file(GLOB_RECURSE includes ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME} ${sources} ${includes})
target_link_libraries(${PROJECT_NAME} "pthread")
