//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>


int multy_returns_from_lua_function()
{
    sol::state lua;

    lua.script("function f (a, b, c) return a+5, b, c end");

    std::tuple<int, int, int> result;
    result = lua["f"](1, 2, 3);
    // result == { 6, 2, 3 }
    std::cout<<"result is "<<std::get<0>(result)<<","<<std::get<1>(result)<<","<<std::get<2>(result)<<std::endl;


    int a, b;
    std::string c;
    sol::tie( a, b, c ) = lua["f"](1, 2, "bark");
    // a == 6
    // b == 2
    // c == "bark"
    std::cout<<"a is "<<a<<",b is "<<b<<",c is "<<c<<std::endl;

    return 0;
}