cmake_minimum_required(VERSION 3.17)
project(benchmark-suite)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp ReusablePool.h btest.h rss.h)

if (MINGW)
    target_link_libraries(${PROJECT_NAME} psapi)
endif ()