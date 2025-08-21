#include "Magician.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) :Player(nickname)
{
    job_name = "������";
    level = 8;
    HP = 100;
    MP = 120;
    power = 20;
    defence = 10;
    accuracy = 75;
    speed = 15;
}

void Magician::attack() {
    cout << "* ������ ����Ѵ�!" << endl;
}