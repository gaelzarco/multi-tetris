cmake_minimum_required(VERSION 3.24)
project(game LANGUAGES CXX)

add_executable(game game.cxx)
target_compile_features(game PRIVATE cxx_std_23)
target_compile_options(game PRIVATE -fmodules-ts)

find_package(raylib REQUIRED)

# handle either target name
if(TARGET raylib::raylib)
  set(RAYLIB_TGT raylib::raylib)
else()
  set(RAYLIB_TGT raylib)
endif()

target_link_libraries(game PRIVATE ${RAYLIB_TGT})

# Precompile "print" and "raylib.h" as header units (GCC -fmodules-ts)
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
