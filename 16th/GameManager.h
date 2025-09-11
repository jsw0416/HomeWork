#pragma once
#include <memory>
#include "Shop.h"
#include "Monster.h"


class GameManager
{
public:
	GameManager(std::string nickname = "Default")
		: player(nickname), shop(player) {}
	~GameManager() {}
	
	string nickname;
	void GameStart();

	void selectAction();

	void visitShop();

	void displayInventory();

private:
	
	Player player;
	Shop shop;
};
