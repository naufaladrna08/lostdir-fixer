cmake_minimum_required(VERSION 3.0.0)
project(lostdir-renamer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include_directories(.)
enable_testing()

add_executable(lostdir-renamer 
  main.cpp
  utils.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
