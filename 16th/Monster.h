#pragma once 
#include <iostream> 
#include <string> 
#include <vector> 
#include "Player.h" 
using namespace std; 

class Monster { 
public: 
	// ���� ���� (�̸� ����) 
	string m_name; 
	int m_hp; 
	int m_atk; 
	int m_lv; 
	
	Monster(string n, int h, int a) 
		: m_name(n), m_hp(h), m_atk(a), m_lv(1) { } 
	virtual ~Monster() {} // ���� ����� ���� ���� ������ ������ġ
	
	// getter (�̸� ���� + ���� �߰�) 
	const string& getName() const noexcept { return m_name; } 
	int getHP() const noexcept { return m_hp; } 
	int getATK() const noexcept { return m_atk; } 
	int getLV() const noexcept { return m_lv; } 
	
	// ���� ���� 
	virtual void roar() { cout << m_name << ": xxx!" << endl; } 
	virtual int attack() { return m_atk; } 
	
	// ���� ���� 
	virtual void takeDamage(int dmg); 
	bool isMDead() const; 
	bool getMIsDead() const; 
	
	void show() { 
		cout << " [ " << getName() << " ] " << "LV:" << getLV() << " HP:" << getHP() << " /ATK:" << getATK()<< "\n" << endl;
	} 
}; 

// �Ļ� ���͵� (m_lv ���� �߰�) 
class Goblin : public Monster { 
public: 
	Goblin(int lv) : Monster("Goblin", 10 + lv * 10, 10 * lv) { m_lv = lv; } 
	void roar() override { cout << " Goblin: ����!" << endl;} 
}; 
class Orc : public Monster { 
public: 
	Orc(int lv) : Monster("Orc", 20 + lv * 20, 15 * lv) { m_lv = lv; } 
	void roar() override { cout << " Orc: ����!" << endl; } 
}; 
class Troll : public Monster { 
public: 
	Troll(int lv) : Monster("Troll", 30 + lv * 30, 20 * lv) { m_lv = lv; } 
	void roar() override { cout << " Troll: �����!" << endl; }
}; 
class Slime : public Monster { 
public: 
	Slime(int lv) : Monster("Slime", 40 + lv * 40, 30 * lv) { m_lv = lv; } 
	void roar() override { cout << " Slime: �ʱ�?" << endl; } 
};
class Invisible_Dragon : public Monster {
public:
	Invisible_Dragon(int lv) : Monster("Invisible_Dragon", 65 + lv * 65, 30 * lv) { m_lv = lv; }
	void roar() override { cout << " Invisible_Dragon : ���� �巡���� ���� �����ϴ� " << endl; }
};

// === ���� ���� ��ƿ (���� ����) ===
//index: 0=Goblin, 1=Orc, 2=Troll, 3=Slime 
Monster* SpawnByIndex(int index, int level); 

bool TurnBattle(int& hp, int atk, int lv, const std::string& playerName);
bool TurnBattleFromPlayer(Player& p);

bool BossBattle(int& hp, int atk, int lv, const std::string& playerName);
bool BossBattleFromPlayer(Player& p);