
#include <iostream>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "GameManager.h"
#include <string>

using namespace std;

Player::Player(std::string name)
    : name(name), level(1), health(200), MaxHealth(200), gold(100), attack(30), experience(0), inv()
{
    inv.push_back(new HealthPotion("ü�� ����", 50, 1, 10));
    inv.push_back(new AttackBoost("���ݷ� ���� ����", 10, 1, 20));
    inv.push_back(new ExperienceBoost("����ġ ���� ����", 20, 1, 30));

}


//Setter �Լ�
void Player::setAttack(int atk)
{
    attack = atk;
}

void Player::setGold(int coin)
{
    gold = coin;
}

void Player::setHealth(int hp)
{
    health = hp;
}

void Player::displayStatus()
{
    cout << " \n" << endl;
    cout << " ======================" << endl;
    cout << "  * Character status * " << endl;
    cout << " ======================" << endl;
    cout << " �г��� : " << name << endl;
    cout << " Level : " << level << endl;
    cout << " HP : " << health << endl;
    cout << " ���ݷ� : " << attack << endl;
    cout << " ����ġ : " << experience << endl;
    cout << " ��� : " << gold << endl;
    cout << " ======================" << endl;
    cout << " \n" << endl;

}

void Player::levelUp() // �������� ü�� Ǯ ȸ��
{

    if (level >= 10)
    {
        cout << " �ִ� �����Դϴ�! " << endl;
        return;
    }
    else
    {
        level += 1;
        MaxHealth += (level * 20);  // ������ 20���� ����ŭ �ִ�ü������
        attack += (level * 5);     // ������ 5���� ����ŭ ���ݷ�����
        health = MaxHealth;

        cout << " ������! ���� ����: " << level << endl;
    }
}

void Player::addExperience(int amount) // ����ġ
{
    experience += amount;

    if (experience >= 100)
    {
        experience -= 100;
        levelUp();

        cout << "+" << amount << "����ġ�� ȹ���߽��ϴ�! ���� ����ġ:" << experience << endl;
    }
}

void Player::bossBattle()
{
    bool winBoss = BossBattleFromPlayer(*this); //���� ��� bool�޾ƿ�

    if (winBoss)
    {
        int rewardGold = (rand() % 2 == 0) ? 80 : 100; //rand = 0 �̻� ���� ����(����) ���� �� ��10 : ����20
        int rewardExp = 60;
        gold += rewardGold;
        addExperience(rewardExp);
        cout << " ���� ȹ��! + " << rewardGold << " ���, + " << rewardExp << " ����ġ [���� ���" << gold << "]\n" << endl;

        int drop = rand() % 100; // ������ rand = (0~99) 1/100 = 1%
        if (drop < 50)  // 30������ �� 30%
        {
            int item = rand() % 3;   // 0, 1, 2 �� �ϳ� ����

            if (item == 0)
            {
                bool found = false;
                for (auto& item : Getinv())
                {
                    if (item->getName() == "ü�� ����")
                    {
                        for (int i = 0; i < 1; ++i)
                            item->gainItem();
                        found = true;
                        cout << " ü�� ������ ȹ���߽��ϴ�! " << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << " ü�� ������ ȹ���߽��ϴ�! " << endl;
                    HealthPotion* newPotion = new HealthPotion("ü�� ����", 50, 1, 10);
                    Getinv().push_back(newPotion);
                }
            }
            else if (item == 1)
            {
                bool found = false;
                for (auto& item : Getinv())
                {
                    if (item->getName() == "���ݷ� ���� ����")
                    {
                        for (int i = 0; i < 1; ++i)
                            item->gainItem();
                        found = true;
                        cout << " ���ݷ� ���� ������ ȹ���߽��ϴ�! " << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << " ���ݷ� ���� ������ ȹ���߽��ϴ�! " << endl;
                    AttackBoost* newPotion = new AttackBoost("���ݷ� ���� ����", 10, 1, 20);
                    Getinv().push_back(newPotion);
                }
            }
            else
            {
                bool found = false;
                for (auto& item : Getinv())
                {
                    if (item->getName() == "����ġ ���� ����")
                    {
                        for (int i = 0; i < 1; ++i)
                            item->gainItem();
                        found = true;
                        cout << " ����ġ ���� ������ ȹ���߽��ϴ�! " << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << " ����ġ ���� ������ ȹ���߽��ϴ�! " << endl;
                    ExperienceBoost* newPotion = new ExperienceBoost("����ġ ���� ����", 20, 1, 30);
                    Getinv().push_back(newPotion);
                }
            }
        }
    }
    else
    {
        health = MaxHealth / 2;
        cout << " �÷��̾ ����Ͽ����ϴ�." << health << " �� ü�� ȸ�� �� ������ ��ȯ�մϴ�!" << endl;
    }
}

void Player::battle()  // ���� �¸��� ��� 50ȹ��
{
    bool win = TurnBattleFromPlayer(*this); //���� ��� bool�޾ƿ�

       if (win) 
       {
           int rewardGold = (rand() % 2 == 0) ? 10 : 20; //rand = 0 �̻� ���� ����(����) ���� �� ��10 : ����20
           int rewardExp = rand() % 30;
           gold += rewardGold;
           addExperience(rewardExp);
           cout << " ���� ȹ��! + " << rewardGold << " ���, + " << rewardExp << " ����ġ [���� ���" << gold << "]\n" << endl;

       int drop = rand() % 100; // ������ rand = (0~99) 1/100 = 1%
       if (drop < 30)  // 30������ �� 30%
       {
           int item = rand() % 3;   // 0, 1, 2 �� �ϳ� ����

           if (item == 0)
           {
               bool found = false;
               for (auto& item : Getinv())
               {
                   if (item->getName() == "ü�� ����")
                   {
                       for (int i = 0; i < 1; ++i)
                           item->gainItem();
                       found = true;
                       cout << " ü�� ������ ȹ���߽��ϴ�! " << endl;
                       break;
                   }
               }
               if (!found)
               {
                   cout << " ü�� ������ ȹ���߽��ϴ�! " << endl;
                   HealthPotion* newPotion = new HealthPotion("ü�� ����", 50, 1, 10);
                   Getinv().push_back(newPotion);
               }
           }
           else if (item == 1)
           {
               bool found = false;
               for (auto& item : Getinv())
               {
                   if (item->getName() == "���ݷ� ���� ����")
                   {
                       for (int i = 0; i < 1; ++i)
                           item->gainItem();
                       found = true;
                       cout << " ���ݷ� ���� ������ ȹ���߽��ϴ�! " << endl;
                       break;
                   }
               }
               if (!found)
               {
                   cout << " ���ݷ� ���� ������ ȹ���߽��ϴ�! " << endl;
                   AttackBoost* newPotion = new AttackBoost("���ݷ� ���� ����", 10, 1, 20);
                   Getinv().push_back(newPotion);
               }
           }
           else
           {
               bool found = false;
               for (auto& item : Getinv())
               {
                   if (item->getName() == "����ġ ���� ����")
                   {
                       for (int i = 0; i < 1; ++i)
                           item->gainItem();
                       found = true;
                       cout << " ����ġ ���� ������ ȹ���߽��ϴ�! " << endl;
                       break;
                   }
               }
               if (!found)
               {
                   cout << " ����ġ ���� ������ ȹ���߽��ϴ�! " << endl;
                  ExperienceBoost* newPotion = new ExperienceBoost("����ġ ���� ����", 20, 1, 30);
                   Getinv().push_back(newPotion);
               }
           }
       }
       }
      else
      {
         health = MaxHealth / 2;
         cout << " �÷��̾ ����Ͽ����ϴ�."<< health << " �� ü�� ȸ�� �� ������ ��ȯ�մϴ�!" << endl;
      }    
 }


void Player::useItem()
{
    int input;
    std::cin >> input;

    Item* selectedItem = nullptr;
    int index = -1;

    auto& inventory = Getinv();

    for (int i = 0; i < inventory.size(); i++)
    {
         if (input == 1 && dynamic_cast<HealthPotion*>(inventory[i])) {
             selectedItem = inventory[i];
             index = i;
             break;
         }          
        
        else if (input == 2 && dynamic_cast<AttackBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 3 && dynamic_cast<ExperienceBoost*>(inventory[i])) {
            selectedItem = inventory[i];
            index = i;
            break;
        }
        else if (input == 0) {
            return;
        }
    }
    
    if (selectedItem == nullptr && input != 0) {
        std::cout << "�ش� �������� �����ϴ�." << std::endl;
        return;
    }

    if (health >= MaxHealth && input == 1 ) //����ü���� �ִ� ü�º��� ũ��, input�� 1�϶�
    {
        std::cout << "ü���� ���� á���ϴ�! ������ ����� �� �����ϴ�." << endl;
        return;
    }
    else 
    {
        selectedItem->use(*this); //������ ���
        selectedItem->lossItem();
    }

    if (selectedItem->getCount() <= 0) // ������ ������ 0���� ������ ��ü�� �����
    {
        delete selectedItem; //���� �Ҵ�� ��ü �޸� ����
        inventory.erase(inventory.begin() + index); //�κ��丮���� ����
        return;
    }
}

