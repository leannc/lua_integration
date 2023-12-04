//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>
#include <iostream>

struct my_class {
    int a = 0;

    my_class() {};

    my_class(int x) : a(x) {

    }

    int func() {
        ++a; // increment a by 1
        return a;
    }
};


int call_cpp_member_functions_in_lua()
{
    sol::state lua;

    // Here, we are binding the member function and a class instance: it will call the function on
    // the given class instance
    lua.set_function("my_class_func", &my_class::func, my_class());

    // We do not pass a class instance here:
    // the function will need you to pass an instance of "my_class" to it
    // in lua to work, as shown below
    lua.set_function("my_class_func_2", &my_class::func);

    // With a pre-bound instance:
    lua.script(R"(
                first_value = my_class_func()
                second_value = my_class_func()
        )");
    // first_value == 1
    // second_value == 2
    int first_value = lua["first_value"];
    int second_value = lua["second_value"];
    std::cout<<"first_value is "<<first_value<<",second_value is "<<second_value<<std::endl;

    // With no bound instance:
    lua.set("obj", my_class(24));
    // Calls "func" on the class instance
    // referenced by "obj" in Lua
    lua.script(R"(
                third_value = my_class_func_2(obj)
                fourth_value = my_class_func_2(obj)
        )");
    // first_value == 25
    // second_value == 26
    int third_value = lua["third_value"];
    int fourth_value = lua["fourth_value"];
    std::cout<<"third_value is "<<third_value<<",fourth_value is "<<fourth_value<<std::endl;


    ///在lua文件中执行
    lua.open_libraries(sol::lib::base);
    lua.script_file("scripts/call_cpp_member_function_from_lua.lua");

    return 0;
}