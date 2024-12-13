/*
*  �н� ��ǥ : C��� ������ C++���� Ȱ���, ������(Reference)�� ���� ����
*  �ۼ���    : 2024-08-09
*  �ۼ���    : �赿��
*/

#include "lectures.h"
#include <cstdio>  // iostream
#include <cstring> // string

/*
*  C���� �����͸� ����ϴ� ����?
*  �Լ��� ����ϸ鼭 �Լ� �ȿ��� �����͸� �����Ϸ��� �����͸� ���ڷ� �Ѱ���� �߽��ϴ�.
*/

/*
*  �Լ��� ����� �� �����Ͱ� �ƴ� �����ڸ� ����ϸ� ���ڷ� &(�ּҿ����ڸ�) ������� ���� �� �ִ�.
*  �ּ� ����   : int*
*  ������ ���� : int& ������ �̸� = �����ϰ��� �ϴ� ����;
*  int a;
*  int&	AnotherA = a;
*/

void SwapInt(int* a, int* b)	 // �Լ��� �̿��ؼ� ���� �����ϱ� ���ؼ��� �����͸� ����ؾ��Ѵ�.
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// �Լ� �����ε� : C���� �Լ��� �̸����� �Լ��� �����մϴ�. �׷���, C++ �Լ��� �̸� + (�Ű�����, ����)
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void ChangeVal(int& p)
{
	// p�� ���� 10���� �����ϴ� �ڵ带 �ۼ��� ������
	p = 10;
}


int Function()  // int�� ��ȯ�ϴ� �Լ�.
{
	int a = 2;
	return a;
}

// �����ڸ� �����ϴ� �Լ�
// ������� �ʵ��� ���̴� ����.
int& Function2()
{
	int a = 2;
	return a;
}

int& Function3(int& a)
{
	a = 2;
	return a;
}

typedef struct Human
{
	char name[30];  // �̼���
	int age;		// 30
}Human;

// ������ ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ����� �ּ���.
// Human ����ü�� ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ����� �ּ���.
// 
// Human �����͸� �ִ� �Լ�.
void AddHumanInfo(Human& human)
{
    // cin �Լ��� �̿��ؼ� �̸� �޾ƿ��� 

	strcpy_s(human.name, 30, "�̼���");
	// cin �Լ��� �̿��ؼ� ���� �޾ƿ���
	human.age = 30;
}
void PrintHumanInfo(Human& human)
{
	std::cout << "�̸� : " << human.name << std::endl;
	std::cout << "���� : " << human.age << std::endl;
}


void lecture2()
{
	std::cout << "2�� " << std::endl;
	// ���� C��� ����Ʈ

	int num = 10; // num���� 10�̶�� ����, �ּ�
	int* numPtr = &num;  // ������(����);

	// C���� ������ �� C++�� �������� ���¸� ������� �ʾƵ� �۵��Ѵ�.(���ϴ�.)
	printf("�������� �ּ� %p\n", numPtr);

	std::cout << "�������� �ּ� : " << numPtr << std::endl;
	std::cout << "�����Ͱ� ����Ű�� �� : " << *numPtr << std::endl;

	// ������ �̸� ��Ģ
	//int number_of_people; // �ܾ�� �ܾ���̸� '_' ǥ���ϰ� �ֽ��ϴ�.
	//int NumberOfPeople;	  // ���� �� �� �빮�ڷ� ǥ���Ѵ�. 

	// �����ؾ��� ����. �� ����� ���� ȥ���ؼ� ���� �� ��
	// 1. int NumerOfMonster; ������ �̸� ��Ģ�� �ϳ��� �����ؼ� ���� ��
	// 2. int number_ofPeople; �� ����� ��� ���� �� ��

	int num1 = 1, num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1�� �� " << num1 << std::endl << "num2�� �� " << num2 << std::endl;

	// ������ ����� ��
	// ������ : ������ ����
	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1;  // AnotherA1�� a1�� �����̴�.

	std::cout << "AnotherA1�� �� " << AnotherA1 << std::endl;

	// a1 ���� �Ǵ°� �ƴѰ���?
	// -> Primitive type
	// ����ü�� ũ��� ����� �������̱� ������ �ۼ��ڿ� ���� ũ�Ⱑ �޶�����.
	// �����ڵ� ����������, �����ڰ� ����Ű�� �ּҸ� �ѹ� �����ϸ� 8����Ʈ(64��Ʈ �ý���) ������ ����ü�� �����ؼ� �� �� �ִ�.

	// �����ڿ� �����Ͱ� �ٸ� �κ�
	// �����ʹ� �ּҿ����ڸ� ���ڷ� �ް� �ؾ��Ѵ�. ����ڰ� �Լ��� �����Ϳ� ���� ���ص��� �־�� �Ѵ�. (C���)
	// �����ڴ� �ּҿ����ڸ� ���ڷ� �޳���? �ȹ޴´�. ����ڰ� �� ���� �����̴�. (C++���)

	int c_num2;
	std::cin >> c_num2;
	std::cout << "c_num2�� �� " << c_num2 << std::endl;

	// ������(Reference) �Լ����� ����ϴ� ���

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num1�� �� " << d_num1 << std::endl << "d_num2�� �� " << d_num2 << std::endl;

	// �����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �ؾ� �մϴ�.
	// �����ڴ� ������ �� ����� �ּҸ� �����ͼ� ���縦 �Ѵ�.
	int& AnotherDNum1 = d_num1;

	// int& Literal = 100; // �����ڴ� ���ͷ� ����� ����Ű�� ���Ѵ�.   
	const int& Literal = 100; // �����ڴ� const Ű���带 ���ؼ� ����� ����ų �� �ְ� �ȴ�.

	int p = 5;
	ChangeVal(p);
	std::cout << p << std::endl;

	// ������(���۷���)�� �����ϴ� �Լ�

	int p2 = 5;

	int tempA = Function();	// tempA Function�ȿ� �ִ� a�� ���� �����ؼ� �����Ѵ�.
	int tempB = Function3(p2);

	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�. �ڡ�

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	// int& anotherTemp = Function(); // 
	const int& anotherTemp = Function();
	// int& anotherTemp2 = Function2(); // �Ϻ� �����Ϸ����� ������ ������ �߻��մϴ�.

	// (1) �Լ����� ���� ������ ��  int a = Function();
	// int a = Function();   a = 2; 2��� ���� a�� �����Ѵ�. ���� ���簡 �̷������. ��� ����
	// int&	a = Function();  ������ Ÿ������ ���ͷ� ����� ����ų �� ����. �����Ͽ����� �߻��Ѵ�.
	// const int& a = Function(); �����ڰ� �����͸� ����Ű�� �ϰ� ������ const Ű���带 ����Ѵ�. 
	// ��, const ���� �޴� a �����ڴ� ���� ������ �Ұ����ϴ�.

	// (2) �Լ��� �����ڸ� ������ �� int& Function();
	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�. �ڡ�

	Human human;

	AddHumanInfo(human);
	PrintHumanInfo(human);
}