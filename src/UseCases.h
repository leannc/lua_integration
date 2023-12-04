//
// Created by wangkang on 2023/12/3.
//

#pragma once

int load_variables_from_lua();
int write_variables_to_lua();
int call_cpp_functions_in_lua();
int call_cpp_member_functions_in_lua();
int call_cpp_template_functions_in_lua();
int get_a_function_from_lua_in_cpp();
int multy_returns_from_lua_function();
int define_multy_return_functions_to_lua_function_in_cpp();
int return_any_type_to_and_from_lua();