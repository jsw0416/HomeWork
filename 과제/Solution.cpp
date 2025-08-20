#include <iostream>
#include <string>
using namespace std;

void setPotion(int count, int* p_HPpotion, int* p_MPpotion) // 포션 함수
{
	*p_HPpotion = count; *p_MPpotion = count;
}

int main()
{
	int status[4] = { 0 }; // 스탯을 입력할 배열 
	int choice; // 행동 선택지
	int HPpotion = 5, MPpotion = 5;

	while (true)
	{
		cout << "HP를 입력해주세요:";
		cin >> status[0];
		cout << "MP를 입력해주세요:";
		cin >> status[1];
		if (status[0] < 50 || status[1] < 50)
		{
			cout << " HP 혹은 MP가 너무 낮습니다. 다시 입력하세요" << endl;
		}
		else if (status[0] > 100 || status[1] > 100)
		{
			cout << " HP 혹은 MP가 너무 높습니다. 다시 입력하세요" << endl;
		}
		else
		{
			break;
		}

	}

	while (true)
	{
		cout << "공격력을 입력해주세요:";
		cin >> status[2];
		cout << "방어력을 입력해주세요:";
		cin >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << " 공격력 혹은 방어력이 너무 낮습니다. 다시 입력하세요" << endl;
		}
		else if (status[2] > 100 || status[3] > 100)
		{
			cout << " 공격력 혹은 방어력이 너무 높습니다. 다시 입력하세요" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "현재 능력치" << endl;
		cout << "HP :" << status[0] << endl;
		cout << "MP :" << status[1] << endl;
		cout << "ATK :" << status[2] << endl;
		cout << "DEF :" << status[3] << endl;
		cout << "HP와 MP포션이 5개씩 지급되었습니다." << endl;
		cout << "=====행동을 선택해주세요=====" << endl;
		cout << "1. HP 회복" << endl;
		cout << "2. MP 회복" << endl;
		cout << "3. HP 강화" << endl;
		cout << "4. MP 강화" << endl;
		cout << "5. 공격 스킬 사용" << endl;
		cout << "6. 필살기 사용" << endl;
		cout << "7. 게임 종료" << endl;
		cout << "=============================" << endl;

		cin >> choice;

		if (choice == 1)
		{
			cout << "HP 회복" << endl;
			if (HPpotion > 0)
			{
				status[0] += 20;
				HPpotion--;
				cout << "HP포션 1개를 소모해 HP를 20 회복했습니다." << endl;
				cout << "현재 HP:" << status[0] << endl;
				cout << "남은 포션 수:" << HPpotion << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (choice == 2)
		{
			if (MPpotion > 0)
			{
				status[1] += 20;
				MPpotion--;
				cout << "MP포션 1개를 소모해 MP를 20 회복했습니다." << endl;
				cout << "현재 MP:" << status[1] << endl;
				cout << "남은 포션 수:" << MPpotion << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (choice == 3)
		{
			status[0] *= 2;
			cout << "HP가 두배 증가했습니다." << endl;
			cout << "현재 HP:" << status[0] << endl;
		}
		else if (choice == 4)
		{
			status[1] *= 2;
			cout << "MP가 두배 증가했습니다." << endl;
			cout << "현재 MP:" << status[1] << endl;
		}
		else if (choice == 5)
		{
			if (status[1] >= 50)
			{
				status[1] -= 50;
				cout << "MP를 소모해 공격스킬을 사용했습니다." << endl;
				cout << "남은 MP:" << status[1] << endl;
			}
			else
			{
				cout << "MP가 부족해 스킬을 사용 할 수 없습니다." << endl;
			}
		}
		else if (choice == 6)
		{
			status[1] /= 2;
			cout << "MP의 절반을 사용해 필살기를 사용했습니다." << endl;
			cout << "남은 MP:" << status[1] << endl;
		}
		else if (choice == 7)
		{
			cout << "게임을 종료합니다." << endl;
			return 0;
		}
	}
}
