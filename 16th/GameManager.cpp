#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "Shop.h" 
#include <memory>
#include <vector>
#include "GameManager.h"
#include "Inventory.h"

using namespace std;



void GameManager::GameStart() // 전체 게임 실행
{
	string NickName;
	cout << " =======================================\n" << endl;
	cout << " 16조 전사의 모험에 오신것을 환영합니다!\n" << endl;
	cout << " =======================================\n" << endl;
	cout << "\n" << endl;
	cout << " 케릭터 생성을 위해 이름을 입력해주세요!\n" << endl;
	cout << " >>>";
	while (true) {
		getline(cin, NickName);

		if (NickName.empty()) //입력을 안했을 때
		{
			cout << "닉네임은 비어 있을 수 없습니다. 다시 입력해주세요!\n";
			continue;
		}
		if (NickName.find(' ') != string::npos) //닉네임에 띄워쓰기를 썼을 때
		{
			cout << "닉네임에 공백은 사용할 수 없습니다. 다시 입력해주세요!\n";
			continue;
		}
		break;
	}
	player = Player(NickName);
	cout << "\n" << endl;
	cout << " 케릭터 이름 : " << player.getCharacterName() <<"\n" << endl;
	cout << " =======================================\n" << endl;
	cout << " 환영합니다! " << player.getCharacterName() << " 님! 모험이 시작됩니다 !\n" << endl;
	cout << " =======================================\n" << endl;
	selectAction();
}
   
void GameManager::selectAction() //케릭터를 생성하면 컨텐츠를 선택 할 수 있는 마을에 입장
{   
	int selectaction;
	cout << " ==============    16조 마을 입니다 !    ==============\n" << endl;
	cout << " ============== 원하는 것을 선택해주세요!==============\n" << endl;
	cout << " 전투 - 1.\n 상점 - 2.\n 가방 확인 - 3.\n 스텟 관리 - 4.\n 던전 들어가기(보스) - 5.\n 게임 종료 - 6.\n" << endl;
	cin >> selectaction;
	switch (selectaction) // 플레이어가 선택하는 번호의 입력값
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
		cout << " ==============원하시는 선택지를 골라주세요==============\n" << endl;
		cout << " 체력 포션 - 1.\n 공격력 증가 포션 - 2.\n 경험치 포션 - 3.\n 나가기 - 0.\n" << endl;
		cout << " ========================================================\n" << endl;
		cout << " 현재 보유 포션 목록 \n" << endl;
		Inventory inv;
		inv.PrintCurrentItemAndGold(player); // 현재 보유 중인 아이템 갯수와 골드 출력
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
		cout << " ========잘못 입력하셨습니다! 다시 선택해주세요!======== \n" << endl;
		selectAction();
		break;
	}
}

void GameManager::visitShop()
{
	system("cls");
	cout << " ==========상점에 오신것을 환영합니다!==========\n" << endl;
	shop.displayitem();
	system("cls");
	selectAction();
}

void GameManager::displayInventory()
{
	cout << " ============Inventory=============\n" << endl;
	auto& inv = player.Getinv(); //플레이어의 동적배열에 접근하여 대입
	if (inv.empty()) //인벤토리가 비어있다면
	{
		cout << " 인벤토리가 비어 있습니다.\n" << endl;
	}
	else 
	{
		for (size_t i = 0; i < inv.size(); ++i) //인벤토리 배열에 아이템들을 다 체크 후 출력
		{
			cout << i + 1 << ".  아이템 이름 : " << inv[i]->getName() << " \n아이템 개수 : " << inv[i]->getCount() << " 개 \n" << endl;
		}
	}
	cout << " ============Inventory=============\n" << endl;
	cout << "\n" << endl;
	cout << " 나가기 - 3.\n" << endl;
	
	int displayinv;
	cin >> displayinv;
	if (displayinv == 3) // 상점 나가기 입력 받기
	{
		system("cls");
		selectAction();
	}
}