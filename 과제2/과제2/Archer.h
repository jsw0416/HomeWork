#pragma once
#include "player.h"
#include <iostream>
#include <string>

class Archer : public Player
{
public:
    Archer(string nickname);
    ~Archer() override = default;

    void attack() override;
};
