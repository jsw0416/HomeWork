#include <iostream>
#include <string>
using namespace std;

void setPotion(int count, int* p_HPpotion, int* p_MPpotion) // ���� �Լ�
{
	*p_HPpotion = count; *p_MPpotion = count;
}

int main()
{
	int status[4] = { 0 }; // ������ �Է��� �迭 
	int choice; // �ൿ ������
	int HPpotion = 5, MPpotion = 5;

	while (true)
	{
		cout << "HP�� �Է����ּ���:";
		cin >> status[0];
		cout << "MP�� �Է����ּ���:";
		cin >> status[1];
		if (status[0] < 50 || status[1] < 50)
		{
			cout << " HP Ȥ�� MP�� �ʹ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else if (status[0] > 100 || status[1] > 100)
		{
			cout << " HP Ȥ�� MP�� �ʹ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else
		{
			break;
		}

	}

	while (true)
	{
		cout << "���ݷ��� �Է����ּ���:";
		cin >> status[2];
		cout << "������ �Է����ּ���:";
		cin >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << " ���ݷ� Ȥ�� ������ �ʹ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else if (status[2] > 100 || status[3] > 100)
		{
			cout << " ���ݷ� Ȥ�� ������ �ʹ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "���� �ɷ�ġ" << endl;
		cout << "HP :" << status[0] << endl;
		cout << "MP :" << status[1] << endl;
		cout << "ATK :" << status[2] << endl;
		cout << "DEF :" << status[3] << endl;
		cout << "HP�� MP������ 5���� ���޵Ǿ����ϴ�." << endl;
		cout << "=====�ൿ�� �������ּ���=====" << endl;
		cout << "1. HP ȸ��" << endl;
		cout << "2. MP ȸ��" << endl;
		cout << "3. HP ��ȭ" << endl;
		cout << "4. MP ��ȭ" << endl;
		cout << "5. ���� ��ų ���" << endl;
		cout << "6. �ʻ�� ���" << endl;
		cout << "7. ���� ����" << endl;
		cout << "=============================" << endl;

		cin >> choice;

		if (choice == 1)
		{
			cout << "HP ȸ��" << endl;
			if (HPpotion > 0)
			{
				status[0] += 20;
				HPpotion--;
				cout << "HP���� 1���� �Ҹ��� HP�� 20 ȸ���߽��ϴ�." << endl;
				cout << "���� HP:" << status[0] << endl;
				cout << "���� ���� ��:" << HPpotion << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (choice == 2)
		{
			if (MPpotion > 0)
			{
				status[1] += 20;
				MPpotion--;
				cout << "MP���� 1���� �Ҹ��� MP�� 20 ȸ���߽��ϴ�." << endl;
				cout << "���� MP:" << status[1] << endl;
				cout << "���� ���� ��:" << MPpotion << endl;
			}
			else
			{
				cout << "������ �����մϴ�." << endl;
			}
		}
		else if (choice == 3)
		{
			status[0] *= 2;
			cout << "HP�� �ι� �����߽��ϴ�." << endl;
			cout << "���� HP:" << status[0] << endl;
		}
		else if (choice == 4)
		{
			status[1] *= 2;
			cout << "MP�� �ι� �����߽��ϴ�." << endl;
			cout << "���� MP:" << status[1] << endl;
		}
		else if (choice == 5)
		{
			if (status[1] >= 50)
			{
				status[1] -= 50;
				cout << "MP�� �Ҹ��� ���ݽ�ų�� ����߽��ϴ�." << endl;
				cout << "���� MP:" << status[1] << endl;
			}
			else
			{
				cout << "MP�� ������ ��ų�� ��� �� �� �����ϴ�." << endl;
			}
		}
		else if (choice == 6)
		{
			status[1] /= 2;
			cout << "MP�� ������ ����� �ʻ�⸦ ����߽��ϴ�." << endl;
			cout << "���� MP:" << status[1] << endl;
		}
		else if (choice == 7)
		{
			cout << "������ �����մϴ�." << endl;
			return 0;
		}
	}
}
