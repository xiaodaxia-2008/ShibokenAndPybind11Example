cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)
set(CMAKE_BUILD_TYPE
    "Release"
    CACHE STRING "build type, Relase or Debug")

project(EasyWidget)

find_package(pybind11 REQUIRED)
find_package(
  Qt5
  COMPONENTS Widgets
  REQUIRED)
set(CMAKE_AUTOMOC ON)

add_library(EasyWidget)
target_sources(EasyWidget PUBLIC EasyWidget.cpp)
target_link_libraries(EasyWidget PUBLIC Qt5::Widgets)

pybind11_add_module(PyEasyWidget PyEasyWidget.cpp)
target_link_libraries(PyEasyWidget PRIVATE EasyWidget)

add_executable(Example Example.cpp)
target_link_libraries(Example PRIVATE EasyWidget)
