//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>


int get_a_function_from_lua_in_cpp()
{
    sol::state lua;

    lua.script(R"(
                function f (a)
                        return a + 5
                end
        )");

    // Get and immediately call
    int x = lua["f"](30);
    // x == 35
    std::cout<<"x is "<<x<<std::endl;

    // Store it into a variable first, then call
    sol::function f = lua["f"];
    int y = f(20);
    // y == 25
    std::cout<<"y is "<<y<<std::endl;

    ///===================== 在lua文件中执行
    lua.open_libraries(sol::lib::base);
    lua.script_file("scripts/get_a_function_from_lua_in_cpp.lua");

    sol::function f1 = lua["func_in_lua_1"];
    int z = f1(20);
    // z == 25
    std::cout<<"z is "<<z<<std::endl;

    return 0;
}