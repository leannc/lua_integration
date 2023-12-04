//
// Created by kang on 2023/12/4.
//

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <string>

sol::protected_function_result safe_call_back(lua_State*, sol::protected_function_result pfr)
{
    sol::error err = pfr;
    std::cout << "An error (an expected one) occurred: " << err.what() << std::endl;
    return pfr;
}


int safe_script_usage()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    ///===============默认的方式，这个样子,在程序的最后会报错，最好是不要用这种
    // uses sol::script_default_on_error, which either panics or throws,
    // depending on your configuration and compiler settings
    try {
        ///========错误的文件名
//        auto result1 = lua.safe_script_file("bad file name");

        ///========好的文件名
//        auto result1 = lua.safe_script_file("scripts/test_1.lua");
    }
    catch( const sol::error& e ) {
        std::cout << "an expected error has occurred: " << e.what() << std::endl;
    }


    ///===============使用sol::script_pass_on_error，这个样子不会报错，但是会返回一个错误 👍
    // a custom handler that you write yourself
    // is only called when an error happens with loading or running the script
    auto result2 = lua.safe_script_file("scripts/test_1.lua", [](lua_State*, sol::protected_function_result pfr) {
        // pfr will contain things that went wrong, for either loading or executing the script
        // the user can do whatever they like here, including throw. Otherwise...
        sol::error err = pfr;
        std::cout << "An error (an expected one) occurred: " << err.what() << std::endl;

        // ... they need to return the protected_function_result
        return pfr;
    });

    ///==========直接使用call back函数
    auto result3 = lua.safe_script("bad script", safe_call_back);

    std::cout << std::endl;

    std::cout<<""<<std::endl;

    return 0;
}