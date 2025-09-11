#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"
#include "GameManager.h"

using namespace std;

class Item;


Shop::Shop(Player& p):player(p) // Shop 생성자
{ // 동적 할당
    ShopList.push_back(new HealthPotion("체력 포션", 50, 1, 10));
    ShopList.push_back(new AttackBoost("공격력 증가 포션", 10, 1, 20));
    ShopList.push_back(new ExperienceBoost("경험치 증가 포션", 20, 1, 30));
};

Shop::~Shop() {
    for (auto item : ShopList) delete item;
}

void Shop::buyitem()
{

    int itemselect = 0; //구매할 아이템 선택지
    int itembuy = 0; //아이템 구매 수량
    std::cout << " ==============================" << std::endl;
    std::cout << " II 무엇을 구매하시겠습니까? II" << std::endl;
    std::cout << " II  1. 체력 포션            II\n II  2. 공격력 증가 포션     II\n II  3. 경험치 증가 포션     II\n II  4. 뒤로 가기            II" << std::endl;
    std::cout << " ==============================" << std::endl;
    std::cout << " [현재 골드 : " << player.getGold() << "G]" << std::endl;
    std::cout << "  >>> ";
    std::cin >> itemselect;
    
    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("체력 포션", 50, 1, 10);
        std::cout << " 체력 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        system("cls");
        double total = h.getPrice() * itembuy; // total = 물건 가격 * 아이템 구매 수량
        if (player.getGold() < total)
        {
            std::cout << " ===========================" << std::endl;
            std::cout << " II !!골드가 부족합니다!! II" << std::endl;
            std::cout << " II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - h.getPrice() * itembuy);
            std::cout << " 체력 포션을 " << itembuy << " 개 구매 했습니다." << std::endl;
            std::cout << " [남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "체력 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                HealthPotion* newPotion = new HealthPotion("체력 포션", 50, itembuy, 10);
                player.Getinv().push_back(newPotion);
            }
        }
        break;
    }
    case 2:
    {
        AttackBoost a("공격력 증가 포션", 10, 1, 20);
        std::cout << " 공격력 증가 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        double total = a.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << " ===========================" << std::endl;
            std::cout << " II !!골드가 부족합니다!! II" << std::endl;
            std::cout << " II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - a.getPrice() * itembuy);
            std::cout << " 공격력 증가 포션을 " << itembuy << " 개 구매 했습니다." << std::endl;
            std::cout << " [남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "공격력 증가 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                AttackBoost* newATKPotion = new AttackBoost("공격력 증가 포션", 10, itembuy, 20);
                player.Getinv().push_back(newATKPotion);
            }
        break;
        }
    }
    case 3:
    {
        ExperienceBoost e("경험치 증가 포션", 20, 1, 30);
        std::cout << " 경험치 증가 포션을 선택하셨습니다. 몇개 구매하시겠습니까?" << std::endl;
        std::cout << " 구매할 갯수 >>> ";
        std::cin >> itembuy;
        double total = e.getPrice() * itembuy;
        system("cls");
        if (player.getGold() < total)
        {
            std::cout << "  ===========================" << std::endl;
            std::cout << "  II !!골드가 부족합니다!! II" << std::endl;
            std::cout << "  II  처음으로 돌아갑니다  II" << std::endl;
            buyitem();
        }
        else
        {
            player.setGold(player.getGold() - e.getPrice() * itembuy);
            std::cout << " 경험치 증가 포션을 " << itembuy << " 개 구매 했습니다." << std::endl;
            std::cout << " [남은 골드 : " << player.getGold() << "G]" << std::endl;

            bool found = false;
            for (auto& item : player.Getinv())
            {
                if (item->getName() == "경험치 증가 포션")
                {
                    for (int i = 0; i < itembuy; ++i)
                        item->gainItem();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ExperienceBoost* newEXPPotion = new ExperienceBoost("경험치 증가 포션", 20, itembuy, 30);
                player.Getinv().push_back(newEXPPotion);
        }
        break;
        }
    }
    case 4:
    {
        system("cls");
        std::cout << " 메뉴 선택으로 돌아갑니다." << endl;
        displayitem();
    }
    default:
        break;
    }
}
    
 

void Shop::sellitem()
{
    int itemselect = 0; //아이템 선택
    int itemsell = 0; //아이템 판매 수량
    std::cout << " ==============================" << std::endl;
    std::cout << " II 무엇을 판매하시겠습니까? II" << std::endl;
    std::cout << " II  1. 체력 포션            II\n II  2. 공격력 증가 포션     II\n II  3. 경험치 증가 포션     II\n II  4. 뒤로 가기            II" << std::endl;
    std::cout << " ==============================" << std::endl;
    std::cout << " [현재 골드 : " << player.getGold() << "G]" << std::endl;
    std::cout << "  >>> ";
    std::cin >> itemselect;

    switch (itemselect)
    {
    case 1:
    {
        HealthPotion h("체력 포션", 50, 1, 10);
        std::cout << " 체력 포션을 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << " 판매할 갯수 >>> ";
        std::cin >> itemsell; //판매할 아이템 수량
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
            std::cout << " 보유 수량이 부족합니다. (보유: " << available << "개)\n";
            break;
        }
        double total = (h.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " 체력 포션을 " << itemsell << " 개 판매 했습니다." << std::endl;
        std::cout << " [현재 골드 : " << player.getGold() << "G]\n";
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
        AttackBoost a("공격력 증가 포션", 10, 1, 20);
        std::cout << " 공격력 증가 포션을 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << "  판매할 갯수 >>> ";
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
            std::cout << " 보유 수량이 부족합니다. (보유: " << available << "개)\n";
            break;
        }
        double total = (a.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " 공격력 증가 포션을 " << itemsell << " 개 판매 했습니다." << std::endl;
        std::cout << " [현재 골드 : " << player.getGold() << "G]\n";
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
        ExperienceBoost e("경험치 증가 포션", 20, 1, 30);
        std::cout << " 경험치 증가 포션을 선택하셨습니다. 몇개 판매하시겠습니까?" << std::endl;
        std::cout << " 판매할 갯수 >>> ";
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
            std::cout << " 보유 수량이 부족합니다. (보유: " << available << "개)\n";
            break;
        }
        double total = (e.getPrice() * itemsell) * 0.6;
        player.setGold(player.getGold() + (int)total);
        std::cout << " 경험치 증가 포션을 " << itemsell << " 개 판매 했습니다." << std::endl;
        std::cout << " [현재 골드 : " << player.getGold() << "G]\n";
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
        std::cout << " 메뉴 선택으로 돌아갑니다." << endl;
        system("cls");
        displayitem();
    }
    default:
        std::cout << " 잘못된 선택입니다. 다시 선택해주세요." << std::endl;
        break;
    }
};

void Shop::displayitem()
{
    int Shopmenu;

    while (true)
    {
        cout << "\n =!=!=!=!=!= 상점 물품 목록 =!=!=!=!=!=\n" << endl;
        for (int i = 0; i < (int)ShopList.size(); ++i) {
            Item* ip = ShopList[i];
            cout << i + 1 << ". [이름: " << ip->getName()
                << " , 가격: " << ip->getPrice() << "G]\n" << endl;
        }
        std::cout << " [현재 골드 : " << player.getGold() << "G]" << std::endl;
        std::cout << " ==========================" << std::endl;
        std::cout << " II 메뉴를  선택해주세요 II"<< std::endl;
        std::cout << " II   1.포션 구매하기    II" << std::endl;
        std::cout << " II   2.포션 판매하기    II" << std::endl;
        std::cout << " II   3.포션상점 나가기  II" << std::endl;
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
            std::cout << " 상점을 나갑니다." << endl;
            break;
        default:
            std::cout << " 잘못된 입력입니다." << std::endl;
            break;
        };
    };
};