cmake_minimum_required(VERSION 3.1)
project(napi-transformstream)

set(CMAKE_CXX_STANDARD 11)

# Build a shared library named after the project from the files in `src/`
file(GLOB SOURCE_FILES "src/*.cc")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Include N-API wrappers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC} PRIVATE "${CMAKE_SOURCE_DIR}/node_modules/node-addon-api")

# Essential library files to link to a node addon
# You should add this line in every CMake.js based project
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} )
