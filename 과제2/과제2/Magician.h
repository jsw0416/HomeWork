#pragma once
#include "player.h"
#include <iostream>
#include <string>

class Magician : public Player
{
public:
    Magician(string nickname);
    ~Magician() override = default;

    void attack() override;
};