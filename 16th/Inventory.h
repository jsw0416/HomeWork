#pragma once
#include <string>


class Player; // 전방 선언

class Item //추상클래스
{
public:
	virtual ~Item() {} // 가상 소멸자
	virtual std::string getName() = 0; // 순수 가상함수,아이템 이름 꺼내는 함수 (자식클래스에서 구현)
	virtual void use(Player& player) = 0; //순수 가상함수, 포션 사용 함수 (자식클래스에서 구현)
	virtual int gainItem() = 0; // 아이템 갯수 +1 (상점 구입, 전투중 드랍)
	virtual int lossItem() = 0; // 아이템 갯수 -1(상점 판매, 아이템 사용)
	virtual int getCount() = 0; // 현재 아이템 보유 갯수 반환
	virtual int getPrice() = 0; // 아이템 가격 반환
};

class HealthPotion : public Item {
private:
	std::string name; // 아이템 이름 (ex: 빨간 포션)
	int healthRestore; // 회복량 (ex: 체력+50)
	int numberofHealthPotion; // 회복포션 개수 초기값
	int priceHealthPotion =10; // 회복포션 가격 선언
public:
	HealthPotion(std::string n, int Restore, int Numberof, int price); //생성자: 이름(n), 회복량(Restore), 수량(Numberof), 가격(price)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
	int getCount() override { return numberofHealthPotion; }
	int getPrice() override { return priceHealthPotion;}
};

class AttackBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 파워 부스트)
	int attackIncrease; // 증가량 (ex: 공격력+10)
	int numberofAttackBoost; // 공격 부스트 개수 초기값
	int priceAttackBoost = 20; // 공격 부스트 가격 선언
public:
	AttackBoost(std::string n, int Increase, int Numberof, int price); //생성자: 이름(n), 증가량(Increase), 수량(Numberof), 가격(price)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
	int getCount() override { return numberofAttackBoost; }
	int getPrice() override { return priceAttackBoost; }
};

class ExperienceBoost : public Item {
private:
	std::string name; // 아이템 이름 (ex: 경험치 부스트)
	int experienceIncrease; // 증가량 (ex: 경험치+20)
	int numberofExperienceBoost; // 경험치 부스트 개수 초기값
	int priceExperienceBoost = 30; // 경험치 부스트 가격 선언
public:
	ExperienceBoost(std::string n, int Increase, int Numberof, int price); //생성자: 이름(n), 증가량(Increase), 수량(Numberof), 가격(price)
	std::string getName() override; //부모클래스 getName(아이템 이름 반환) 받아와 구현
	void use(Player& player) override; //부모클래스(포션 사용) 받아와 구현
	int gainItem() override; //부모클래스(포션 개수 증가) 받아와 구현
	int lossItem() override; //부모클래스(포션 개수 감소) 받아와 구현
	int getCount() override { return numberofExperienceBoost; }
	int getPrice() override { return priceExperienceBoost; }
};

// 인벤토리 클래스 추가하기
class Inventory
{
public:
	Inventory() {}
	~Inventory() {}

	void PrintCurrentItemAndGold(Player& player); // 현재 아이템 개수 및 골드 출력 선언
};