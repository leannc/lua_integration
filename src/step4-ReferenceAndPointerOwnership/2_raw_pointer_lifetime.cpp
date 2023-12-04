//
// Created by kang on 2023/12/4.
//

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <string>

struct my_type {
    void stuff() {
    }
};

int raw_pointer_lifetime()
{
    sol::state lua;

    ///=====================错误的使用方式
    // AAAHHH BAD
    // dangling pointer!
    lua["my_func"] = []() -> my_type* { return new my_type(); };

    // AAAHHH!
    lua.set("something", new my_type());

    // AAAAAAHHH!!!
    lua["something_else"] = new my_type();


    ///=====================正确的使用方式
    // :ok:
    lua["my_func0"] = []() -> std::unique_ptr<my_type> { return std::make_unique<my_type>(); };

    // :ok:
    lua["my_func1"] = []() -> std::shared_ptr<my_type> { return std::make_shared<my_type>(); };

    // :ok:
    lua["my_func2"] = []() -> my_type { return my_type(); };

    // :ok:
    lua.set("something", std::unique_ptr<my_type>(new my_type()));

    std::shared_ptr<my_type> my_shared = std::make_shared<my_type>();
    // :ok:
    lua.set("something_else", my_shared);

    // :ok:
    auto my_unique = std::make_unique<my_type>();
    lua["other_thing"] = std::move(my_unique);

    return 0;
}