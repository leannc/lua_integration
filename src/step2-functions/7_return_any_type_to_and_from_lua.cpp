//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>

sol::object fancy_func (sol::object a, sol::object b, sol::this_state s) {
    sol::state_view lua(s);
    if (a.is<int>() && b.is<int>()) {
        return sol::make_object(lua, a.as<int>() + b.as<int>());
    }
    else if (a.is<bool>()) {
        bool do_triple = a.as<bool>();
        return sol::make_object(lua, b.as<double>() * ( do_triple ? 3 : 1 ) );
    }
    return sol::make_object(lua, sol::lua_nil);
}

int return_any_type_to_and_from_lua()
{
    sol::state lua;

    lua["f"] = fancy_func;

    int result = lua["f"](1, 2);
    // result == 3

    double result2 = lua["f"](false, 2.5);
    // result2 == 2.5

    // call in Lua, get result
    lua.script("result3 = f(true, 5.5)");
    double result3 = lua["result3"];
    // result3 == 16.5

    std::cout<<"result is "<<result<<",result2 is "<<result2<<",result3 is "<<result3<<std::endl;

    return 0;
}