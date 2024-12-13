#include "lectures.h"


/*
*  template Ű���� - �Ϲ�ȭ �ڵ�
*  �Լ� ���ø�
*  Ŭ���� ���ø�
*/

/*
*  template�� ����ϴ°�?
*  �� ���� ���ϴ� �Լ�(int �� return)
*  �Լ� �����ε� : ���ڱ��� �����ؼ� �Լ��� �����Ѵ�.
*  �ѹ��� int, double, float.... ǥ���ϴ� ����� ������? template
*/

/*
*  template ��� ���
*  �Լ� �̸�<������ Ÿ��>( )
*/

/*
*   ��� ����
*  	�Լ� ���ø� : template <typename T> �Լ� ����. �Լ��� ����µ� ����ϴ� ���ø��� �ǹ��Ѵ�.
*   ���ø� �Լ� : Add<int>(3,5);
*/

/*
*  �Լ� ���ø��� ������µ�, ���� ���ø� �Լ��� �����Ǵ°�?
*  Add<int>(3,5);
*  int Add<int>(int num1, int num2)
* {
*	return num1 + num2;
* }
*  �Լ� ���ø��� �����ϸ� ���ʿ��� �޸𸮸� ����ϴ� �� �ƴմϱ�?
*  -> Add<int>(3,5); �ڵ尡 �ۼ��Ǿ��� �� (������ ������) int Add<int> ������ �ȴ�.
*  -> ������ ������ T Ÿ�Կ�	�ش��ϴ� �Լ��� ����ٸ� ��ǻ�� �ӵ��� ���������� �ʽ��ϱ�?
*  -> ������ <-> ��Ÿ�� ���� : ���α׷� ���� ���� �Լ��� ���� ����� ���� ������ ���α׷� �ӵ��� ����X 
*/

 /*
 *  type T, �� T��� �� ����ؾ� �Ǵ°�?
 *  -> �ٸ� ���� ����ص� ������ �����ϴ�.
 */

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

/*
*  �Լ� ���ø��� ����ȭ(Specializtion)
*/

template <>
char Add(char num1, char num2)
{
	std::cout << num1 << num2 << std::endl;
	return 0;
}

template <typename P>
P Minus(P num1, P num2)
{
	std::cout << "num1 ���� num2�� �� �� : ";
	return num1 - num2;
}

template <class C>
C Mulitply(C num1, C num2)
{
	return num1 * num2;
}

template <typename T>
T Divide(T num1, T num2)
{
	return num1 / num2;
}

// ���� ���� : template <class T> ��õ���� �ʴ´�.
// class Ŭ���� �̸� << Ű����� ȥ���ϴ� ��찡 �־ template Ű����� �ַ� ����Ѵ�.

// Ÿ���� ������ �ΰ� �̻��� ���

template <typename T1, typename T2>
void ShowData(double a, double b)
{
	std::cout << "a�� T1���� ����ȭ�� �� : " << (T1)a << std::endl;
	std::cout << "b�� T2�� ����ȭ�� �� : " << (T2)b << std::endl;	
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

double Add(double num1, double num2)
{
	return num1 + num2;
}

// Max �� (a , b) ū ���� �������ִ� �Լ�
// ���� ��  aaa < bb : ���̰� �� �� ���� �� ũ��.(������)	   - strlen(char*) -> ���� ��
// a93 < b94  : ���� ���� ���ڰ� �� ū���� ũ�ٰ� �Ѵ�.(������)  - strcom -> ũ�� ��


// Max

template <typename T>
T Max(T a, T b)
{
	return a < b ? b : a; // ������ a�� ������ �Լ�

	// �������� �ڵ�� ��Ȯ�� ��ġ�Ѵ�.
	//if (a < b)
	//	return b;
	//else if (a > b)
	//	return a;

}

template <>
const char* Max<const char*>(const char* a, const char* b)
{
	return strlen(a) > strlen(b) ? a : b;
}

// Non-type ���ø� : type�� �ƴ� ���ø�

template <typename T, int val>
T AddValue(T const& curValue)
{
	return curValue + val;
}

const int EVENTMONEY = 10000; // int
const int EVENTEXP = 100;     // double

void lecture12()
{
	std::cout << "int Add(a,b) ��� : " << Add(3, 5) << std::endl;
	std::cout << "double Add(a,b) ��� : " << Add(3.4, 5.9) << std::endl;
	std::cout << "T Add<int>(a,b) ��� : " << Add<int>(3, 5) << std::endl;
	std::cout << "float Add<float>(a,b) ��� : " << Add<float>(3.4, 5.9) << std::endl;
	std::cout << Add<char>(32, 32) << std::endl;
	std::cout << Minus<int>(10, 5) << std::endl;

	ShowData<float, int>(3.2, 4.5);

	std::cout << "float Divide<float>(a,b) ��� : " << Divide<float>(3.4, 2.3) << std::endl;

	std::cout << "Add ���ø� �Լ��� ����ȭ " << std::endl;
	int num = Add<char>(97, 98);

	std::cout << "�� �Լ� ��� ����" << std::endl;
	std::cout << Max<double>(3.2, 5.9) << std::endl;
	// �Լ� ���ø��� <T Ÿ���� �������� �ʾƵ�> �����Ϸ��� ������ -> ����� ��ȯ ���� ���. �߸� ��ȯ ���� ���
	std::cout << Max(3.2, 5.4)  << std::endl;
	std::cout << Max("aaa", "bb") << std::endl;

	float myExp = 1.1f;
	int myMoney = 500;
	std::cout << "�̺�Ʈ �� ����ġ : " << AddValue<float, EVENTEXP>(myExp) << std::endl;
	std::cout << "�̺�Ʈ �� �� : " << AddValue<int, EVENTMONEY>(myMoney) << std::endl;
}