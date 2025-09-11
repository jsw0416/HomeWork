#pragma once
#include <string>


class Player; // ���� ����

class Item //�߻�Ŭ����
{
public:
	virtual ~Item() {} // ���� �Ҹ���
	virtual std::string getName() = 0; // ���� �����Լ�,������ �̸� ������ �Լ� (�ڽ�Ŭ�������� ����)
	virtual void use(Player& player) = 0; //���� �����Լ�, ���� ��� �Լ� (�ڽ�Ŭ�������� ����)
	virtual int gainItem() = 0; // ������ ���� +1 (���� ����, ������ ���)
	virtual int lossItem() = 0; // ������ ���� -1(���� �Ǹ�, ������ ���)
	virtual int getCount() = 0; // ���� ������ ���� ���� ��ȯ
	virtual int getPrice() = 0; // ������ ���� ��ȯ
};

class HealthPotion : public Item {
private:
	std::string name; // ������ �̸� (ex: ���� ����)
	int healthRestore; // ȸ���� (ex: ü��+50)
	int numberofHealthPotion; // ȸ������ ���� �ʱⰪ
	int priceHealthPotion =10; // ȸ������ ���� ����
public:
	HealthPotion(std::string n, int Restore, int Numberof, int price); //������: �̸�(n), ȸ����(Restore), ����(Numberof), ����(price)
	std::string getName() override; //�θ�Ŭ���� getName(������ �̸� ��ȯ) �޾ƿ� ����
	void use(Player& player) override; //�θ�Ŭ����(���� ���) �޾ƿ� ����
	int gainItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int lossItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int getCount() override { return numberofHealthPotion; }
	int getPrice() override { return priceHealthPotion;}
};

class AttackBoost : public Item {
private:
	std::string name; // ������ �̸� (ex: �Ŀ� �ν�Ʈ)
	int attackIncrease; // ������ (ex: ���ݷ�+10)
	int numberofAttackBoost; // ���� �ν�Ʈ ���� �ʱⰪ
	int priceAttackBoost = 20; // ���� �ν�Ʈ ���� ����
public:
	AttackBoost(std::string n, int Increase, int Numberof, int price); //������: �̸�(n), ������(Increase), ����(Numberof), ����(price)
	std::string getName() override; //�θ�Ŭ���� getName(������ �̸� ��ȯ) �޾ƿ� ����
	void use(Player& player) override; //�θ�Ŭ����(���� ���) �޾ƿ� ����
	int gainItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int lossItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int getCount() override { return numberofAttackBoost; }
	int getPrice() override { return priceAttackBoost; }
};

class ExperienceBoost : public Item {
private:
	std::string name; // ������ �̸� (ex: ����ġ �ν�Ʈ)
	int experienceIncrease; // ������ (ex: ����ġ+20)
	int numberofExperienceBoost; // ����ġ �ν�Ʈ ���� �ʱⰪ
	int priceExperienceBoost = 30; // ����ġ �ν�Ʈ ���� ����
public:
	ExperienceBoost(std::string n, int Increase, int Numberof, int price); //������: �̸�(n), ������(Increase), ����(Numberof), ����(price)
	std::string getName() override; //�θ�Ŭ���� getName(������ �̸� ��ȯ) �޾ƿ� ����
	void use(Player& player) override; //�θ�Ŭ����(���� ���) �޾ƿ� ����
	int gainItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int lossItem() override; //�θ�Ŭ����(���� ���� ����) �޾ƿ� ����
	int getCount() override { return numberofExperienceBoost; }
	int getPrice() override { return priceExperienceBoost; }
};

// �κ��丮 Ŭ���� �߰��ϱ�
class Inventory
{
public:
	Inventory() {}
	~Inventory() {}

	void PrintCurrentItemAndGold(Player& player); // ���� ������ ���� �� ��� ��� ����
};