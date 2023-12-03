//
// Created by wangkang on 2023/12/3.
//
#include <iostream>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}


int main()
{
    lua_State *L=luaL_newstate();
    luaL_openlibs(L);

    //调用执行lua脚本
    int r= luaL_dofile(L,"scripts/test_1.lua");
    if (r!=LUA_OK)
    {
        std::string err= lua_tostring(L,-1);
        std::cout << err << std::endl;
        return false;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}