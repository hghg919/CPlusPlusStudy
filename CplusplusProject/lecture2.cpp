/*
* �н���ǥ : c��� ������ c++���� Ȱ���, ������(regerence)�� ���� ����
* �ۼ���   : 2024-08-09
* �ۼ���   : ������
*/

#include "lectures.h"
#include <cstdio>  // iostream
#include <cstring> // string

/*
* c���� �����͸� ����ϴ� ����?
* �Լ��� ����ϸ鼭 �Լ� �ȿ��� �����͸� �����Ϸ��� �����͸� ���ڷ� �Ѱ���� �߽��ϴ�.
*/

/*
* �Լ��� ����Ҷ� �����Ͱ� �ƴ� �����ڸ� ����ϸ� ���ڷ� &(�ּҿ�����) ������� ���� �� �ִ�.
* �ּ� ����   : int*
* ������ ���� : int& ������ �̸� = �����ϰ��� �ϴ� ����;
* int a;
* int& AnoterA = a;
*/

void SwapInt(int* a, int* b) // �Լ��� �̿��ؼ� ���� �����ϱ� ���ؼ��� �����͸� ����ؾ� �Ѵ�.
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// �Լ� �����ε� : c���� �Լ��� �̸����� �Լ��� �����մϴ�. �׷��� c++ �Լ��� �̸� + (�Ű�����, ����)
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void ChangeVal(int& p)
{
	// p�� ���� 10���� �����ϴ� �ڵ带 �ۼ��غ�����.
	p = 10;
}

int Function1() // int�� ��ȯ�ϴ� �Լ�
{
	int a = 2;
	return a;
}

// �����ڸ� �����ϴ� �Լ�
// ������� ����
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
	char name[30]; // �̼���
	int age;       // 30   
}Human;

// ������ ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ����� �ּ���.
// Human ����ü�� ���۷����� ��ȯ�ϴ� �Լ��� �ϳ� ����� �ּ���.
//
// Human �����͸� �ִ� �Լ�.
Human& AddHumanInfo(Human& human)
{
	// cin �Լ��� �̿��ؼ� �������� ������ �Է��ϰ� ����
	strcpy_s(human.name, 30, "�̼���");
	// cin �Լ��� �̿��ؼ� ���� �޾ƿ���
	human.age = 30;
	return human;
}
void PrintHumanInfo(Human& human)
{
	std::cout << "�̸� : " << human.name << std::endl;
	std::cout << "���� : " << human.age << std::endl;
}

void lecture2()
{
	std::cout << "2��" << std::endl;
	// ���� c��� ����Ʈ

	int num = 10; // num���� 10�̶�� ����, �ּ�
	int* numPtr = &num; // ������(����);

	// c���� �������� c++�� �������� ���¸� ������� �ʾƵ� �۵��Ѵ�.(���ϴ�.)
	printf("�������� �ּ� : %p\n", numPtr); // ����������?

	std::cout << "�������� �ּ� : " << numPtr << std::endl;
	std::cout << "�����Ͱ� ����Ű�� �� : " << *numPtr << std::endl;

	// ������ �̸� ��Ģ
	int number_of_people; // �ܾ�� �ܾ� ���̸� '_" ǥ���ϰ� �ֽ��ϴ�.
	int NumberOfPeople;   // ���� �� �� �빮�ڷ� ǥ���Ѵ�.

	// �����ؾ� �� ����. �� ����� ���� ȥ���ؼ� ���� �� ��
	// 1. int NumberOfMonster; ������ �̸� ��Ģ�� �ϳ��� �����ؼ� ���� ��
	// 2. int number_ofPeople; �� ����� ��� ���� �� ��

	int num1 = 1, num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1�� �� : " << num1 << std::endl << "num2�� �� : " << num2 << std::endl;

	// ������ ����� ��
	// ������ : ������ ����
	int a1 = 10;
	int* a1Ptr = &a1;
	int& AnotherA1 = a1; // AnotherA1�� a1�� �����̴�.

	std::cout << "AnotherA1�� �� : " << AnotherA1 << std::endl;

	// a1 ���� �Ǵ°� �ƴѰ���?
	// -> Primitive type
	// ����ü�� ũ��� ����� �������̱� ������ �ۼ��ڿ� ���� ũ�Ⱑ �޶�����.
	// �����ڵ� ����������, �����ڰ� ����Ű�� �ּҸ� �ѹ� �����ϸ� 8����Ʈ(64��Ʈ �ý���) ������ ����ü�� �����ؼ� �� �� �ִ�.

	// �����ڿ� �����Ͱ� �ٸ� �κ�
	// �����ʹ� �ּҿ����ڸ� ���ڷ� �ް� �ؾ��Ѵ�. ����ڰ� �Լ��� �����Ϳ� ���� ���ص��� �־�� �Ѵ�. (c���)
	// �����ڴ� �ּҿ����ڸ� ���ڷ� �޳���? �ȹ޴´�. ����ڰ� �� ���� �����̴�. (c++���)

	// int c_num2;
	// std::cin >> c_num2;
	// std::cout << "c_num2�� �� : " << c_num2 << std::endl;

	// ������(Reference) �Լ����� ����ϴ� ���

	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);
	std::cout << "d_num1�� �� : " << d_num1 << std::endl << "d_num2�� �� : " << d_num2 << std::endl;

	// �����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �ؾ� �Ѵ�.
	// �����ڴ� ������ �� ����� �ּҸ� �����ͼ� ���縦 �Ѵ�.
	int& AnotheDNnum1 = d_num1;

	// int& Literal = 100; // �����ڴ� ���ͷ� ����� ����Ű�� ���Ѵ�.
	const int& Literal = 100; // �����ڴ� const Ű���带 ���ؼ� ����� ����ų �� �ְ� �ȴ�.

	int p = 5;
	ChangeVal(p);
	std::cout << "ChangeVal�� �� : " << p << std::endl;
	
	// ������(���۷���)�� �����ϴ� �Լ�

	int p2 = 5;

	int tempA = Function1(); // tempA Function1�ȿ� �ִ� a�� ���� �����ؼ� �����Ѵ�.
	int tempB = Function3(p2);

	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�. �ڡ�

	std::cout << tempA << std::endl;
	std::cout << tempB << std::endl;

	// int& anotherTemp = Function1(); // 
	const int& anotherTemp = Function1();
	// int& anotherTemp2 = Function2(); // �Ϻ� �����Ϸ����� ������ ������ �߻��Ѵ�.

	// (1) �Լ����� ���� ������ ��int a = Function();
	// int a = Function(); a = 2; 2��� ���� a�� �����Ѵ�. ���� ���簡 �̷������. ��� ����
	// int& a = Function(); ������ Ÿ������ ���ͷ� ����� ����ų�� ����. �����Ͽ����� �߻��Ѵ�.
	// const int& a = Function(); �����ڰ� ���ͷ��� ����Ű�� �ϰ� ������ constŰ���带 ����Ѵ�
	// ��, const ���� �޴� a �����ڴ� ���� ������ �Ұ����ϴ�.

	// (2) �Լ��� �����ڸ� ������ �� int& Function();
	// �ڡ� ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�. �ڡ�

	Human human;

	AddHumanInfo(human);
	PrintHumanInfo(human);
}