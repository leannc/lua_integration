cmake_minimum_required(VERSION 3.21)
project(lua_integration)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rdparty/lua546)


add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE 3rdparty/lua546/lua-5.4.6/include)
target_link_libraries(${PROJECT_NAME} PRIVATE lua_static)
