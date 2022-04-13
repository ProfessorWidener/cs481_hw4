cmake_minimum_required( VERSION 3.0 )
project( hw4 )

list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )

enable_language( CXX )
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wredundant-decls -Wcast-align -Wshadow" )

enable_testing()

set( hw4_INCDIR "${CMAKE_CURRENT_SOURCE_DIR}/.." )
include_directories( "external" )

#/////////////////////////// star information of google test ///////////////////////////////
set(GOOGLETEST_ROOT external/googletest CACHE STRING "Google Test source root")
include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )
set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )
foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()
add_library(googletest STATIC ${GOOGLETEST_SOURCES})
target_link_libraries(googletest pthread)
#///////////////////////////// end information of google test //////////////////////////////

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(pnc_SOURCES
  buffer.hpp
  buffer.cpp
  producer_consumer.hpp
  )

set(phil_SOURCES
  philosopher.hpp
  philosopher.cpp
  )

add_library( hw4_cond STATIC ${pnc_SOURCES} condition_var.cpp )
target_link_libraries( hw4_cond pthread )

add_library( hw4_sem STATIC ${pnc_SOURCES} semaphore.cpp )
target_link_libraries( hw4_sem pthread )

add_library( hw4_circ STATIC ${phil_SOURCES} circular.cpp )
target_link_libraries( hw4_circ pthread )

add_library( hw4_hold STATIC ${phil_SOURCES} hold_and_wait.cpp )
target_link_libraries( hw4_hold pthread )

add_subdirectory( tests )



