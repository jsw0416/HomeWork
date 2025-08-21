#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) :Player(nickname)
{
    job_name = "±Ã¼ö";
    level = 10;
    HP = 120;
    MP = 100;
    power = 25;
    defence = 20;
    accuracy = 90;
    speed = 25;
}

void Archer::attack() {
    cout << "* È­»ìÀ» ½ð´Ù!" << endl;
}