#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Shop.h" 
#include <memory>
#include <vector>
#include "GameManager.h"
#include "Inventory.h"

using namespace std;



void GameManager::GameStart() // ��ü ���� ����
{
	string NickName;
	cout << " =======================================\n" << endl;
	cout << " 16�� ������ ���迡 ���Ű��� ȯ���մϴ�!\n" << endl;
	cout << " =======================================\n" << endl;
	cout << "\n" << endl;
	cout << " �ɸ��� ������ ���� �̸��� �Է����ּ���!\n" << endl;
	cout << " >>>";
	while (true) {
		getline(cin, NickName);

		if (NickName.empty()) //�Է��� ������ ��
		{
			cout << "�г����� ��� ���� �� �����ϴ�. �ٽ� �Է����ּ���!\n";
			continue;
		}
		if (NickName.find(' ') != string::npos) //�г��ӿ� ������⸦ ���� ��
		{
			cout << "�г��ӿ� ������ ����� �� �����ϴ�. �ٽ� �Է����ּ���!\n";
			continue;
		}
		break;
	}
	player = Player(NickName);
	cout << "\n" << endl;
	cout << " �ɸ��� �̸� : " << player.getCharacterName() <<"\n" << endl;
	cout << " =======================================\n" << endl;
	cout << " ȯ���մϴ�! " << player.getCharacterName() << " ��! ������ ���۵˴ϴ� !\n" << endl;
	cout << " =======================================\n" << endl;
	selectAction();
}
   
void GameManager::selectAction() //�ɸ��͸� �����ϸ� �������� ���� �� �� �ִ� ������ ����
{   
	int selectaction;
	cout << " ==============    16�� ���� �Դϴ� !    ==============\n" << endl;
	cout << " ============== ���ϴ� ���� �������ּ���!==============\n" << endl;
	cout << " ���� - 1.\n ���� - 2.\n ���� Ȯ�� - 3.\n ���� ���� - 4.\n ���� ����(����) - 5.\n ���� ���� - 6.\n" << endl;
	cin >> selectaction;
	switch (selectaction) // �÷��̾ �����ϴ� ��ȣ�� �Է°�
	{
	case 1:
		system("cls");
		player.battle();
		cout << "\n" << endl;
		system("pause");
		system("cls");
		selectAction();
		break;
	case 2:
		system("cls");
		visitShop();
		break;
	case 3:
		system("cls");
		displayInventory();
		break;
	case 4:
	{
		system("cls");
		cout << " ==============���Ͻô� �������� ����ּ���==============\n" << endl;
		cout << " ü�� ���� - 1.\n ���ݷ� ���� ���� - 2.\n ����ġ ���� - 3.\n ������ - 0.\n" << endl;
		cout << " ========================================================\n" << endl;
		cout << " ���� ���� ���� ��� \n" << endl;
		Inventory inv;
		inv.PrintCurrentItemAndGold(player); // ���� ���� ���� ������ ������ ��� ���
		player.useItem();
		player.displayStatus();
		selectAction();
	}
	case 5:
		system("cls");
		player.bossBattle();
		cout << "\n" << endl;
		system("pause");
		system("cls");
		selectAction();
		break;
	case 6:
		return;
	default:
		system("cls");
		cout << " ========�߸� �Է��ϼ̽��ϴ�! �ٽ� �������ּ���!======== \n" << endl;
		selectAction();
		break;
	}
}

void GameManager::visitShop()
{
	system("cls");
	cout << " ==========������ ���Ű��� ȯ���մϴ�!==========\n" << endl;
	shop.displayitem();
	system("cls");
	selectAction();
}

void GameManager::displayInventory()
{
	cout << " ============Inventory=============\n" << endl;
	auto& inv = player.Getinv(); //�÷��̾��� �����迭�� �����Ͽ� ����
	if (inv.empty()) //�κ��丮�� ����ִٸ�
	{
		cout << " �κ��丮�� ��� �ֽ��ϴ�.\n" << endl;
	}
	else 
	{
		for (size_t i = 0; i < inv.size(); ++i) //�κ��丮 �迭�� �����۵��� �� üũ �� ���
		{
			cout << i + 1 << ".  ������ �̸� : " << inv[i]->getName() << " \n������ ���� : " << inv[i]->getCount() << " �� \n" << endl;
		}
	}
	cout << " ============Inventory=============\n" << endl;
	cout << "\n" << endl;
	cout << " ������ - 3.\n" << endl;
	
	int displayinv;
	cin >> displayinv;
	if (displayinv == 3) // ���� ������ �Է� �ޱ�
	{
		system("cls");
		selectAction();
	}
}