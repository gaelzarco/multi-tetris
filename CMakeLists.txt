cmake_minimum_required(VERSION 3.24)
project(game LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(game game.cxx)
target_compile_features(game PRIVATE cxx_std_23)
target_compile_options(game PRIVATE -fmodules-ts)
target_link_libraries(game PRIVATE raylib)

add_custom_target(modules
  COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/gcm.cache"
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -fmodules-ts -x c++-system-header print
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -fmodules-ts -x c++-system-header raylib.h
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
  VERBATIM
)

add_dependencies(game modules)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES
  "${CMAKE_BINARY_DIR}/gcm.cache"
)
