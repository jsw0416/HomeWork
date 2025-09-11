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
	string shopitemname; //아이템 이름

	void buyitem(); //아이템 구매
	void sellitem(); //아이템 판매
	void displayitem(); //아이템 출력  
private:
	vector<Item*> ShopList; //상점 아이템 동적 배열
	Player& player; // Player 클래스에대한 참조
};