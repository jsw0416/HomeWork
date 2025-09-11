#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Inventory.h"

using namespace std;

class Shop
{
public:
	Shop(Player& p);
	~Shop();
	string shopitemname; //������ �̸�

	void buyitem(); //������ ����
	void sellitem(); //������ �Ǹ�
	void displayitem(); //������ ���  
private:
	vector<Item*> ShopList; //���� ������ ���� �迭
	Player& player; // Player Ŭ���������� ����
};