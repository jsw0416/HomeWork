#include "Thief.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) :Player(nickname)
{
    job_name = "도적";
    level = 10;
    HP = 120;
    MP = 100;
    power = 30;
    defence = 20;
    accuracy = 90;
    speed = 30;
}

void Thief::attack() {
    cout << "* 단검을 휘두른다!" << endl;
}