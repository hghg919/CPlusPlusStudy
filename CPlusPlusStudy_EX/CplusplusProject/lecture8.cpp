#include "lectures.h"
#include <cstring>
/*
*  �н� ��ǥ : c++ ��� �⺻ ������ ���� ����
*  �ۼ���    : 2024-08-22
*  �ۼ���    : �赿��
*/

/*
*  ���(inheritance) : �θ�� ���� ������ �̾�޴� ��
*  �θ�(Ŭ����) <-> �ڽ�(Ŭ����) ����Ѵ� : private ��� ���� ����. public �Լ��� �����ؼ� ��� ������ ����Ͽ���.  
*  �θ� ������ �ִ� ����, �Լ��� �ڽ��� ����Ѵ�. �θ� �����ϰ� �ִ� ��� ���� ����� �� �־�����?
*/

/*
*  ��ӿ��� ���� ���Ǵ� ��� ���� 
*  ����� ���ִ� Ŭ����   vs    ����� �޴� Ŭ����
*  �θ�(parent)          vs     �ڽ�(child)
*  ���(base)            vs     ����,�Ļ�(derived)
*  ����(super)           vs     ����(sub)
*  ����                  vs     ����
*/

/*
*  ����� �⺻ ��� : �θ� Ŭ����(��� �ϴ� Ŭ����)�� �ߺ����� �ʰ� ����� �� �ִ� �����̴�.
*  Ŭ������ ������ �Ҹ���
*/

/*
*  ���� ������
*  public    : public ���� ���� ū ��� ����� ������ ����Ѵ�. private �̿��� ��� ������ ����Ѵ�. 
*  private   : �ڽ� Ŭ���� �̿��� ��� Ŭ������ ������ ���´�. �ڽ� Ŭ������ ���ٵ� �����Ѵ�.
*  protected : �⺻������ private�� �뵵�� ������, Ŭ������ ��ӵǾ��� �� �ڽ� Ŭ������ ������ ����ϴ� ����
*  c++ Ư���� ��� ���� : ���� ���, ���� ���	������ ���� �����ڷ� �ذ��ϱ� ���ؼ� private, protected ����� �����Ѵ�.
*/

/*
*  ����� ������ ��� : public ���, private ���, protected ���
*  public ��� : (�θ� Ŭ����)private �̿��� ��� ������ ����Ѵ�. �θ� ���� �ִ� ���������ڿ� �����ϰ� �����´�.
*  protected ��� : (�θ� Ŭ����)private �̿��� ��� ������ protected �������� �����Ѵ�.
*  private ��� : ��� ���� �����ڸ� private�� �����Ѵ�. �����ϴ� ������ �������� ��� ���.
*/

/*
*  �ڡڡڡڡ� IS-A�� �ش��ϴ� ��쿡�� ����� �ϼ���.
*  ����� ���� �ؾ��ϴ°�?
*  IS-A	:   A is B �ΰ�? A�� B�ΰ���? Child(Parent + �߰������� Child ������ ���)�� Parent �ΰ���?
*  EBook�� å�Դϴ�. å�� Ŭ���� ����. EBook å�� ������ ��ӹ��� �� �ִ�.
*  ���簢���� �簢���ΰ���?  
*  HAS-A : A�� B�� �����ϰ� �ִ�.  Police(�ڽ�)�� Gun(�θ�)�� �����ϰ� �ִ�.
*  Police (����) 
*  Gun(��)
*/

class Book
{
private:
	char* title;
	int price;
public:
	Book(const char* title, int price)			
	{
		this->price = price;   //: price(price) ó���� ����.
		this->title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
	}
	~Book()
	{
		delete[] title;
	}

	void ShowBookInfo()	
	{
		std::cout << "���� : " << title << std::endl;
		std::cout << "���� : " << price << std::endl;
	}
};

class EBook : public Book
{
private:
	char* DRMkey;
public:
	EBook(const char* title, int price, const char* key) : Book(title, price)
	{
		DRMkey = new char[strlen(key) + 1];
		strcpy_s(DRMkey, strlen(key) + 1, key);
	}

	void ShowEBookInfo() 
	{
		ShowBookInfo();
		std::cout << "DRMKey�� ��" << "wasdfwefiajed" << std::endl;
	}

	~EBook()
	{
		delete[] DRMkey;
	}
};

class Gun
{
protected :
	int bulletCount;
public:
	Gun(int bullet)
	{
		bulletCount = bullet;
	}
	void UseGun()
	{
		bulletCount--;
	}
	int ShowRemainBullet()
	{
		return bulletCount;
	}
};

class Police// IS - A,  Has - A  ������ ��(����(Has-A)�� �ϰ� �ֽ��ϴ�)�Դϱ�?
{
private:
	Gun* gun;
public:
	Police()
	{
		gun = new Gun(10);
	}
	void Shot()
	{
		gun->UseGun();
		std::cout << "�߻�!" << std::endl;
		std::cout << "���� ��ź �� : " << gun->ShowRemainBullet() << std::endl;
	}
};

class Police2 : public Gun
{
	 // ���� �߿� ���� �������� ������ ���� �� �ֳ���? -> ������ �� ���ְ� ���� �� �� �ִ�.
	 // Has-A  Police ��ü�� Gun�� ����ؾ����� ���ƾ����� �Ǵ��� �� GunŬ���� �������ص� �Ǵ� ��쵵 �������ϴ� case

	 // bat*
};

class base
{
private:
	int num1;
protected:
	int num3;
public:
	base(int value, int value3) : num1(value), num3(value3) {}     // ��� �̴ϼȶ�����
	base()
	{
		std::cout << "base() ������ ȣ��!" << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	~base()
	{
		std::cout << "base() �Ҹ��� ȣ��!" << std::endl;
	}
};

class derived : public base
{
private:
	int num2;
public:
	derived(int value) : num2(value) {}
	derived()
	{
		std::cout << "derived() ������ ȣ��!" << std::endl;
	}
	void dPrint()
	{
		num3 = 3;
		num2 = 2;
		std::cout << "drived()" << num2 << " " << num3 << std::endl;
	}
	~derived()
	{
		std::cout << "dervied() �Ҹ��� ȣ��!" << std::endl;
	}
};

class parent
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
};

class child : protected parent
{
	 // num3�� ���� �����ڰ� protected 
};


// ���� ����
// ���簢��(Square) �簢��(Rectangle)

class Rectangle
{
private:
	int width, height;
public:
	Rectangle(int width, int height) : width(width), height(height) {}
	void ShowAreaInfo()
	{
		std::cout << "���� : " << width * height << std::endl;
	}
};

class square : public Rectangle
{
public:
	square(int size) : Rectangle(size, size) {}
};
// ������ �ʱ�ȭ
// Rectangle(int width, int height) : width(width), height(height)
// public : ShowAreaInfo ( width * height)
// 
// class Square : public Rectangle{} // ���簢�� ������ ������ ���̰� ���� �簢�� 



void lecture8()
{
	std::cout << "8�� !" << std::endl;
	base b1(1,3);
	b1.Print();
	derived d1;	  // �ڽ� Ŭ������ ������ �� �θ� Ŭ������ ���� �����ؾ� �Ѵ�.
	d1.Print();
	d1.dPrint();

	// ���� Ǯ��

	Rectangle re(2, 4);
	re.ShowAreaInfo();
	square sq(5);
	sq.ShowAreaInfo();

	// protected ���
	// ��ü ������ ���� ���� ��Ģ�� ��Ű���� ������ �����̴�.
	parent p1;
	p1.num3 = 10;
	child c1;
	//c1.num3 = 100;

	Book book("C++ ����", 5000);
	book.ShowBookInfo();

	// ����å
	EBook ebook("C++ ���� ����", 10000,  "wwwssssddd");
	ebook.ShowEBookInfo();
	// ����
	Police police;
	police.Shot();

	// Pet ���� ���α׷�.   ������� ǥ��      Dog, Cat, Bird -> Pet ����� ���
	// Dog,Cat,Bird �����ִ� ��� player Pet�̶� ��ȣ�ۿ��� �Ѵ�.	playerController

}