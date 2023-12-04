//
// Created by wangkang on 2023/12/3.
//

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <iostream>

int write_variables_to_lua()
{
    sol::state lua;

    // open those basic lua libraries
    // again, for print() and other basic utilities
    lua.open_libraries(sol::lib::base);

    // value in the global table
    lua["bark"] = 50;

    // a table being created in the global table
    lua["some_table"] = lua.create_table_with(
            "key0", 24,
            "key1", 25,
            lua["bark"], "the key is 50 and this string is its value!");

    // Run a plain ol' string of lua code
    // Note you can interact with things set through sol in C++ with lua!
    // Using a "Raw String Literal" to have multi-line goodness:
    // http://en.cppreference.com/w/cpp/language/string_literal
    lua.script(R"(

	print(some_table[50])
	print(some_table["key0"])
	print(some_table["key1"])

	-- a lua comment: access a global in a lua script with the _G table
	print(_G["bark"])

	)");


    ///=================对不存在的元素取值
    auto barkkey = lua["bark2"];
    if (barkkey.valid() == false) {
        std::cout << "barkkey does not exist" << std::endl;
    }

    barkkey = 50;
    if (barkkey.valid()) {
        // Branch taken: value exists!
        std::cout << "Bark Bjork Wan Wan Wan" << std::endl;
    }


    ///=================通过sol::lua_nil，来删除某一些值
    lua["bark3"] = 50;
    sol::optional<int> x = lua["bark3"];
    // x will have a value
    if (x) {
        std::cout << "the value of x is : "<<x.value() << std::endl;
    }
    else {
        return -1;
    }



    ///=============================删除bark3
    lua["bark3"] = sol::lua_nil;
    sol::optional<int> y = lua["bark3"];
    // y will not have a value
    if (y) {
        std::cout << "bark3 still alive" << std::endl;
    }
    else {
        std::cout << "y has no value, as expected" << std::endl;
    }


    return 0;
}