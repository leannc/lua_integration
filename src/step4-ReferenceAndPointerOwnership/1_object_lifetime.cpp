//
// Created by kang on 2023/12/4.
//

#include <sol/sol.hpp>
#include <string>

int object_lifetime()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.script(R"(
	obj = "please don't let me die";
	)");

    ///sol::object这个对象，可以把lua里面的变量，保存到c++里面，一直保存，直到c++里面的这个对象被销毁。lua里面销毁也不会受影响。
    sol::object keep_alive = lua["obj"];
    lua.script(R"(
	obj = nil;
	function say(msg)
		print(msg)
	end
	)");

    lua.collect_garbage();

    lua["say"](lua["obj"]);
    std::cout<<"===================="<<std::endl;
    // still accessible here and still alive in Lua
    // even though the name was cleared
    std::string message = keep_alive.as<std::string>();
    std::cout << message << std::endl;

    // Can be pushed back into Lua as an argument
    // or set to a new name,
    // whatever you like!
    lua["say"](keep_alive);

    return 0;
}