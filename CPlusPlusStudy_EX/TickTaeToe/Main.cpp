#include <iostream>
#include "StdExample.cpp"
#include "TickTaeToe.h"

// Ŭ���� Ű����. �̸�. ����� �ؾ��ϸ� ����� ����.
// ��ɰ� ��� ���� ���� private, public, protected
// ������, �Ҹ���	 - ���������, ���� ���� - ���� ����
// ��� : virtual <-> �Ϲ� �Լ�
// ������ ǥ�� - Ŭ������ Ȯ�强�� �������ش�.  
// virtual �Լ�(); �ڽ� �Լ�(�̸��� ���� �Լ�) override;
// c++ ����ȯ. �θ�->�ڽ� ����ȯ : dynamic_cast. if���� �Բ� ����ؼ� ������ ����ȯ ����
// template �Ϲ�ȭ �ڵ� �ۼ��ϴ� ��

template <typename T>
class SingleTon
{
private:
	static T* singleton;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleton()
	{
		if (nullptr == singleton)
		{
			singleton = new T; 
		}
		return singleton;
	}

	static void Release()
	{
		delete singleton;
		singleton = nullptr;
	}
};

template<typename T>
T* SingleTon<T>::singleton = nullptr;

// GameManager Ŭ������ SingleTon ��ӹ޴´�. 
// SingleTon Ŭ������ GamemanagerŬ������ ���������� ����ϰ� �ִ�.
class GameManager : public SingleTon<GameManager>
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

		// while �ݺ���. inputnum .. 1 ���� ����. 2. ���� ���� 3. ���� ����..

		while (true)
		{
			//system("cls");

			int userInput = 0;
			std::cout << "1. ���� ����" << std::endl;
			std::cout << "2. ���� ����" << std::endl;
			std::cin >> userInput;

			if (userInput == 1)
			{
				GameStart();
			}
			else if (userInput == 2)
			{
				GameEnd();
			}
			else
			{
				std::cout << "�߸��� �Է�, �ٽ� �Է����ּ���." << std::endl;
			}
		}
	}

	void GameStart()
	{
		std::cout << "���� ����!" << std::endl;

		// Ŭ���� ���� �̸�.h ���� �̸�.cpp 
		// Board board;   board.GamePlay();

		board b;
		b.GamePlay();
	}
	void GameEnd()
	{
		exit(0);
	}
};

int main(void)
{
	//std::cout << "Std �Լ� ����" << std::endl;
	//SampleSTD* sample = new SampleSTD;
	//sample->SetWidthExample();
	//sample->IsDigitExampe();
	//delete sample;

	std::cout << "���� ȭ��" << std::endl;
	
	GameManager* gm = GameManager::GetSingleton();
	gm->MainMenu();
	
}