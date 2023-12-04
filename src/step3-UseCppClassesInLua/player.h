//
// Created by kang on 2023/12/4.
//

#ifndef LUA_INTEGRATION_PLAYER_H
#define LUA_INTEGRATION_PLAYER_H

#include <iostream>

struct player {
public:
    int bullets;
    int speed;

    player()
        : player(3, 100) {

    }

    player(int ammo)
        : player(ammo, 100) {

    }

    player(int ammo, int hitpoints)
        : bullets(ammo), hp(hitpoints) {

    }

    void boost() {
        speed += 10;
    }

    bool shoot() {
        if (bullets < 1)
            return false;
        --bullets;
        return true;
    }

    void set_hp(int value) {
        hp = value;
    }

    int get_hp() const {
        return hp;
    }

private:
    int hp;
};


#endif //LUA_INTEGRATION_PLAYER_H
