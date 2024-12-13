#include "lectures.h"

/*
*   1. c++ casting ������ ����
* 
*   2. virutal ���� �Լ��� ���� ����[��ü�������α׷����� ������]
*   pure virtual
*   abstract Ŭ����
*   vtable
* 
*   3. monster class (Goblin, Slime class) - Player ����
*   4. ���� ��� Reward - monster�׾��� �� �����ϴ� ������
*/

class AA
{
public:
	virtual void Show()
	{
		std::cout << "AA" << std::endl;
	}
};

class BB : public AA
{
public :
	void Show()
	{
		std::cout << "BB" << std::endl;
	}

	void MyBB()
	{
		std::cout << "MyBB" << std::endl;
	}
};

class CC : public AA
{
public :
	void Show()
	{
		std::cout << "CC" << std::endl;
	}

	void MyCC()
	{
		std::cout << "MyCC" << std::endl;
	}
};

//  2. virutal ���� �Լ��� ���� ����[��ü�������α׷����� ������]
//	pure virtual     : Pet _ void Sound(Pet* pet) ��, �����, �� �������� �κ��� Pet. �����Ҹ�.
//  Pet Ŭ���� ��ü�� �߻����� �����̴�. 
// 
// 
//	abstract Ŭ����
//	vtable

class NewPet
{
public:
	virtual void Sound() = 0; // ���� ���� �Լ� -> NewPet�� ��ӹ޴� Dog, Cat Sound ������Ѷ�

};

// ���� ���� �Լ� pure virtual function
// ��� : �ݵ�� �������̵� �Ǿ�� �ϴ� �Լ�
// ���� ���� �Լ��� �����ϰ� �ִ� Ŭ���� �߻� Ŭ������� �����մϴ�.
// �߻� Ŭ������ �ݵ�� �ϳ� �̻��� ����� �ʿ��ϴ�.
// NewPet*
// NewPet np1;

// virtual ���� �Լ��� ����ϴ� Ŭ������ ��� �����ؼ� ����� �� �ִ�.
// ��� �Լ��� virtual �Լ� (���� �Լ�) �����ص� ������ ���� �ʳ���?

// virtual Ű���� �Է��ϴ� �ǹ� : �Է����� ������ Ű���尡 �۵����� �ʴ´�.

// �� c++ �⺻ �������� virtual�� ����Ǿ� ���� �ʴ°�?
// virtual ���������� vTable ������ �����մϴ�. vPtr;
// virtual �������� �ʾ��� �� : �ٷ� �ش� �Լ��� �����Ѵ�.

// �������� �ʿ��� ���� �����Լ��� ����ϴ� ���� ���� ����ȭ�� �ӵ��� ���� �ڵ尡 �� �� �ִ�.
// virtual ��� �Լ��� ����ص� ������ ���� ���δ�.
// �޸�, �ð��� ���ݾ� ������ ��ġ�� �־���.

// monster class - �߻� Ŭ������ ǥ���� �ѹ� �غ��ϴ�.
// reward class - ����ġ(int), ��ȭ(int)(money), ������(������ ��ȣ, (Item)), Quest Item
// Is-A, Has-A

// player <-> monster battle System
// battle class.  public : bool End() : �÷��̾ �׾��� ��, ���Ͱ� �׾��� �� , �÷��̾ ���� ���� ��..
// ���� �ݺ�(������ �� bool)
// 1. playerTurn.  (1)����, (2)���, (3)���� 
// NextTurn
// 2. MonsterTurn (1)����  

// ���Ͱ� ������ monster Class  Has, Is => Reward Drop Item()
// Player.GetItem(monster* m1); 



class NewDog : public NewPet
{
public:
	virtual void Sound()			   
	{
		std::cout << "�п�!" << std::endl;
	}

	virtual void Play()
	{
		std::cout << "���" << std::endl;
	}

	void DDD()
	{
		std::cout << "DDD" << std::endl;
	}
};

void lecture11()
{
	std::cout << "c++ casting ������" << std::endl;
	std::cout << "1. static_cast<type>" << std::endl;
	// �⺻ �ڷ����� ��ȯ, ������ �� ���� ��ȯ, ��� ������ Ŭ���� ��ȯ�� ���� �� �ִ�.

	double pi = 3.14; // 3
	int pi_int = (int)(3.14) - (0.14); // (int)3.14 => 3 - 0.14 = (int)2.xxxxxx =>2 
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int�� �� : " << pi_int << std::endl;
	std::cout << "pitint2�� �� : " << pi_int2 << std::endl;

	// ù��°, ���� �Լ��� �̿��Ͽ� ��ü�� ������ ǥ��
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();

	AA* aPtr3 = new CC();
	// static_cast ��Ӱ����� Ŭ������ ǥ��

	BB* bPtr1 = static_cast<BB*>(aPtr2);
	bPtr1->Show();
	bPtr1->MyBB();

	BB* bPtr2 = static_cast<BB*>(aPtr3); // aPtr3 BB* -> CC*
	bPtr2->Show();
	bPtr2->MyBB();

	// static_cast<Type> : ���� ��ü�� ������ Type���·� ����ȯ�� ��Ų��.

	// ��� ������ Ŭ������ ����ȯ dymamic_cast

	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if (cPtr1 != nullptr) // C��� NULL #define NULL 0. ������ ���� 0. ����Ű�� �ּҰ� ����. nullPtr
	{
		cPtr1->MyCC();
	}
	
	// const_cast : const Ű���带 ���Ĺ޴� ������ ������� ���ִ� ��ȯ.

	const int num = 10;

	int* nonConstNum = const_cast<int*>(&num);
	*nonConstNum = 12;
	std::cout << "num�� �� : " << num << std::endl;
	std::cout << "nonConstNum�� �� : " << *nonConstNum << std::endl;

	// reinterpret_cast

	// int 65 = 0 0 0 00001000(2)
	// char 65			01111111(2)	->A

	int num2 = 65; // int�� �ּҰ� char �ּҷ� ���� ����ȯ
	char* charPtr = reinterpret_cast<char*>(&num2);
	std::cout << "char ���·� ���� ����ȯ : " << *charPtr << std::endl;

    // �����Ͱ� ����ִ� ������ �Ű澲�� �ʰ� ������ ����ȯ.
	double* intPtrValue = reinterpret_cast<double*>(&num2);
	std::cout << "������ ������ �Ǽ��� ��ȯ : " << *intPtrValue << std::endl;


	NewPet* nP1 = new NewDog();
	nP1->Sound();
	
	NewDog* nD1 = dynamic_cast<NewDog*>(nP1);
	nD1->Play();
}


