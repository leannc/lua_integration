//
// Created by wangkang on 2023/12/3.
//

#include "UseCases.h"
#include <string>
#include <iostream>

void header(const std::string title)
{
    std::cout<<"####################### "<<title<<" #######################"<<std::endl;
}

#define CALL_USE_CASE(func) \
    header(#func);\
    func();


int main()
{
///============variables============
//    CALL_USE_CASE(load_variables_from_lua);
//    CALL_USE_CASE(write_variables_to_lua);

///============functions============
//    CALL_USE_CASE(call_cpp_functions_in_lua);
//    CALL_USE_CASE(call_cpp_member_functions_in_lua);
//    CALL_USE_CASE(call_cpp_template_functions_in_lua);
//    CALL_USE_CASE(get_a_function_from_lua_in_cpp);
//    CALL_USE_CASE(multy_returns_from_lua_function);
//    CALL_USE_CASE(define_multy_return_functions_to_lua_function_in_cpp);
//    CALL_USE_CASE(return_any_type_to_and_from_lua);

///============classes============
    CALL_USE_CASE(use_cpp_classes_in_lua);


}