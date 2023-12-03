cmake_minimum_required(VERSION 3.21)
project(lua_integration)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rdparty/lua546)


add_executable(${PROJECT_NAME} src/main.cpp
        src/UseCases.h
        src/step1-variables/1_load_variables_from_lua.cpp
        src/scripts/variables.lua
        src/step1-variables/2_write_variables_to_lua.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        3rdparty/lua546/lua-5.4.6/include
        3rdparty/sol/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE lua_static)
