// ����ϸ� ���� �Լ���
// std::cin >> input;   �������� �ƴ��� �Ǻ�, std::isdigit()
// std::setw() ������ ���̸� �����ϰ� ���߾� �ִ� �Լ�
// �����͸� Ŭ������ ǥ���� �� -> iterator
// ���ڿ��� Ŭ������ ǥ���� �� -> string

#include <iostream>
#include <cstdlib>
#include <iomanip> 

// std

class SampleSTD
{
public:
	SampleSTD() {}

	// �ܼ��� ��� ���� ����� �Լ�  (������ ����)
	// setw(����) : ���� ��ŭ ũ�⸦ ä���� �����ش�.
	// std::left : ���� ����
	// std::right : ������ ����
	// std::setfill : ��ĭ�� (���ڷ�)�� ä���ش�.

	void SetWidthExample()
	{
		int a = 4235;
		int b = 12345;
		std::cout << std::setfill('=') << std::left << std::setw(20) << a << std::endl;
		std::cout << std::setfill('#') << std::right << std::setw(20) << b << std::endl;
		

		int waitnum;
		std::cout << "�� ������ �����Ϸ��� �ƹ� ���ڸ� �Է����ּ���." << std::endl;
		std::cin >> waitnum;
		system("cls");
	}

	void IsDigitExampe()
	{
	    // �������� ���ڰ� �ƴϸ� false,  true ��ȯ���ִ� �Լ� 

		int a = 10;

		if (std::isdigit(a))
		{
			std::cout << "���Դϴ�." << std::endl;
		}		
	}
};

// ������ 
// *ptr  : ������.
// ptr++ : (�ּ� + 1)
// ++ptr
class Iterator
{
private:
	int* ptr;
public:
	Iterator(int* p) : ptr(p) {}

	// ������ �����ε�

	Iterator* operator++()
	{
		++ptr;
		return this;
	}
	Iterator* operator++(int)
	{
		Iterator* temp = this;
		++(*this);
		return temp;
	}

};

// Iterator Ŭ���� std  
// �ڷᱸ�� class
// Ŭ���� �ȿ� ������(iterator Ŭ����) 

//  for�ݺ���

// for(int i =0;  i <  arr.Length; i++) { } 
// Iterator s;     s.begin();   s.End() ;
// while(s.End() != nullptr)