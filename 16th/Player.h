#pragma once
#include <iostream>
#include <vector>
#include <string>

class Item; // 전방선언

class Player
{
public: // 멤버함수
	
	Player(std::string name);// 생성자

	~Player() {}  // 소멸자

	//getter
	int getAttack() { return attack; } // 공격
	int getGold() {	return gold;} //골드
	int getHealth() { return health; } //체력
	int getMaxHealth() { return MaxHealth; }
	int getExperience() { return experience; } // 경험치
	std::string getCharacterName() { return name; } // 캐릭터 닉네임 
	std::vector<Item*>& Getinv() { return inv; } // 인벤토리 접근
	int getLevel() { return level; }

	//setter
	void setAttack(int atk); // 공격
	void setGold(int coin); // 골드
	void setHealth(int hp); // 체력
	void addExperience(int amount); // 경험치
	void levelUp();
	void useItem(); // 아이템 사용
	void displayStatus(); // 캐릭터 스테이터스 창
	void battle();//전투 승리시 골드획득 로직에 사용하는 함수
	void bossBattle(); // 보스와 전투 승리시
	

private: // 멤버변수

	std::vector<Item*>inv;//동적배열
	std::string name;
	int level;
	int health;
	int MaxHealth;
	int attack;
	int gold;
	int experience;

};