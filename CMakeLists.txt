cmake_minimum_required(VERSION 3.14)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

set( EXECUTABLE_OUTPUT_PATH "EXE" )

#add_executable(main Floyd_Warshall.cpp)
#add_executable(main Dijkstra.cpp )

#set( BOOST_ROOT "c:/local/boost_1_71_0" )
##set( BOOST_INCLUDEDIR "c:/local/boost_1_71_0/boost")
##set( BOOST_LIBRARYDIR "c:/local/boost_1_71_0/lib64-msvc-10.0")
#find_package(Boost COMPONENTS REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#
#add_library(boost_geometry INTERFACE)
#add_library(Boost::geometry ALIAS boost_geometry)
#target_include_directories(boost_geometry INTERFACE include)
#
#
#add_library(boost_algorithm INTERFACE)
#add_library(Boost::algorithm ALIAS boost_algorithm)
#target_include_directories(boost_algorithm INTERFACE include)
#
#
#add_library(boost_graph INTERFACE)
#add_library(Boost::graph ALIAS boost_graph)
#target_include_directories(boost_graph INTERFACE include)


#target_link_libraries(boost_geometry
#        INTERFACE
#        Boost::assert
#        Boost::config
#        Boost::core
#        Boost::static_assert
#        Boost::throw_exception
#        )


#simple_list
#add_executable( main P2/NodeList_Simple/simple_list.cpp P2/NodeList_Simple/simple_list.h )

#json reader
#add_executable( main "Projects/JSON/test.cpp" "Projects/JSON/json.h" "Projects/JSON/json_except.h" )

#mqueue
#add_executable( main "P2/Mqueue/mqueue.h" "P2/Mqueue/queuetest.cpp" )

#mstack
#add_executable( main "P2/Mqueue/mstack.h" "P2/Mqueue/mstack_test.cpp" )

#add_executable( main main.cpp "Math/Binary Exp.h")

#add_executable( problems "Problems/COJ/3095.cpp" Math/Matrix.h )

#add_executable( main "main.cpp" "Math/Matrix Power.h"

add_executable( main main.cpp )
