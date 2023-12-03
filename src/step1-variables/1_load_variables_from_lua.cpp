//
// Created by wangkang on 2023/12/3.
//
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <cassert>

#include <iostream>

int load_variables_from_lua() {

    sol::state lua;
    lua.open_libraries(sol::lib::base); ///没有这一句，脚本里面的print就不能用了
    lua.script_file("scripts/variables.lua");

    ///================= 基本操作
    bool isfullscreen = lua["config"]["fullscreen"]; // can get nested variables
    sol::table config = lua["config"];

    sol::table resolution = config["resolution"];
    int x = resolution["x"];
    int y = resolution["y"];
    std::cout << "resolution :  x : " << x << ", y : " <<y << std::endl;


    ///================通过valid()函数，来判断这个是否是一个有效的变量
    auto z = resolution["z"];
    if (z.valid())
    {
        std::cout << "z is valid" << std::endl;
    }
    else
    {
        std::cout << "z is invalid" << std::endl;
    }


    ///=================== 可以使用optional来判断类型
    sol::optional<int> is_an_integer = lua["config"]["fullscreen"];
    if (is_an_integer == sol::nullopt) {
        std::cout << "lua[\"config\"][\"fullscreen\"] is not an integer "<< std::endl;
    }

    sol::optional<bool> is_a_boolean = lua["config"]["fullscreen"];
    if (is_a_boolean) {
        std::cout << "lua[\"config\"][\"fullscreen\"] is a boolean "<< std::endl;
    }

    sol::optional<double> does_exist = lua["not_a_variable"];
    if (does_exist == sol::nullopt) {
        std::cout << "lua[\"not_a_variable\"] does not exist "<< std::endl;
    }

    ///=================== 可以使用get_or()函数，来判断这个变量是否存在，如果不存在，就返回一个默认值
    int is_defaulted = lua["config"]["fullscreen"].get_or(24);
    assert(is_defaulted == 24);

    ///下面这一句会报错，因为lua["config"]["fullscreen"]是一个bool类型，而不是int类型
    //int wrong_type_value = lua["config"]["fullscreen"];

    assert(!isfullscreen);
    return 0;
}