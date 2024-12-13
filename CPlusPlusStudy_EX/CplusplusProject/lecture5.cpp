#include "lectures.h"

/*
*  �н� ��ǥ : Ŭ����(��ü���� ���α׷���)�� Ư¡
*  �ۼ���    : 2024-08-14
*  �ۼ���    : �赿��
*/

// Ŭ���� ����
// Ŭ���� ������, �Լ� �����ε�

// ���α׷��Ӹ� �����ϴ� ���� Ŭ������ ���� �ִ� Ư¡�̴�.
// ���α׷��� �Ǽ��� ��õ������ ������ �� �ִ�.

// 1. ������   : ���α׷��Ӱ� �Ǽ��� �ʱ�ȭ���� �ʰ� �����͸� ����ϴ� ���� ��õ������ ���� ���� �����̴�.
// 2. �������� : ���������ڸ� ���ؼ� ���α׷��Ӱ� �����͸� �����ϰ� ������ �� �ִ� ����̴�. (����� ����� ���ؼ�)
// ��� ������ private���� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ� ������ ���·� ��� ������ ������ �����ϴ� ���� �ǹ��Ѵ�.
// ���� Ŭ������ �ۼ��ϱ� ���� �⺻ ���� : ��������(���м�), ĸ��ȭ
// 3. ĸ��ȭ  : �������� ó��޴� ĸ��. ĸ���� ��� �������� �� ������ ȥ�յǾ� �ִ� ���� ĸ���� �����ϰ� �ִ� ���Դϴ�.
// ĸ���� �� �� ������ �м��� �ؾ��մϴ�.
// �ڵ带 ĸ��ȭ ���׽��ϴ�. �ڵ带 �Լ��� ������ �߽��ϴ�.	�Լ��� �ڵ�� �ۼ��� �ؼ�, �� ����� �ʿ��� ����� �� �Լ��� ȣ�⸸ �ϸ� �ǰԲ� �ۼ��ϴ� ���Դϴ�.
// (1) �����(����)�� �� �Լ��� ������ �ϴ��� �� �ʿ䰡 ����.
// (2) �ۼ���(���α׷���) ���忡�� �ڵ带 �ۼ��ϴµ� �ʿ��� �Լ��� �׳� ȣ�⸸ �ϸ� �˴ϴ�. 
// Play(); �ູ��, ���, û�ᵵ  
// ��Ű�� ��ǰ�� ��������ϴ�. Play, Feed, Shower �ѹ��� ����Ǵ� ����� �Ѵٰ� �մϴ�.
// Package1(){Play(); Feed(); Shower(); }

class Date
{
private:
	int day;   // ���� �� �����غ���. 30, 31 
	int month; // 1 ~ 12
	int year;  // 2024 �ʱ�ȭ ��
public:
	// private�� �������� �ʰ� ��� ������ ����
	void ChangeDay(int x); // day�� �����ϴ� �Լ�
	void ChangeMonth(int x); // month�� �����ϴ� �Լ�
	void ChangeYear(int x);  // year�� �����ϴ� �Լ�
	void ChangeDate(int year, int month, int day);
	Date();
	Date(int _day, int _month, int _year);
	void ShowDate(); // ���� ��¥�� ����ϴ� �Լ�	
};

Date::Date() // ����Ʈ �������� ������
{
	day = 14;
	month = 8;
	year = 2024;
}

Date::Date(int _day, int _month, int _year)
{
	day = _day;	 // this->day = _day;
	this->month = _month;
	this->year = _year;
}

void Date::ChangeDay(int x)
{
	if (x > 31)
	{
		std::cout << "���� 31���� ���� �� �����ϴ�." << std::endl;
		std::cout << "���� �ش� ����� ������ �� �����ϴ�." << std::endl;
	    return;
	}

	day = x;
}

void Date::ChangeMonth(int x)
{
	month = x;
}

void Date::ChangeYear(int x)
{
	year = x;
}

void Date::ChangeDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::ShowDate()
{
	std::cout << "������ " << year << "�� " << month << "�� " << day << "���Դϴ�." << std::endl;
}

class SinivelCap
{
public:
	void Take()
	{
		std::cout << "�๰���� �����߽��ϴ�." << std::endl;
	}
};

class SneezeCap
{
public:
	void Take()
	{
		std::cout << "������� �����߽��ϴ�." << std::endl;
	}
};

class Capsule100
{
private:
	SinivelCap sc;
	SneezeCap sz;
public:
	void Take()
	{
		sc.Take();
		sz.Take();
	}
};

class Patient
{

public:
	void TakeCapsule(Capsule100& capsule)
	{
		capsule.Take();
	}
};

// Point (int x, int y) ��ǥ�� ����ϴ� ��ü�� �����غ�����.
// private, int x, inty
// ������ Point(x, y)

class Point
{
private:
	int x;
	int y;
public:
	Point();
	int GetX() const;
	int GetY() const;
	void ShowPoint() const;
};

Point::Point()
{
	std::cout << "x�� ��ǥ�� �Է� : ";
	std::cin >> x;
	std::cout << "y�� ��ǥ�� �Է� : ";
	std::cin >> y;
}

// const �Լ��� ���� ����
// (��ȯ��) �Լ��̸�() const;  �������� �ۼ��Ѵ�.
// const keyword ���Ĺ޴� �Լ��� ��� ������ ���� ������� ������ �����ϴ� Ű���� �Դϴ�.

int Point::GetX() const 
{
	return x;
}

int Point::GetY() const
{
	return y;
}

void Point::ShowPoint()	const
{
	std::printf("(%d,%d)\n", GetX(), GetY());	
	//std::cout << "(" << x << "," << y << ")" << std::endl;
}

// �簢�� Rectangle ��ü�� �����غ�����
// Point -> leftDown, upRight ��ǥ�� �ΰ� �����մϴ�.
// �簢���� ���̸� ���ϴ� �Լ�
// �簢���� ������ ����ϴ� �Լ� �����غ�����.
// leftDown, upRight�� ��ǥ�� �����ϴ� �Լ� �߰��غ��� �ǰڽ��ϴ�.

class Rectangle
{
private:
	Point leftDown;
	Point rightUp;
	int areaSize;
public:
	Rectangle();
	int CalculateArea();
	void ShowRectInfo();
};

// ��� �̴ϼȶ������� �̿��� ��� �ʱ�ȭ ���
// ��� �̴ϼȶ������� ��������� ����� ��ü�� ������ ȣ���� Ȱ���ϴ� ����Դϴ�.

Rectangle::Rectangle():leftDown(),rightUp()
{
	areaSize = CalculateArea();
};

int Rectangle::CalculateArea()
{
	int row = rightUp.GetX() - leftDown.GetX(); // ���� ����
	int col = rightUp.GetY() - leftDown.GetY(); // ���� ����

	std::cout << "�簢���� ���� : " << row * col << std::endl;
	return row * col;
}

void Rectangle::ShowRectInfo()
{
	leftDown.ShowPoint();
	rightUp.ShowPoint();
	std::cout << "�簢���� ���� : " << areaSize << std::endl;
}

// Circle Ŭ������ ���� �����غ�����
// ������ radius,  const float PI = 3.14f , ���� ��ǥ Point
// ���� ȣ�� ���̿�, ���� ���̸� �����ڷ� �����ϰ�
// showCircleInfo(); ���� ��ǥ, ������ ����, ȣ�� ����, ���̸� ����ϴ� �Լ��� ��������.


void lecture5()
{
	std::cout << "5��" << std::endl;
	Date date1; // ����Ʈ�����ڷ� �ʱ�ȭ
	date1.ShowDate();
	Date date2 = Date(15, 8, 2024);
	// 2024.8.16
	date2.ChangeDay(16);
	date2.ShowDate();
	Date date3 = Date(15, 8, 2024);
	date3.ChangeDate(2025, 8, 15);
	date3.ChangeMonth(4);
	date3.ChangeDay(35);
	date3.ShowDate();

	// �Լ��� �̿��ؼ� ����� ���� �����ϴ� �Ͱ�
	// ��� ������ ���� �����ؼ� �����ϴ� �Ͱ� ũ�� �������� ���� �ʳ���?

	Patient pa; // ȯ�� �Ѹ��� �����մϴ�.
	Capsule100 capsule;
	pa.TakeCapsule(capsule);

	// �簢�� Ŭ���� ȣ��
	Rectangle rect1;
	rect1.ShowRectInfo();
}