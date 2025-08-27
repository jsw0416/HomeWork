#include <iostream>
#include <string>
using namespace std;


class Item 
{
    string name_;
    int    price_;
public:
    Item(string name = "Unknown", int price = 0) : name_(name), price_(price) {}
    void PrintInfo() const
    {
        cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
    }
};

class Weapon
{
    string name_;
    int    dmg_;
public:
    Weapon(string name = "Wood Sword", int dmg = 1) : name_(name), dmg_(dmg) {}
    void PrintInfo() const
    {
        cout << "[����: " << name_ << ", ���ݷ�: " << dmg_ << "]" << endl;
    }
};

class Potion
{
    string name_;
    int    amount_;
public:
    Potion(string name = "HP Potion", int amount = 50) : name_(name), amount_(amount) {}
    void PrintInfo() const 
    {
        cout << "[����: " << name_ << ", ȸ����: " << amount_ << "]" << endl;
    }
};


template <typename T>
class Inventory
{
private:
    T* pItems_;     
    int  capacity_;  
    int  size_;      

public:
   
    explicit Inventory(int capacity = 10)
        : pItems_(nullptr),
        capacity_(capacity <= 0 ? 1 : capacity),
        size_(0)
    {
        pItems_ = new T[capacity_]; 
    }

   
    ~Inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
        capacity_ = 0;
        size_ = 0;
    }

    
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    
    void AddItem(const T& item) 
    {
        if (size_ >= capacity_) 
        {
            cout << "�κ��丮�� �� á���ϴ�!" << endl;
            return;
        }
        pItems_[size_] = item; 
        ++size_;
    }

   
    void RemoveLastItem() 
    {
        if (size_ == 0)
        {
            cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
            return;
        }
        --size_;
    }

    
    int GetSize() const { return size_; }

    
    int GetCapacity() const { return capacity_; }

    
    void PrintAllItems() const
    {
        if (size_ == 0) 
        {
            cout << "(�������)" << endl;
            return;
        }
        for (int i = 0; i < size_; ++i) 
        {
            pItems_[i].PrintInfo();
        }
    }

    const T& operator[](int idx) const { return pItems_[idx]; }
    T& operator[](int idx) { return pItems_[idx]; }
};

int main()
{
    cout << "==== Item �κ��丮 ====" << endl;
    Inventory<Item> invItems(3); 
    invItems.AddItem(Item("Peach", 3));
    invItems.AddItem(Item("Herb", 10));
    invItems.AddItem(Item("Juwel", 120));
    invItems.AddItem(Item("Overflow", 999)); 

    cout << "Size/Capacity: " << invItems.GetSize() << " / " << invItems.GetCapacity() << endl;
    invItems.PrintAllItems();

    invItems.RemoveLastItem();
    invItems.RemoveLastItem();
    invItems.RemoveLastItem();
    invItems.RemoveLastItem(); 
    cout << "Size/Capacity: " << invItems.GetSize() << " / " << invItems.GetCapacity() << endl;
    invItems.PrintAllItems();

    cout << "\n==== Weapon �κ��丮 ====" << endl;
    Inventory<Weapon> invWeapon; 
    invWeapon.AddItem(Weapon("Iron Sword", 15));
    invWeapon.AddItem(Weapon("Bow", 10));
    invWeapon.PrintAllItems();

    cout << "\n==== Potion �κ��丮 ====" << endl;
    Inventory<Potion> invPotion(2);
    invPotion.AddItem(Potion("HP Potion", 50));
    invPotion.AddItem(Potion("MP Potion", 30));
    invPotion.AddItem(Potion("Extra", 10)); 
    invPotion.PrintAllItems();

    return 0;
}
