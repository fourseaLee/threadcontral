cmake_minimum_required(VERSION 2.8)

project(threadControl)
#set (threadControl_VERSION_MAJOR 1)
#set (threadControl_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_BUILD_TYPE "Debug")


include_directories(./include)

aux_source_directory(./src DIR_SRCS)

set(link_lib  pthread boost_system boost_thread)

add_executable(threadcontrol ${DIR_SRCS})

target_link_libraries(threadcontrol ${link_lib})
        
