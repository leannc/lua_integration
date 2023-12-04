//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>

template <typename A, typename B>
auto my_add( A a, B b ) {
    return a + b;
}

int call_cpp_template_functions_in_lua()
{
    sol::state lua;

    // adds 2 integers
    lua["my_int_add"] = my_add<int, int>;

    // concatenates 2 strings
    lua["my_string_combine"] = my_add<std::string, std::string>;

    lua.script("my_num = my_int_add(1, 2)");
    int my_num = lua["my_num"];
    // my_num == 3

    lua.script("my_str = my_string_combine('bark bark', ' woof woof')");
    std::string my_str = lua["my_str"];
    // my_str == "bark bark woof woof"

    /// ===================== 重载函数
    lua["my_combine"] = sol::overload( my_add<int, int>, my_add<std::string, std::string> );

    lua.script("my_num = my_combine(1, 2)");
    lua.script("my_str = my_combine('bark bark', ' woof woof')");
    int my_num2 = lua["my_num"];
    std::string my_str2 = lua["my_str"];

    // my_num2 == 3
    // my_str2 == "bark bark woof woof"
    std::cout<<"my_num2 is "<<my_num2<<",my_str2 is "<<my_str2<<std::endl<<std::endl;

    ///===================== 在lua文件中执行
    lua.open_libraries(sol::lib::base);
    lua.script_file("scripts/call_cpp_template_function_from_lua.lua");

    return 0;
}