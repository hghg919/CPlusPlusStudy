#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

// ƽ���� ����
// ������    3x3 �������� �������Ѵ�. -> Ŭ������ ǥ�� class Board -> 2���� �迭 

// ���1 : �÷��̾ ���� �׸���.   X �Ǵ� O insert_X insert_O 
// ���2 : x_Win,  o_Win
// �¸����� :������ �ϼ�,  ������ �ϼ�, �밢��(���� ������ �Ʒ�), �밢��(������ ���� �Ʒ�)

// ����ϸ� ���� �Լ���
// std::cin >> input;   �������� �ƴ��� �Ǻ�, std::isdigit()
// std::setw() ������ ���̸� �����ϰ� ���߾� �ִ� �Լ�
// �����͸� Ŭ������ ǥ���� �� -> iterator
// ���ڿ��� Ŭ������ ǥ���� �� -> string

class board
{
	// bMap ����ִ� �����Ͱ� �������� �ƴ��� üũ �ϴ� �Լ�
	bool isNum(std::string& s);

private:
	int size;            // ũ�Ⱑ 3
	std::string** bMap; // 2���� �迭  [����][����]

public:
	board();

	void GamePlay();

	// 2���� �迭�� ������ �ִ� �Լ�
	bool insert_x(int pos);
	bool insert_o(int pos);
	// 2���� �迭 �ȿ� �����Ͱ� �ִ��� ������ üũ �ϴ� �Լ�
	std::string get_item(int pos) const;
	std::string get_item(int col, int row) const;

	// �����ǿ� ��� �ִ� ���� ������ִ� �Լ�
	void Print();

	bool x_win();
	bool o_win();

	int GetSize() const
	{ return size; }

};

// std::cout �Լ��� �̿��ؼ� Ŭ������ ����ϰڴ�.
std::ostream& operator<< (std::ostream& out, const board& b);


