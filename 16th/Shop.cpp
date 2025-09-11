#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"
#include "GameManager.h"

using namespace std;

class Item;


Shop::Shop(Player& p):player(p) // Shop ������
{ // ���� �Ҵ�
    ShopList.push_back(new HealthPotion("ü�� ����", 50, 1, 10));
    ShopList.push_back(new AttackBoost("���ݷ� ���� ����", 10, 1, 20));
    ShopList.push_back(new ExperienceBoost("����ġ ���� ����", 20, 1, 30));
};

Shop::~Shop() {
    for (auto item : ShopList) delete item;
}

void Shop::buyitem()
{

    int itemselect = 0; //������ ������ ������
    int itembuy = 0; //������ ���� ����
    std::cout << " ==============================" << std::endl;
    std::cout << " II ������ �����Ͻðڽ��ϱ�? II" << std::endl;
    std::cout << " II  1. ü�� ����            II\n II  2. ���ݷ� ���� ����     II\n II  3. ����ġ ���� ����     II\n II  4. �ڷ� ����            II" << std::endl;
    std::cout << " ==============================" << std::endl;
    std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;
    std::cout << "  >>> ";
    std::cin >> itemselect;
    
    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("ü�� ����", 50, 1, 10);
        std::cout << " ü�� ������ �����ϼ̽��ϴ�. � �����Ͻðڽ��ϱ�?" << std::endl;
        std::cout << " ������ ���� >>> ";
        std::cin >> itembuy;
        system("cls");
        double total = h.getPrice() * itembuy; // total = ���� ���� * ������ ���� ����
        if (player.getGold() < total)
        {
            std::cout << " ===========================" << std::endl;
            std::cout << " II !!��尡 �����մϴ�!! II" << std::endl;
            std::cout << " II  ó������ ���ư��ϴ�  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - h.getPrice() * itembuy);
            std::cout << " ü�� ������ " << itembuy << " �� ���� �߽��ϴ�." << std::endl;
            std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "ü�� ����")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                HealthPotion* newPotion = new HealthPotion("ü�� ����", 50, itembuy, 10);
                player.Getinv().push_back(newPotion);
            }
        }
        break;
    }
    case 2:
    {
        AttackBoost a("���ݷ� ���� ����", 10, 1, 20);
        std::cout << " ���ݷ� ���� ������ �����ϼ̽��ϴ�. � �����Ͻðڽ��ϱ�?" << std::endl;
        std::cout << " ������ ���� >>> ";
        std::cin >> itembuy;
        double total = a.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << " ===========================" << std::endl;
            std::cout << " II !!��尡 �����մϴ�!! II" << std::endl;
            std::cout << " II  ó������ ���ư��ϴ�  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - a.getPrice() * itembuy);
            std::cout << " ���ݷ� ���� ������ " << itembuy << " �� ���� �߽��ϴ�." << std::endl;
            std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "���ݷ� ���� ����")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                AttackBoost* newATKPotion = new AttackBoost("���ݷ� ���� ����", 10, itembuy, 20);
                player.Getinv().push_back(newATKPotion);
            }
        break;
        }
    }
    case 3:
    {
        ExperienceBoost e("����ġ ���� ����", 20, 1, 30);
        std::cout << " ����ġ ���� ������ �����ϼ̽��ϴ�. � �����Ͻðڽ��ϱ�?" << std::endl;
        std::cout << " ������ ���� >>> ";
        std::cin >> itembuy;
        double total = e.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << "  ===========================" << std::endl;
            std::cout << "  II !!��尡 �����մϴ�!! II" << std::endl;
            std::cout << "  II  ó������ ���ư��ϴ�  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - e.getPrice() * itembuy);
            std::cout << " ����ġ ���� ������ " << itembuy << " �� ���� �߽��ϴ�." << std::endl;
            std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "����ġ ���� ����")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ExperienceBoost* newEXPPotion = new ExperienceBoost("����ġ ���� ����", 20, itembuy, 30);
                player.Getinv().push_back(newEXPPotion);
        }
        break;
        }
    }
    case 4:
    {
        system("cls");
        std::cout << " �޴� �������� ���ư��ϴ�." << endl;
        displayitem();
    }
    default:
        break;
    }
}
    
 

void Shop::sellitem()
{
    int itemselect = 0; //������ ����
    int itemsell = 0; //������ �Ǹ� ����
    std::cout << " ==============================" << std::endl;
    std::cout << " II ������ �Ǹ��Ͻðڽ��ϱ�? II" << std::endl;
    std::cout << " II  1. ü�� ����            II\n II  2. ���ݷ� ���� ����     II\n II  3. ����ġ ���� ����     II\n II  4. �ڷ� ����            II" << std::endl;
    std::cout << " ==============================" << std::endl;
    std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;
    std::cout << "  >>> ";
    std::cin >> itemselect;

    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("ü�� ����", 50, 1, 10);
        std::cout << " ü�� ������ �����ϼ̽��ϴ�. � �Ǹ��Ͻðڽ��ϱ�?" << std::endl;
        std::cout << " �Ǹ��� ���� >>> ";
        std::cin >> itemsell; //�Ǹ��� ������ ����
        system("cls");

        HealthPotion* hpItem = nullptr;
        for (auto* it : player.Getinv()) {
            if (auto* hp = dynamic_cast<HealthPotion*>(it)) {
                hpItem = hp;
                break;
            }
        }
        int available = hpItem ? hpItem->getCount() : 0;
        if (itemsell <= 0 || itemsell > available) {
            std::cout << " ���� ������ �����մϴ�. (����: " << available << "��)\n";
            break;
        }
        double total = (h.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " ü�� ������ " << itemsell << " �� �Ǹ� �߽��ϴ�." << std::endl;
        std::cout << " [���� ��� : " << player.getGold() << "G]\n";
        for (int i = 0; i < itemsell; ++i) hpItem->lossItem();
        if (hpItem->getCount() == 0) {
            auto& inv = player.Getinv();
            for (size_t i = 0; i < inv.size(); ++i) {
                if (inv[i] == hpItem) {
                    delete inv[i];
                    inv.erase(inv.begin() + i);
                    break;
                }
            }
        break;
        }
    }
    case 2:
    {
        AttackBoost a("���ݷ� ���� ����", 10, 1, 20);
        std::cout << " ���ݷ� ���� ������ �����ϼ̽��ϴ�. � �Ǹ��Ͻðڽ��ϱ�?" << std::endl;
        std::cout << "  �Ǹ��� ���� >>> ";
        std::cin >> itemsell;
        system("cls");

        AttackBoost* atkItem = nullptr;
        for (auto* it : player.Getinv()) {
            if (auto* ab = dynamic_cast<AttackBoost*>(it)) { 
                atkItem = ab;
                break; 
            }
        }
        int available = atkItem ? atkItem->getCount() : 0;
        if (itemsell <= 0 || itemsell > available) {
            std::cout << " ���� ������ �����մϴ�. (����: " << available << "��)\n";
            break;
        }
        double total = (a.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " ���ݷ� ���� ������ " << itemsell << " �� �Ǹ� �߽��ϴ�." << std::endl;
        std::cout << " [���� ��� : " << player.getGold() << "G]\n";
        for (int i = 0; i < itemsell; ++i) atkItem->lossItem();
        if (atkItem->getCount() == 0) {
            auto& inv = player.Getinv();
            for (size_t i = 0; i < inv.size(); ++i) {
                if (inv[i] == atkItem) {
                    delete inv[i];
                    inv.erase(inv.begin() + i);
                    break;
                }
            }
        break;
        }
    }
    case 3:
    {
        ExperienceBoost e("����ġ ���� ����", 20, 1, 30);
        std::cout << " ����ġ ���� ������ �����ϼ̽��ϴ�. � �Ǹ��Ͻðڽ��ϱ�?" << std::endl;
        std::cout << " �Ǹ��� ���� >>> ";
        std::cin >> itemsell;
        system("cls");

        ExperienceBoost* expitem = nullptr;
        for (auto* it : player.Getinv()) {
            if (auto* ex = dynamic_cast<ExperienceBoost*>(it)) {
                expitem = ex;
                break;
            }
        }
        int available = expitem ? expitem->getCount() : 0;
        if (itemsell <= 0 || itemsell > available) {
            std::cout << " ���� ������ �����մϴ�. (����: " << available << "��)\n";
            break;
        }
        double total = (e.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " ����ġ ���� ������ " << itemsell << " �� �Ǹ� �߽��ϴ�." << std::endl;
        std::cout << " [���� ��� : " << player.getGold() << "G]\n";
        for (int i = 0; i < itemsell; ++i) expitem->lossItem();
        if (expitem->getCount() == 0) {
            auto& inv = player.Getinv();
            for (size_t i = 0; i < inv.size(); ++i) {
                if (inv[i] == expitem) {
                    delete inv[i];
                    inv.erase(inv.begin() + i);
                    break;
                }
            }
        break;
        }
    }
    case 4:
    {
        std::cout << " �޴� �������� ���ư��ϴ�." << endl;
        system("cls");
        displayitem();
    }
    default:
        std::cout << " �߸��� �����Դϴ�. �ٽ� �������ּ���." << std::endl;
        break;
    }
};

void Shop::displayitem()
{
    int Shopmenu;

    while (true)
    {
        cout << "\n =!=!=!=!=!= ���� ��ǰ ��� =!=!=!=!=!=\n" << endl;
        for (int i = 0; i < (int)ShopList.size(); ++i) {
            Item* ip = ShopList[i];
            cout << i + 1 << ". [�̸�: " << ip->getName()
                << " , ����: " << ip->getPrice() << "G]\n" << endl;
        }
        std::cout << " [���� ��� : " << player.getGold() << "G]" << std::endl;
        std::cout << " ==========================" << std::endl;
        std::cout << " II �޴���  �������ּ��� II"<< std::endl;
        std::cout << " II   1.���� �����ϱ�    II" << std::endl;
        std::cout << " II   2.���� �Ǹ��ϱ�    II" << std::endl;
        std::cout << " II   3.���ǻ��� ������  II" << std::endl;
        std::cout << " ==========================" << std::endl;
        std::cout << "  >>> ";
        std::cin >> Shopmenu;
        switch (Shopmenu)
        {
        case 1:
            system("cls");
            buyitem();
            break;
        case 2:
            system("cls");
            sellitem();
            break;
        case 3:
            return;
            std::cout << " ������ �����ϴ�." << endl;
            break;
        default:
            std::cout << " �߸��� �Է��Դϴ�." << std::endl;
            break;
        };
    };
};