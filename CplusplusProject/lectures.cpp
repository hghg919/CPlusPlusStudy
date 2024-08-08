/*
* �н���ǥ : c++ ��� �н�. c���� ��� ������ �����غ���
* �ۼ���   : 2024-08-08
* �ۼ���   : ������
*/

/*
* hello world ��� ���ִ� �Լ� <- ����� �Լ� : <stdio.h> printf, scanf
* hello world ��� ���ִ� �Լ� <- ����� �Լ� : <iostream> cout, cin
* cout : ��� �Լ�
* ���� : std::cout << "hello world" << std::endl; = "\n"
* cin : �Է� �Լ�
* ���� : std::cin >> num;
*/

/*
* 1. ���� : int, char, float, double
* 2. �ݺ���, ���ǹ� : for, while, if, switch
* 3. ������(����) : int*, char*, &num, &al, *num, *al
*/

/*
* namespace �̸� ������ �����ΰ�?
*/

/*
* �Լ�, ������ �ۼ��� �ϴµ�, �ٸ� ����� �� �ڵ带 ������ ���鼭 �ߺ��� �̸��� ���� �Լ��� ����� Ȯ���� �������ϴ�.
* C++ �������� �̸� �����ϱ� ���ؼ� namespace��� ������ �����մϴ�.
* ���� namespce (�̱ݰ���)�̸� {} : �λ�-�赿�� ����-�赿��
*/

/*
* ���� ���� ������ '::'
* ���� : �̸�����:: ���� �Ǵ� �Լ�;
* �̸� �����ȿ� �ִ� ���� �Ǵ� �Լ��� ����� �� �ִ�.
* ���࿡ �̸� ������ �ʹ� ��, ���ϰ� ���� ����� ������?
* using Ű����
* using TODATISTHRUSDAY::num;
*/

#include "lectures.h"
#include "cstring"

namespace TODATISTHRUSDAY
{
	int num;
	int num2;
}

using TODATISTHRUSDAY::num; // num �̸��� �̸� �������� ����Ѵ�.
// using namespace TODATISTHRUSDAY; // ��� ���� �Ǵ� �Լ��� �̸��������� �����´�.
// �� �������ȿ��� ����ϴ� ��� ������ �Ǵ� �Լ��� using namespace �̸��� ����ض�.
// ���� : �̸��� �� namespace�� ���� �Է¾��ص� �ȴ�.
// ���� : namespace �ȿ� ������ �Լ��� ��������, �ٸ��Լ� �Ǵ� ������ �̸��� ��ġ�� ��찡 �����.

// ��� ��õ��
// using namespace�� �̿��ؼ� ��� ������ �����ϴ� ����� �����ض�.
// �ʿ��� �Լ��� �ʿ��� ������ �����ؼ� ����ض�.

// namespace using ����
// std::cout -> cout ����� �� �ְԲ� using���� ����ؼ� ����� ������

namespace JHJ
{
	int age;
	char name[30];

	void printfMyName()
	{
		std::cout << "�� �̸��� " << name << "�Դϴ�.\n";
		std::cout << "���̴� " << age << "�Դϴ�.\n";
	}
}

using JHJ::printfMyName;

namespace CPP
{
	void Sasmple()
	{
		std::cout << "Sample!" << std::endl;
	}
}


namespace CPP2
{
	void Sasmple()
	{
		std::cout << "Sample2!" << std::endl;
	}
}

void Sample()
{
	
}



void lecture1()
{
	std::cout << "Hello World!\n";
	std::cout << "Hello World!" << std::endl;

	CPP::Sasmple();
	CPP2::Sasmple();

	// �̸��� ������ :: namespace�̱���
	// std �̸������Դϴ�. : c++ ǥ�� ���̺귯���� �̸� ����

	strcpy_s(JHJ::name ,30, "������");
	JHJ::printfMyName();

	int a1;
	// scanf_s(%d, &a1); :: c���� �Է� �޴� ���
	std::cout << "�Է� ���� ���� �Է��� �ּ��� : " << std::endl;
	std::cin >> a1;
	std::cout << "�Է¹��� �� " << a1;

	// int�� ���� LuckyNumber �������ּ��� = 5.
	// c++ ��� �Լ� " ���� ���ڸ� ���߾� ������" << std::endl;
	// int UserIput ������ ���ݴϴ�.
	// C++ �Է� �Լ� Userinput�� �����͸� �޾��ּ���

	//
	int LuckyNumber = 5;
	std::cout << "���� ���ڸ� ���߾� ������ : " << std::endl;
	int UserIput;

	while (true)
	{
		std::cin >> UserIput;
		if (LuckyNumber == UserIput)
		{
			std::cout << "������ ���߾����ϴ�." << std::endl;
			break;
		}
		else if (LuckyNumber != UserIput)
		{
			std::cout << "�����Դϴ�. �ٽ��Է��ϼ���." << std::endl;
		}
	}
}