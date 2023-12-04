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
//    CALL_USE_CASE(load_variables_from_lua);
//    CALL_USE_CASE(write_variables_to_lua);

//    CALL_USE_CASE(call_cpp_functions_in_lua);
    CALL_USE_CASE(call_cpp_member_functions_in_lua);
}