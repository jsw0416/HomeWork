#pragma once
#include "player.h"
#include <iostream>
#include <string>

class Thief : public Player
{
public:
    Thief(string nickname);
    ~Thief() override = default;

    void attack() override;
};
