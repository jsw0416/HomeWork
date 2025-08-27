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
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
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
        cout << "[무기: " << name_ << ", 공격력: " << dmg_ << "]" << endl;
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
        cout << "[포션: " << name_ << ", 회복량: " << amount_ << "]" << endl;
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
            cout << "인벤토리가 꽉 찼습니다!" << endl;
            return;
        }
        pItems_[size_] = item; 
        ++size_;
    }

   
    void RemoveLastItem() 
    {
        if (size_ == 0)
        {
            cout << "인벤토리가 비어있습니다." << endl;
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
            cout << "(비어있음)" << endl;
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
    cout << "==== Item 인벤토리 ====" << endl;
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

    cout << "\n==== Weapon 인벤토리 ====" << endl;
    Inventory<Weapon> invWeapon; 
    invWeapon.AddItem(Weapon("Iron Sword", 15));
    invWeapon.AddItem(Weapon("Bow", 10));
    invWeapon.PrintAllItems();

    cout << "\n==== Potion 인벤토리 ====" << endl;
    Inventory<Potion> invPotion(2);
    invPotion.AddItem(Potion("HP Potion", 50));
    invPotion.AddItem(Potion("MP Potion", 30));
    invPotion.AddItem(Potion("Extra", 10)); 
    invPotion.PrintAllItems();

    return 0;
}
