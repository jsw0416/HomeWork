#pragma once
#include <iostream>
#include <vector>
#include <string>

class Item; // ���漱��

class Player
{
public: // ����Լ�
	
	Player(std::string name);// ������

	~Player() {}  // �Ҹ���

	//getter
	int getAttack() { return attack; } // ����
	int getGold() {	return gold;} //���
	int getHealth() { return health; } //ü��
	int getMaxHealth() { return MaxHealth; }
	int getExperience() { return experience; } // ����ġ
	std::string getCharacterName() { return name; } // ĳ���� �г��� 
	std::vector<Item*>& Getinv() { return inv; } // �κ��丮 ����
	int getLevel() { return level; }

	//setter
	void setAttack(int atk); // ����
	void setGold(int coin); // ���
	void setHealth(int hp); // ü��
	void addExperience(int amount); // ����ġ
	void levelUp();
	void useItem(); // ������ ���
	void displayStatus(); // ĳ���� �������ͽ� â
	void battle();//���� �¸��� ���ȹ�� ������ ����ϴ� �Լ�
	void bossBattle(); // ������ ���� �¸���
	

private: // �������

	std::vector<Item*>inv;//�����迭
	std::string name;
	int level;
	int health;
	int MaxHealth;
	int attack;
	int gold;
	int experience;

};