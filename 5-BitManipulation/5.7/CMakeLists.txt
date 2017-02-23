cmake_minimum_required (VERSION 2.6)
project (main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_BUILD_TYPE Debug)

include_directories(${main_SOURCE_DIR})

file(GLOB main_SRC
    "*.h"
    "*.cpp"
)

add_executable(main ${main_SRC})

TARGET_LINK_LIBRARIES(main PUBLIC pthread )

