#pragma once
#include <string>
#include <iostream>
#include <vector>

// ���Ϳ��� ����
// 1. ���� - ���ݷ�, ü��

class Item
{
private:
	std::string name;
	int index;
public:
	Item() {}
	Item(std::string name, int index) : name(name), index(index) {}
	void ShowItemInfo()
	{
		std::cout << "�������� �̸� : " << name << std::endl;
		std::cout << "�������� ��ȣ : " << index << std::endl;
	}
};

class Reward
{
private:
	int exp;
	int money;
	// ������
	Item* item;

public:
	Reward() {}
	Reward(int exp, int money, Item& item) : exp(exp), money(money)
	{
		this->item = new Item();
		this->item = &item;
	}
	~Reward()
	{
		delete item;
	}

	void RewardItem(std::vector<Item>* inventory);
	int RewardMoney() { return money; };
	int RewardExp() { return exp; };
};


class Monster;

class Player
{
private:
	int HP;
	int AP;
	// ü��, ���ݷ�
	int exp;
	int money;
	std::vector<Item> inventory; // ĳ���� ������ �κ��丮 Ȯ��� �Ȱڴ�. ���� �迭 vector
public:
	// ������
	Player() {} // �⺻ ������
	Player(int hp, int ap) : HP(hp), AP(ap)
	{
		std::cout << "�÷��̾ ������" << std::endl;
	}
	// �Ҹ���
	~Player() // �����Ҵ��� ���� �� delete
	{
		std::cout << "�÷��̾ �Ҹ��" << std::endl;
	}
	
	// �����ϴ�
	void Attack(Monster* monster);
	// ���ݹ޴�.
	void BeAttacked(int damage);
	// ��� üũ �Լ�
	bool IsDead();

	int GetAttackPower() { return AP; }
	void GetMoney(int money);
	void GetExp(int exp);
	std::vector<Item>* GetInventory();

	// �÷��̾��� ���� ������ �����ִ� �Լ�
	void ShowStatus();
};

// ���� ���� �Լ�
class Monster	   
{
protected:
	int HP;
	int AP;
	// ����
	Reward* monsterReward;

public:
	// ������
	Monster() {}
	Monster(int hp, int ap) : HP(hp), AP(ap){}
	// �Ҹ���
	~Monster() {}
	// Attack
	virtual void Attack(Player* player) = 0; 
	// Be_Attacked
	virtual void BeAttacked(Player* player) = 0;
	// DropReward
	virtual void DropReward(Player* player) = 0;
};

class Slime : public Monster
{
public:
	Slime(int hp, int ap, Reward* rewardPtr) : Monster(hp, ap)
	{
		std::cout << "������ ����!" << std::endl;
		InsertDropItemTable(rewardPtr);
	}
	~Slime()
	{
		std::cout << "������ �Ҹ��!" << std::endl;
	}

	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}

	// Attack
	void Attack(Player* player);
	// Be_Attacked
	void BeAttacked(Player* player);
	// DropReward
	void DropReward(Player* player);

	// ��� üũ �Լ�
	bool IsDead();
};

 


