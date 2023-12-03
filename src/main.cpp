//
// Created by wangkang on 2023/12/3.
//
#include <iostream>

#include <sol/sol.hpp>
#include <cassert>

int main()
{
    sol::state lua;
    int x = 0;
    lua.set_function("beep", [&x]{ ++x; });
    lua.script("beep()");
    assert(x == 1);


    lua.open_libraries(sol::lib::base);

    lua.script("print('bark bark bark!')");
    return 0;
}