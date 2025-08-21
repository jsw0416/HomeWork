#pragma once
#include "player.h"
#include <iostream>
#include <string>

class Warrior : public Player
{
public:
    Warrior(string nickname);
    ~Warrior() override = default;

    void attack() override;
};
