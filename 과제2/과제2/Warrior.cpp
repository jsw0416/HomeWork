#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) :Player(nickname)
{
    job_name = "전사";
    level = 10;
    HP = 150;
    MP = 50;
    power = 30;
    defence = 30;
    accuracy = 80;
    speed = 10;
}

void Warrior::attack() {
    cout << "* 장검을 휘두른다!" << endl;
}