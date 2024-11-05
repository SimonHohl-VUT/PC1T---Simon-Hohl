
cmake_minimum_required (VERSION 3.8)

project ("FunExt")

add_executable (FunExt "FunExt.cpp" "FunExt.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FunExt PROPERTY CXX_STANDARD 20)
endif()

