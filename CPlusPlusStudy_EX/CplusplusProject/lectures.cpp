/*
*  �н� ��ǥ : C++ ��� �н�. C��� ���� ��� ������ �����غ���.
*  �ۼ���    : 2024-08-08
*  �ۼ���    : �赿��
*/

/*
*   Hello World ��� ���ִ� �Լ� <- ����� �Լ� : <stdio.h>  printf, scanf
*   Hello World ��� ���ִ� �Լ� <- ����� �Լ� : <iostream> cout , cin
*   cout : ��� �Լ�
*   ����  std::cout << "Hello World!" << std::endl;  
*   cin  : �Է� �Լ�
*   int num;
*   ����  std::cin >> num;		 
*/

/*
*  1. std::cout << " " �� ���¸� �����ϱ� ���ؼ�. �տ��� ���� ������� �� 
*  'std::' ������ �����غ���.
*  namespace �̸� ������ �����ΰ�? � ���ǵ� ��ü�� ��� �ҼӵǾ� �ִ��� �˷��ִ� ���Դϴ�.
*  std�� c++ standard Library�� ��ϵ� �Լ����Դϴ�. C++ ǥ�� ���̺귯���� ��� �Լ��� ���ǵ� �̸� ����
*/

/*
*  �Լ�, ������ �ۼ��� �ϴµ�, �ٸ� ����� �� �ڵ带 ������ ���鼭 �ߺ��� �̸��� ���� �Լ��� ����� Ȯ���� �������ϴ�.
*  C++ �������� �̸� �����ϱ� ���ؼ� namespace��� ������ �����մϴ�.
*  ���� namespace (�̸�����)�̸� { } : �λ�-�赿�� ����-�赿��
*/

/*
*  ���� ���� ������ '::'
*  ���� : �̸� ����:: ���� �Ǵ� �Լ�;
*  �̸� �����ȿ� �ִ� ���� �Ǵ� �Լ��� ����� �� �ִ�.
*  ���࿡ �̸� ������ �ʹ� ��, ���ϰ� ���� ����� ������?
*  using Ű����
*  using TODAYISTHRUSDAY::num;
*/


/*
*  1. ����          : int, char, float, double
*  2. �ݺ���, ���ǹ� : for�ݺ���, while�ݺ���, if, switch ���ǹ�
*  3. ������(����)  : int*, char*,  &num ,  &a1, *num, *a1
*/

#include "lectures.h"
#include "cstring"

namespace TODAYISTHRUSDAY
{
	int num;
	int num2;
}

using TODAYISTHRUSDAY::num;	     // num �̸��� �̸� �������� ����Ѵ�.
// using namespace TODAYISTHRUSDAY; // ��� ���� �Ǵ� �Լ��� �̸� �������� �����´�.
// �� ������ �ȿ��� ����ϴ� ��� ���� �Ǵ� �Լ��� using namespace �̸��� ����ض�.
// ���� : �̸��� �� namespace�� ���� �Է¾��ص� �ȴ�.
// ���� : namespace �ȿ� ������ �Լ��� ���� ����, �ٸ� �Լ� �Ǵ� ������ �̸��� ��ġ�� ��찡 ����ϴ�.

// ��� ��õ��
// using namespace�� �̿��ؼ� ��� ������ �����ϴ� ����� �����ض�.
// �ʿ��� �Լ��� �ʿ��� ������ �����ؼ� ����ض�

// namespace using ����

// std::cout -> cout ����� �� �ְԲ� using���� ����ؼ� ����� ������


namespace CPP
{
	void Sample()
	{
		std::cout << "Sample!" << std::endl;
	}
}

namespace CPP2
{
	void Sample()
	{
		std::cout << "Sample2!" << std::endl;
	}
}

using std::cout;
using std::endl;

namespace KDH
{
    // ����
	int age;
	char name[30];
	// �Լ�
	void PrintMyName()
	{
		cout << "�� �̸��� " << name <<"�Դϴ�.\n";
		cout << "���̴� " << age << "�Դϴ�.\n";
	}
}


// std::in ���ӽ����̽� ����غ���
// ���ڸ��߱� ������ �����غ���.


void lecture1()
{
	cout << "Hello World!\n";
	cout << "Hello World!" << endl;

	CPP::Sample();
	CPP2::Sample();

	// �̸��� ������ :: namespace�̱���
	// std �̸������Դϴ�. : c++ ǥ�� ���̺귯���� �̸� ���� 
	strcpy_s(KDH::name, 30, "�赿��");
	KDH::PrintMyName();

	int a1;
	//scanf_s("%d", &a1); :: C���� �Է� �޴� ���
	std::cout << "�Է� ���� ���� �Է��� �ּ��� : ";
	std::cin >> a1;
	std::cout << "�Է¹��� �� " << a1;

	// int�� ���� LuckyNumber �������ּ��� = 5.
	int LuckyNumber = 5;
	// c++ ��� �Լ� "���� ���ڸ� ���߾� ������" << std::endl;
	std::cout << "���� ���ڸ� ���߾� ������" << std::endl;
	// int UserInput ������ ���ݴϴ�.
	int UserInput;

	

	// 132 ~ 135 while �ݺ������� ���� ������ �����ϴ� �ڵ�
	// if�Լ��� ����ؼ� LuckyNumber�� UserInput ������ 
	// c++ ��� �Լ� "������ ���߾����ϴ�" ���� ��ɵ� �߰����ּ���
	// if�Լ��� ����ؼ� �ٸ��ٸ�
	// c++ ��� �Լ� "�����Դϴ�. �ٽ� �Է��ϼ���"
	while (true)
	{
		// �Է��� ��� �޾ƾ� �մϴ�.
		std::cin >> UserInput;
		if (LuckyNumber == UserInput)
		{
			std::cout << "������ ���߾����ϴ�." << std::endl;
			break;
		}
		else if (LuckyNumber != UserInput)
		{
			std::cout << "�����Դϴ�. �ٽ� �Է��ϼ���" << std::endl;
		}

	}

}

