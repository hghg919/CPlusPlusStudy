#include <iostream>
#include "GameObjects.h"

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


int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	Player player(100, 10);
	//player.Attack(); ���� ��� ����
	player.BeAttacked(10); // 100 - 10 = 90
	
	Item sword("�ҵ�", 10);
	Reward slimeReward(50, 1000, sword);
	Slime slime(50, 5, &slimeReward);

	int userInput = 0;
	int turn = 1;

	while (true) 
	{
		std::cout << "���� ���� ���� �� �� : " << turn << std::endl;
		std::cout << "1��. ����" << std::endl;
		std::cout << "2��. ??" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)
		{
			player.Attack(&slime);
		}

		std::cout << "�������� Turn" << std::endl;
		slime.Attack(&player);

		if (player.IsDead() || slime.IsDead())
		{
			break;
		}

		turn++;
	}

	// 1. ���� ���� ȭ��

	// 2. ���� ���� �÷���

	// Phase 1. Map Adventure (���� ���ƴٴϴ� ���) ( Step++ RandomEncount : SRand( 5 ~ 25)) 
	// Ư�� Ÿ���� ������ ���Ͷ� �������� ������ ���� �Լ��� ������.

	// Phase 2. Player vs Monster (���͸� �ϳ� �����, �� ���� ������ �ٸ� varitaion�� ���͸� ����) 

	// player ��ü ����	      Initialize
	// monster ��ü ����
	// monster Reward ��ü
	// Reward Item ��ü

	// while(true) { }
}