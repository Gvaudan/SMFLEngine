cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(2DGameFramework)

set(BOOST_INCLUDEDIR C:/DEV/boost/include/boost-1_67)
set(BOOST_LIBRARYDIR C:/DEV/boost/lib)

include_directories(${BOOST_INCLUDEDIR})
link_directories(${BOOST_LIBRARYDIR})
include_directories(src/Tools/)
include_directories(src/headers/)
add_library(libthor STATIC IMPORTED)
file(GLOB sources_files
        src/main.cpp
        src/Clock/*.cpp
        src/Context/*.cpp
        src/Context/*.cpp
        src/Debug/*.cpp
        src/Event/*.cpp
        src/Entities/*.cpp
        src/Entities/*/*.cpp
        src/Entities/*/*/*.cpp
        src/Graphic/*.cpp
        src/Input/*.cpp
        src/Physics/*.cpp
        src/Manager/*.cpp
        src/State/*.cpp
        )

add_executable(2DGameFramework ${sources_files} )


target_link_libraries(2DGameFramework libthor)

# Detect and add SFML
message(STATUS "Detect and add SFML")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(SFML_STATIC_LIBRARIES TRUE)

#Find any version 2.X of SFML
#See the FindSFML.cmake_modules file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if (SFML_FOUND)
    message(STATUS "SFML Found")
    include_directories(${SFML_INCLUDE_DIR})
    message(STATUS "linking : ${SFML_LIBRARIES}")
    target_link_libraries(2DGameFramework ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

message(STATUS "Linking Boost and Thor to project")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    file(GLOB boost_libs ${BOOST_LIBRARYDIR}/*-mgw73-mt-d-x64-1_67.a)
    set_property(TARGET libthor PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libthor-s-d.a)

else ()
    file(GLOB boost_libs ${BOOST_LIBRARYDIR}/*-mgw73-mt-x64-1_67.a)
    set_property(TARGET libthor PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libthor-s.a)

endif ()

message(STATUS "Boost libs : ${boost_libs}")
target_link_libraries(2DGameFramework libthor -Wall -lpthread)
target_link_libraries(2DGameFramework ${boost_libs})