#include <iostream>
#include <random>
#include "Monster.h"
#include "Player.h"

//���� ���� 0.7~1.3 ó�� �����Լ�
static int randInt(int lo, int hi) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(gen);
}

// ������ ���� ��� / ��� ����
void Monster::takeDamage(int dmg) {
    if (dmg < 0) dmg = 0;
    m_hp -= dmg;
    if (m_hp < 0) m_hp = 0;
}
bool Monster::isMDead() const { return m_hp <= 0; }
bool Monster::getMIsDead() const { return isMDead(); }

// ���� ���� (�����Լ��� ��������ʰ�, Ư��������� ���� �� ����
// ������ (ĳ��������ü��+ĳ���Ͱ��ݷ�)%4
Monster* SpawnByIndex(int index, int level) {
    int i = index % 4;
    if (i < 0) i += 4; // ������ �������� �ʰ�����, ������ó��
    switch (i) {
    case 0: return new Goblin(level);
    case 1: return new Orc(level);
    case 2: return new Troll(level);
    default: return new Slime(level);
    }
}

// �÷��̾� ��ü�κ��� hp/atk/lv/name�� �޾� ���� ����
bool TurnBattleFromPlayer(Player& p) {
    int hp = p.getHealth();
    int atk = p.getAttack();
    int lv = p.getLevel();
    std::string name = p.getCharacterName();   

    bool win = TurnBattle(hp, atk, lv, name);  // �� �÷��̾� ���� ����
    p.setHealth(hp);
    return win;
}

// ���� ���� (�÷��̾� ������: hp/atk/lv/name)
bool TurnBattle(int& hp, int atk, int lv, const std::string& playerName) {
    // �÷��̾� lv�� 0.7~1.3�� ���� ����
    int minLv = (7 * lv) / 10;                if (minLv < 1) minLv = 1; // ���� 0 ����
    int maxLv = (13 * lv + 9) / 10;           if (maxLv < minLv) maxLv = minLv; // ����ó��
    int monLv = randInt(minLv, maxLv);                                           

    Monster* mon = SpawnByIndex((hp + atk) % 4, monLv);

    std::cout << "\n\n=== �߻��� " << mon->getName() << " ��(��) ��Ÿ����! ===\n\n";
    mon->show();
    mon->roar();
    std::cout << '\n';

    bool playerTurn = true; // �÷��̾� ����

    while (hp > 0 && !mon->isMDead()) {
        if (playerTurn) {
            std::cout << " [�÷��̾� ��] ����!���� " << atk << "\n\n";
            mon->takeDamage(atk);
        }
        else {
            int dmg = mon->attack();
            if (dmg < 0) dmg = 0;
            hp -= dmg; if (hp < 0) hp = 0;
            std::cout << " [���� ��] " << mon->getName()
                << " �� ����! �÷��̾ " << dmg << " ����\n\n";
        }

        std::cout << " ���� | �÷��̾� HP=" << hp
            << " | " << mon->getName() << " HP=" << mon->getHP() << "\n\n";

        playerTurn = !playerTurn;
    }

    bool win = (hp > 0);

    if (win) {
        std::cout << "\n " << playerName << " �¸�! " << mon->getName() << " óġ\n\n";
    }
    else {
        std::cout << "\n " << playerName << " �й�...\n\n";
    }

    delete mon; //�����Ҵ�����
    return win;
}

bool BossBattleFromPlayer(Player& p) {
    int hp = p.getHealth();
    int atk = p.getAttack();
    int lv = p.getLevel();
    std::string name = p.getCharacterName();

    bool wintoboss = BossBattle(hp, atk, lv, name); 
    p.setHealth(hp);                          
    return wintoboss;
}
bool BossBattle(int& hp, int atk, int lv, const std::string& playerName) {
    Invisible_Dragon* boss = new Invisible_Dragon(lv);

    std::cout << "\n === ���� ����: " << boss->getName() << " ===\n\n";
    boss->show();
    boss->roar();
    std::cout << '\n';

    bool playerTurn = true;  // �÷��̾� ����

    while (hp > 0 && !boss->isMDead()) {
        if (playerTurn) {
            std::cout << " [�÷��̾� ��] �������� " << atk << " ����\n\n";
            boss->takeDamage(atk);
        }
        else {
            int dmg = boss->attack();
            if (dmg < 0) dmg = 0;
            hp -= dmg; if (hp < 0) hp = 0;
            std::cout << " [���� ��] " << boss->getName()
                << "�� ����! �÷��̾ " << dmg << " ����\n\n";
        }

        std::cout << " ���� | �÷��̾� HP = " << hp << " / " << boss->getName() << " HP = " << boss->getHP() << "\n\n";
           

        playerTurn = !playerTurn;
    }

    bool wintoboss = (hp > 0);
    if (wintoboss){ 
        std::cout << "\n " << playerName << " �� " << boss->getName() << " ���Լ� �¸��ߴ� " << "\n\n"; 
    }
    else{
        std::cout << "\n " << playerName << " �� " << boss->getName() << " ���Լ� ó���ϰ� �й��ߴ� " << "\n\n";
    }

    delete boss;
    return wintoboss;
}