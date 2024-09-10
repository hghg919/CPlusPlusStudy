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
	// 멤버
public:
	GameManager() {}
	~GameManager() {}
	// 기능 : 게임 화면 출력, 게임 시작, 게임 종료
	void MainMenu()
	{
		std::cout << "메인 메뉴 시작" << std::endl;
	}

	while (true)
	{
		int userInput = 0;
		std::cin >> userInput;
		std::cout << "1. 게임 시작" << std:endl;
		std::cout << "2. 게임 종료" << std:endl;
	}

	void GameStart()
	{
		std::cout << "게임시작!" << std:;endl;

		// 클래스 게임 이름.h 게임 이름.cpp
		// Board board; board.GamePlay();
	}
};

int main(void)
{
	std::cout << "메인화면" << std::endl;
	GameManager gm;
	gm.MainMenu();

	// 클래스
}