
cmake_minimum_required (VERSION 3.8)

project ("lightning")

add_executable (lightning "lightning.cpp" "lightning.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lightning PROPERTY CXX_STANDARD 20)
endif()

