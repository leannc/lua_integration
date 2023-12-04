cmake_minimum_required(VERSION 3.21)
project(lua_integration)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rdparty/lua546)


add_executable(${PROJECT_NAME} src/main.cpp
        src/UseCases.h
        src/step1-variables/1_load_variables_from_lua.cpp
        src/scripts/variables.lua
        src/step1-variables/2_write_variables_to_lua.cpp
        src/step2-functions/1_call_cpp_functions_in_lua.cpp
        src/step2-functions/2_call_cpp_member_functions_in_lua.cpp
        src/step2-functions/3_call_cpp_template_functions_in_lua.cpp
        src/step2-functions/4_get_a_function_from_lua_in_cpp.cpp
        src/step2-functions/5_multy_returns_from_lua_function.cpp
        src/step2-functions/6_define_multy_return_functions_to_lua_function_in_cpp.cpp
        src/step2-functions/7_return_any_type_to_and_from_lua.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        3rdparty/lua546/lua-5.4.6/include
        3rdparty/sol/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE lua_static)

#####################文件夹自动拷贝###########################
# 设置源文件目录
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/scripts)

# 设置目标目录
set(BINARY_DIR ${CMAKE_BINARY_DIR}/scripts)

# 拷贝整个文件夹
file(COPY ${SOURCE_DIR}/ DESTINATION ${BINARY_DIR})

# 添加自定义目标，用于每次构建时拷贝文件夹
add_custom_target(ScriptFolder ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SOURCE_DIR}
        ${BINARY_DIR}
        DEPENDS ${${PROJECT_NAME}}
        COMMENT "Copying config folder to binary directory"
)
# 将自定义目标添加到默认构建目标的依赖项中
add_dependencies(${PROJECT_NAME} ScriptFolder)
