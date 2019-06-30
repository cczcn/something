aux_source_directory(. DIR_SRCS)

add_executable(run ${DIR_SRCS})

find_package (Threads)
#add_executable (run sensorTest.cpp ...)
target_link_libraries (run ${CMAKE_THREAD_LIBS_INIT})

find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
target_link_libraries(run ${Boost_LIBRARIES})


