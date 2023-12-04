//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>


int define_multy_return_functions_to_lua_function_in_cpp()
{
    sol::state lua;

    lua["f"] = [](int a, int b, sol::object c) {
        // sol::object can be anything here: just pass it through
        a+=4;
        return std::make_tuple( a, b, c );
    };

    std::tuple<int, int, int> result = lua["f"](1, 2, 3);
    // result == { 5, 2, 3 }
    std::cout<<"result is "<<std::get<0>(result)<<","<<std::get<1>(result)<<","<<std::get<2>(result)<<std::endl;

    std::tuple<int, int, std::string> result2;
    result2 = lua["f"](1, 2, "Arf?");
    // result2 == { 5, 2, "Arf?" }
    std::cout<<"result2 is "<<std::get<0>(result2)<<","<<std::get<1>(result2)<<","<<std::get<2>(result2)<<std::endl;


    int a, b;
    std::string c;
    sol::tie( a, b, c ) = lua["f"](1, 2, "meow");
    // a == 5
    // b == 2
    // c == "meow"
    std::cout<<"a is "<<a<<",b is "<<b<<",c is "<<c<<std::endl;


    return 0;
}