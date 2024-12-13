/*
*  �н� ��ǥ : C++�� ����ü �� ����ü ������ �����ϱ�
*  Pet Management Game
*  �ۼ���    : 2024-08-12
*  �ۼ���    : �赿��
*/

// typedef : ������ �ۼ��Ǵ� ������ Ÿ���� �ڿ� �̸����� �������� �����ִ� ��

// ����ü ������ ����ؼ� 
// cin �Լ��� ����ؼ� ���� �̸��� �޾ƿͼ� ������� ����ü�� �����ϴ� ��� (���̵� : ����)

// 1. �� �����ϱ�
// userInput 1�̶�� �����͸� ������ -> ���� �Ҵ����� ���ο� ���� �����մϴ�. (���̵� : ��)

// ���� �̸���, Happy(int), Hungry(int) ��ġ���� ���� 100�� �ִ�ġ�Դϴ�.
// Dog ����ü�� ����ϴ� �Լ��� ����� ������.

// �� ���α׷����� ��(Bird),  �����(Cat) �� �� ����ü�� �߰��ش޶�� �ǵ���� ������ϴ�.

// ���� ������ ����� ���õ� �Լ�
// ����̴¿�, ����ٷ��� �ϴµ� ������ Ȯ���� �ִ�.

#include "lectures.h"
#include <cstdio>

typedef struct Dog
{
	char name[30];
	// �ູ��
	int happy;
	// ���
	int hungry;
}Dog;

typedef struct Cat
{
	char name[30];
	int happy;
	int hungry;
	int curious;
};

// Play(Dog& dog);
// Happy + 10; Hungry -5;
// Pet {dog, cat, bird...} -> c++ Ŭ����

void Play(Dog& dog)
{
	dog.happy += 10;
	dog.hungry -= 5;
}

void Play(Cat& cat)
{
	srand(time(NULL));	// �õ带 ����� �ִ� �Լ�
	int randomNumber = rand() % 101; // 1 ~ 100 ���� ���� �޾ƿ�����  

	if (cat.curious < randomNumber)
	{
		std::cout << "����̰� ��⸦ �ź��߽��ϴ�." << std::endl;
		cat.hungry -= 5;
	}
	else 
	{
		cat.happy += 10;
		cat.hungry -= 5;
	}
}

// Feed(Dog& dog);
// Happy + 5 Hungry +10

void Feed(Dog& dog)
{
	dog.happy += 5;
	dog.hungry += 10;
}

void Feed(Cat& cat)
{
	cat.happy += 5;
	cat.hungry += 10;
}

// DayEnd(Dog& dog);
// Happy Hungry 

void DayEnd(Dog& dog, int& currentDay)
{
	dog.happy -= 10;
	dog.hungry -= 10;
	currentDay += 1;
}

void DayEnd(Cat& cat, int& currentDay)
{
	cat.happy -= 10;
	cat.hungry -= 10;
	currentDay += 1;
}

// ShowStatus(Dog& dog);

void ShowStatus(Dog& dog, int& currentDay)
{
	std::cout << "���� ��¥ : " << currentDay << "��" << std::endl;
	std::cout << "���� �̸� : " << dog.name << std::endl;
	std::cout << "�ູ��    : " << dog.happy << std::endl;
	std::cout << "���      : " << dog.hungry << std::endl;
}

void ShowStatus(Cat& cat, int& currentDay)
{
	std::cout << "���� ��¥ : " << currentDay << "��" << std::endl;
	std::cout << "������� �̸� : " << cat.name << std::endl;
	std::cout << "�ູ��    : " << cat.happy << std::endl;
	std::cout << "���      : " << cat.hungry << std::endl;
}
// ���� ���� ȭ��	 -> ���� �������ּ��� -> �̸��� �Է����ּ���

// ���� �÷��� ȭ�� -> 1���� -> ���� ���� ���¸� �����ְ� -> �÷��̾��� �Է�
// 1. ����ֱ� 2. �����ֱ� 

void makePet(Dog& dog)
{
	std::cout << "���� �̸��� �Է����ּ��� : ";
	std::cin >> dog.name;
	dog.happy = 100;
	dog.hungry = 100;
}

void makePet(Cat& cat)
{
	std::cout << "���� �̸��� �Է����ּ��� : ";
	std::cin >> cat.name;
	cat.happy = 100;
	cat.hungry = 100;
	cat.curious = 80;
}

void MainPlay(Dog& dog, int& currentDay)
{
	while (true)
	{
		system("cls"); // �ܼ� clear ��ɾ�
		ShowStatus(dog, currentDay);
		int userInput;
		std::cout << "�ൿ�� �������ּ���" << std::endl;
		std::cout << "1. ����ֱ�" << std::endl;
		std::cout << "2. �����ֱ�" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)
			Play(dog);
		else if (userInput == 2)
			Feed(dog);
		DayEnd(dog, currentDay);

		if (currentDay >= 10)
			break;
	}
	ShowStatus(dog, currentDay);
}

void MainPlay(Cat& cat, int& currentDay)
{
	while (true)
	{
		system("cls"); // �ܼ� clear ��ɾ�
		ShowStatus(cat, currentDay);
		int userInput;
		std::cout << "�ൿ�� �������ּ���" << std::endl;
		std::cout << "1. ����ֱ�" << std::endl;
		std::cout << "2. �����ֱ�" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)
			Play(cat);
		else if (userInput == 2)
			Feed(cat);
		DayEnd(cat, currentDay);

		if (currentDay >= 10)
			break;
	}
	ShowStatus(cat, currentDay);
}

void lecture3()
{
	// ����ü �����ϴ� ���
	Dog dog;
	Cat cat;

	int selectpet; // 1 : dog, 2 : cat
	std::cout << "���� �������ּ��� 1���� ��, 2���� ����� �Դϴ�." << std::endl;
	std::cin >> selectpet;
	switch (selectpet)
	{
		case 1:  makePet(dog);
			break;
		case 2 : makePet(cat);
			break;
		default : 
			std::cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << std::endl;
	}

	int currentDay = 1;

	if (selectpet == 1)
		MainPlay(dog, currentDay);
	else if (selectpet == 2)
		MainPlay(cat, currentDay);
	std::cout << "���� ����!" << std::endl;

	// ����ü ������
	Dog* dogPtr = &dog; // ù��° ���. ����ü �����͸� ������ �Ŀ� ������ �ּҿ����ڷ� �Ҵ��ϱ�.

	// ���� �Ҵ�	 (memory allocation : �޸� �Ҵ�) free ������ �߾���մϴ�.
	// C++�� ���� �Ҵ� : new ������ Ÿ��(); 
	// ���� �Ҵ� ���� : delete ������ �̸�;
	Dog* dogPtr2 = new Dog();
	// (*dogPtr2).name �� �ڵ带 ȭ��ǥ �����ڷ� ǥ���� �����޴�.
	strcpy_s(dogPtr2->name, 30, "ġ��");

	std::cout << "����ü �����Ͱ� ����Ű�� �̸� : " << dogPtr2->name;
	delete dogPtr2;
}

// Play, Feed, ShowStatus�Լ� ���� Dog, Cat
// Dog hungry, happy �������ִ� �Լ�. dog ��ü�� �Լ��� �����Ų��.
// dog.Play(); dog.Feed();

// ����
// 1. Dog ����ü�� ��� �Լ��� ǥ���� �� ������. => Dog, Cat ,Bird ����� ����ü�� �ϳ��� ǥ���ϴ� ����� ������?
// 2. ���ο� ����� �߰��ϱ� ���ؼ��� Dog, Cat, Bird �Լ��� �����ε� => Play(Pet& pet);
// 3. pet.Play(); ǥ���� �ϴ� ����� �� �ڿ�������.
// 4. struct ���� ���� ���� �ʱ�ȭ �Լ��� �ʿ��մϴ�. �ʱ�ȭ �Լ��� ���� ������ �ʰ� ���������� ���������� ������?
// Ŭ���� ������ ���ؼ� �ٷ�� �� ���Դϴ�.