#include <iostream>

class SingleTon
{
	GameManager* singleton;
public:
	SingleTon();

};

class GameManager
{
private:
	// ���
public:
	GameManager() {}
	~GameManager() {}
	// ��� : ���� ȭ�� ���, ���� ����, ���� ����
	void MainMenu()
	{
		std::cout << "���� �޴� ����" << std::endl;
	}

	while (true)
	{
		int userInput = 0;
		std::cin >> userInput;
		std::cout << "1. ���� ����" << std:endl;
		std::cout << "2. ���� ����" << std:endl;
	}

	void GameStart()
	{
		std::cout << "���ӽ���!" << std:;endl;

		// Ŭ���� ���� �̸�.h ���� �̸�.cpp
		// Board board; board.GamePlay();
	}
};

int main(void)
{
	std::cout << "����ȭ��" << std::endl;
	GameManager gm;
	gm.MainMenu();

	// Ŭ����
}