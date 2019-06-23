cmake_minimum_required (VERSION 3.5.1)

project (something)

INCLUDE_DIRECTORIES(
    include
)

SET(ALL_SRC
${DIR_SRCS}
)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
