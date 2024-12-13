#include "lectures.h"

/*
*  �н� ��ǥ : ������ �����ε�
*  ������    : 2024-08-19
*  �ۼ���    : �赿��
*/

/*
*  #include <iostream>
*  istream(�Է� ��Ʈ��), ostream(��� ��Ʈ��)
*  �ܼ� â�� ������� �����Ͽ����ϴ�.
*  cout <<  :  c���� ��Ʈ�����ڷ� ���Ǿ��µ�, cout << ��Ʈ ����� ������ �ֳ���? 
*  cin  >>	:  c���� ��Ʈ�����ڷ� ���Ǿ��µ�, cin  >> ��Ʈ ����� ������ �ֳ���?
*/

/*
*  ����ü, Ŭ���� : ����� ���� �ڷ���
*  Ŭ������ Ŭ���� ���̿� ��������ڰ� ����� �����Ѱ�?
*  ���� -> �ش��ϴ� �ǿ����ڰ� �����ϴ�.
*  �ذ� : �ش��ϴ� �����ڸ� ������ָ� �ȴ�.	=> ������ �����ε����� Ŭ������ ���� �����ϰڴ�.
*/


/*
*  ������ �����ε�	: �⺻ �����ڵ�( +,-,*,/,[], <<, >>)���� ����ڰ� Ŭ������ ���� �����ϴ� ���̴�.
*  ���� : (��ȯ��) (Ű����)(������)() 
*  ���� : void operator+();
*/

/*
*  ���� �Լ� �����ε� 
*  - ��� �Լ��� ���� �����ε� :   ��ü.operator+(�ǿ�����) :   ��ü + �ǿ����� ������ �̷���� �ֽ��ϴ�.
*  - ������ �������� ��ü�� �ݵ�� ���ʿ� �־�� �մϴ�.
*  - ������ 
*   p1 + 10;
*   10 + p1;
*  - ���� �Լ� �����ε��� operator+(�ǿ�����, �ǿ�����) �ǿ����� + �ǿ����� ������ ��ü�� �ڿ� ��ġ�ص� �������� ����� ����մϴ�.
*  �ǿ����� + �ǿ����� = operator+(�ǿ�����, �ǿ�����)
*/

/*
*  frined �Լ�
*  Ŭ������ ��� �Լ��� �ƴϸ鼭 �ش� Ŭ������ private �����͸� ������ �� ����ϴ� �Լ��Դϴ�.
*  Ŭ������ ������ ������, �� Ŭ���� �ȿ� �ִ� �����͸� ����ϰ� �;��� �� ����ϴ� Ű����.
*  ���� : private, public -> private�� �̿��ؼ� �ܺο��� ������ ���ϰ� �ϱ� ���ؼ� ���� ���� �����ϴ� ����.
*  ���� : ������ �����ε��� ����ؼ� �������� �Լ��� ���� �� �ִ�. 
*  ��� : ������ �����ε� �̿ܿ� friend Ű���带 ����ϴ� ���� �����ϸ� �˴ϴ�.
*/

/*
*  ���� ������ �����ε� : ���� ������
*  ++ : num +1;
*  -- : num -1;
*  ++num : ���� ���� ���� 
*  num++ : ���� ���� ����
*/


class Point
{
private:
	int posX, posY;
public:
	Point() {}	           // ����Ʈ ������
	Point(int x, int y)	   // ������ �����ε�
	{
		posX = x;
		posY = y;
	}
	void ShowPosition()
	{
		std::cout << "posX : " << posX << ",posY :" << posY << std::endl;
	}

	Point operator+(Point& ref)
	{
		return Point(posX + ref.posX, posY + ref.posY);
	}

	Point operator-(Point& ref)
	{
		return Point(posX - ref.posX, posY - ref.posY);
	}

	Point operator+(int value)
	{
		return Point(posX + value, posY + value);
	}

	friend Point operator+(int num, Point ref);	   // ���� �Լ� ������ �����ε�

	Point operator++()   // ���� ���� ������  ++P1;
	{
		posX += 1;
		posY += 1;
		return *this;	 // �ڱ� �ڽ��� ��ü�� ��ȯ�Ѵ�.
	}

	Point operator++(int) // ���� ���� ������  P1++;
	{
		Point temp(*this); // ���� ������ : ���� ����� �����Ͱ� �̵��Ѵ�.
		posX += 1;
		posY += 1;
		return temp;
	}
};

Point operator+(int num, Point ref) // �ǿ����� + �ǿ�����
{
	ref.posX += num;
	ref.posY += num;
	return ref;
}

// �̸��� ������ ���ԵǾ� �ִ� Ŭ������ ����̴ϴ�.
// Math m1 + Eng e1 =  ���� ���� : m1 , ���� ���� : e1 	   std::cout << m1.score << e1.score

class Eng; // Eng Ŭ������ �����Ѵ�. ����Ѵ�.
class Math
{
	char name[10];
	int score;

public:
	Math() {}; // ����Ʈ ������ : �����ڸ� ���� �����ϸ� ����Ʈ �����ڰ� �ڵ����� �������� �ʱ� ������ ��������� ������.
	Math(const char* name, int score)    // Math m1("����", 100);	 Read Only
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}

	friend int Add(Math m1, Eng e1);
};

class Eng
{
	char name[10];
	int score;

public:
	Eng() {};
	Eng(const char* name, int score)    
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}

	friend int Add(Math m1, Eng e1);
};

int Add(Math m1, Eng e1)
{
	return m1.score + e1.score;
}

// <iostream>   istream ostream

/* ��� �Լ��� ������ �����ε� ����
*  ostream& operator<<(std::ostream& out, const int& val)
* {
*	  printf("%d", val);
*     return out; 
* }
* 
*  ostream& operator<<( const double& val);
* 
*  ostream& operator<<(std::ostream& out, const char* val)
* {
*	 printf("%s", val);
* }
* 
*  ostream& operator<< (std::ostream& out)
* {
*     printf('\n);
* 	  return out;
* }
*/

/*
*  istream& operator>>(std::istream& in, int& val)
*   {
*		int some;
*      	scanf(val, some); 
*		return in;
*   }
*/

// c��� int => printf("%d", num);



void lecture7()
{
	std::cout << "7��" <<" �н�" << std::endl;
	// std::cout << "7��" std::cout
	Point p1(1, 1);
	Point p2(2, 3);
	Point result = p1 + p2;	  // �����ڿ� ��ġ�ϴ� "+"�����ڰ� �����ϴ�.
	// Point p1 + Point p2 => p1.operatr+(Point& p2);
	Point minus = p1 - p2;
	// p1- p2 => p1.operator-(p2);

	p1.ShowPosition();	   // (1,1)
	p2.ShowPosition();	   // (2,3)
	result.ShowPosition(); // (3,4)
	minus.ShowPosition();  // (-1, -2)

	Point plusWithNum = p1 + 10; // (p1.posX + 10, p1.posY + 10) (11,11);
	// p1.operator+(int value = 10);
	plusWithNum.ShowPosition();

	Point NumPluspoint = 10 + p1;
	// (INT + Point) 10 + P1  => Point operator+(int num, Point p1);
	// 10.operator+(Point& p1);
	NumPluspoint.ShowPosition();

	Point p3(3, 3);
	++p3;
	p3.ShowPosition();
	Point p4(4, 4);
	p4++;
	p4.ShowPosition();
	
	//system("cls");
	std::cout << "���� ���� Ǯ�� " << std::endl;

	Math m1("����1", 95), m2("����2", 70);
	Eng e1("����1", 80), e2("����2", 65);

	std::cout << "�л� 1�� ���� + ���� ���� : " << Add(m1, e1) << std::endl;
	std::cout << "�л� 2�� ���� + ���� ���� : " << Add(m2, e2) << std::endl;

	// ���࿡ ������ �����ε� ������ ���������� �ʴ´ٸ�?
	// Add(m1, e1)

	
}