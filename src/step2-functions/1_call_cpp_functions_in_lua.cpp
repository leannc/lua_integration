//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>

std::string my_function( int a, std::string b ) {
    // Create a string with the letter 'D' "a" times,
    // append it to 'b'
    std::string r= b + std::string( "D");
    std::cout<<"r is "<<r<<std::endl;
    return r;
}



int call_cpp_functions_in_lua()
{
    sol::state lua;

    lua["my_func"] = my_function; // way 1
    lua.set("my_func", my_function); // way 2
    lua.set_function("my_func", my_function); // way 3

    // This function is now accessible as 'my_func' in
    // lua scripts / code run on this state:
    lua.script("some_str = my_func(1, 'Da')");

    // Read out the global variable we stored in 'some_str' in the
    // quick lua code we just executed
    std::string some_str = lua["some_str"];
    // some_str == "DaD"

    std::cout<<"some_str is "<<some_str<<std::endl;

    ///让lua文件里面具有这个函数，并执行
    lua.open_libraries(sol::lib::base);
    lua.script_file("scripts/call_cpp_function_from_lua.lua");

    return 0;
}