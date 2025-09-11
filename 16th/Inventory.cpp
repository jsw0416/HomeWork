#include "Inventory.h"
#include "Player.h"
#include <iostream>

AttackBoost::AttackBoost(std::string n, int increase, int Numberof, int price) // ���ݷ� �ν�Ʈ(�̸�, ������, ����, ����)
	:name(n), attackIncrease(increase), numberofAttackBoost(Numberof), priceAttackBoost(price){
}

std::string AttackBoost::getName() { // ���ݷ� �ν�Ʈ �̸� ��ȯ �Լ�
	return name;
}

void AttackBoost::use(Player& player) { // ���ݷ� �ν�Ʈ ��� �� ���ݷ� ���� �Լ�
	int currentAttack = player.getAttack();          // getter�� �а�
	player.setAttack(currentAttack + attackIncrease); // setter�� ���ݷ� ����
	std::cout << name << " ���! ���ݷ��� " << attackIncrease << "��ŭ �����Ͽ����ϴ�. \n";

}

int AttackBoost::gainItem() // ���ݷ� �ν�Ʈ ���� +1
{
	return ++numberofAttackBoost;
}

int AttackBoost::lossItem() // ���ݷ� �ν�Ʈ ���� -1
{
	if (numberofAttackBoost > 0) {
		return --numberofAttackBoost;
	}
	else {
		std::cout << "���ݷ� �ν�Ʈ�� �����ϴ�!" << std::endl;
		return 0;
	}
}

HealthPotion::HealthPotion(std::string n, int restore, int Numberof, int price) // ȸ�� ����(�̸�, ȸ����, ����)
	:name(n), healthRestore(restore), numberofHealthPotion(Numberof), priceHealthPotion(price){
}

std::string HealthPotion::getName() {// ȸ�� ���� �̸� ��ȯ �Լ�
	return name;
}

void HealthPotion::use(Player& player) { // ȸ�� ���� ��� �� ü�� ���� �Լ�
	int currentHealth = player.getHealth();  // getter�� ����ü�� ����
	int maxHealth = player.getMaxHealth(); // getter�� �ִ�ü�� ����

	if (currentHealth + healthRestore < maxHealth) // (����)����ü�� + ȸ���� < �ִ�ü��
	{
		player.setHealth(currentHealth + healthRestore); // setter�� ȸ���� ��ŭ ü�� ����
		std::cout << name << " ���! ü���� " << healthRestore << "��ŭ ȸ���Ǿ����ϴ�. \n";
	}

	else 
	{
		player.setHealth(maxHealth); // ����ü�� + ȸ������ �ִ�ü���� �ѱ��� ����
		std::cout << name << " ���! ü���� ������ ȸ���Ǿ����ϴ�. \n";
	}
	
}

int HealthPotion::gainItem() // ü�� ���� ���� +1
{
	return ++numberofHealthPotion;
}

int HealthPotion::lossItem() // ü�� ���� ���� -1
{
	if (numberofHealthPotion > 0) {
		return --numberofHealthPotion;
	}
	else {
		std::cout << "ü�� ������ �����ϴ�!" << std::endl;
		return 0;
	}
}

ExperienceBoost::ExperienceBoost(std::string n, int Increase, int Numberof, int price) // ����ġ �ν�Ʈ(�̸�, ������, ����, ����)
	:name(n), experienceIncrease(Increase), numberofExperienceBoost(Numberof), priceExperienceBoost(price){
}

std::string ExperienceBoost::getName() { // ����ġ �ν�Ʈ �̸� ��ȯ �Լ�
	return name;
}

void ExperienceBoost::use(Player& player) { // ����ġ �ν�Ʈ ��� �� ����ġ ���� �Լ�
	player.addExperience(experienceIncrease); // setter�� ����ġ ����
	std::cout << "\n" << name << " ���! ����ġ " << experienceIncrease << "��ŭ ȹ���Ͼ����ϴ�." << "\n";

}
int ExperienceBoost::gainItem()//����ġ �ν�Ʈ ���� +1
{
	return ++numberofExperienceBoost; 
}
int ExperienceBoost::lossItem()//����ġ �ν�Ʈ ���� -1
{
	if (numberofExperienceBoost > 0) {
		return --numberofExperienceBoost;
	}
	else {
		std::cout << "����ġ �ν�Ʈ�� �����ϴ�!" << std::endl;
		return 0;
	}
}
//***** ������ ���� ���� �� ��� ���
void Inventory::PrintCurrentItemAndGold(Player& player) {
	int hpCount = 0;
	int abCount = 0;
	int expCount = 0;

	for (auto* item : player.Getinv()) {
		if (auto* h = dynamic_cast<HealthPotion*>(item)) {
			hpCount += h->getCount();
		}
		else if (auto* a = dynamic_cast<AttackBoost*>(item)) {
			abCount += a->getCount();
		}
		else if (auto* e = dynamic_cast<ExperienceBoost*>(item)) {
			expCount += e->getCount();
		}
	}

	std::cout << "[ü�� ����: " << hpCount
		<< "��, ���ݷ� ���� ����: " << abCount
		<< "��, ����ġ ���� ����: " << expCount
		<< "��, ���� Gold: " << player.getGold() << "G]\n";
}

