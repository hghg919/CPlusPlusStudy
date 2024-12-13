#include "lectures.h"
/*
*  �н� ��ǥ : ��������ڿ� ���� ���� �� �Ҹ���
*  �ۼ���    : 2024-08-16
*  �ۼ���    : �赿��
*/

// 1. ���� Ŭ������ ����� ���ô�.
// ��Ÿũ����Ʈ �����ϴ� ������ ��ü�� ǥ���غ���.

// 2. Ŭ���� �Ҹ��ڿ� ���� �н�
// new Ű���尡 ���Ե� �����ڸ� �������� ��, new Ű����� ������ ������ �޸� ������ ���ϴ� ������
// Ŭ������ �Ҹ��ϴ� ������ ȣ��Ǵ� �Ҹ��ڸ� �����ؼ� delete Ű����� �޸𸮸� �������־���.

// 3. ��������ڸ� �̿��ؼ��� Ŭ������ �����Ѵ�.
// �ڱ��ڽ� Ŭ������ �����ؼ� �ٸ� Ŭ����(�ν��Ͻ�)�� �����ϴ� �������Դϴ�.

// 4. ���� ����(Shallow copy) vs ���� ����(deep copy)
// ���� ���� : ���縦 �� �� �ּҸ� �״�� �����ͼ� ���� �ּҸ� ����Ű�� ���� ��� 
// (�ּҸ� ������ �� �ٸ� �ּҰ� ���� �޸� ������ �Ǹ� ���� �ּҸ� ����Ű�� ������ �߻��Ѵ�.)
// ���� ���� : ������ �� �ּ��� ��쿡 �ش� ������ �����Ҵ����� �����ؼ� ���ο� ������ �����ϴ� ���
// 
// ���� ���縦 ���� ����? �ϳ��� �޸𸮷� �� �̻��� ǥ���� �� �ִ�. �޸𸮸� ������ �� ������ ���� �� �ִ�. 

class Marine
{
private:
	int hp;
	int attackPower;
	int posX;
	int posY;
	bool isDead;
	char* name;
public:
	Marine(int x, int y); // �跰�� ��ġ���� ������ �����ǰ���.
	Marine(int x, int y, const char* marineName);	 // Ŭ���� ����� name�� �ܺ��� marineName�� �����ϴ� ��  const �����ؼ�, marineName ������ �ʴ� �ٴ� ���� ���
	Marine(const Marine& m1); // ��������� ȣ�� ���
	~Marine();            // �Ҹ��� : �Ҹ��� �� ȣ��˴ϴ�.
	void Move(int x, int y);
	int Attack();
	void Damaged(int damage);
	void ShowStatus();
};

Marine::Marine(int x, int y)
{
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(int x, int y, const char* marineName)
{
	// char name[30]; 30�̻��� �̸� ũ�⸦ ������ �� ����. (������ ���� ���) 
    // ������ ���� ��� : �����ϰ��� �ϴ� ���ڿ��� ���� ��ŭ �޸� ������ �Ҵ��ؼ� �����Ѵ�.
	name = new char[strlen(marineName) + 1];  // strlen�� null������ ���ϱ� ������ +1 ������Ѵ�. 
	strcpy_s(name, strlen(marineName) + 1, marineName);
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(const Marine& m1)
{
	name = new char[strlen(m1.name) + 1];  // strlen�� null������ ���ϱ� ������ +1 ������Ѵ�. 
	strcpy_s(name, strlen(m1.name) + 1, m1.name);
	hp = m1.hp;
	attackPower = m1.attackPower;
	posX = m1.posX;
	posY = m1.posY;
	isDead = m1.isDead;
}

Marine::~Marine()
{
	std::cout << name << "�� �Ҹ��� ȣ��!" << std::endl;
 	delete[] name;

	// delete[] : �迭�� ��ü �޸� �����϶�.
}

void Marine::Move(int x, int y)
{
   // x,y��ǥ�� �Ű����� x,y�� ����
	posX = x;
	posY = y;
}

int Marine::Attack()
{
	return attackPower;
}

void Marine::Damaged(int damage)
{
	// hp���� damage ���ְ�, 
	hp -= damage;
	// ���� hp <= 0 isDead  true����
	if (hp <= 0)
		isDead = true;
}

void Marine::ShowStatus()
{
	std::cout << "** ���� ���� **" << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ġ : " << posX << "," << posY << std::endl;
	std::cout << "���ݷ� : " << attackPower << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl;
}

void lecture6()
{
	// ����1�� �����غ���.
	Marine marine1(1,2, "Marine1");
	marine1.ShowStatus();

	// ����2�� ����
	Marine marine2(5, 10, "Marine2");
	marine2.ShowStatus();

	std::cout << "����1�� ����2�� ����" << std::endl;
	marine2.Damaged(marine1.Attack());
	marine2.ShowStatus();

	// ���� ������ ������ �ѹ��� �����غ���. -> �迭
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine3");
	marines[1] = new Marine(3, 5, "Marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];

	// int�� �� ����
	int num = 10;
	int num2 = num;
	int num3(num);   // num3(num) num ������ ���� num3�� ����

	std::cout << num3 << std::endl;

	// Marine�� ��������� ȣ��(����Ʈ ���������)
	Marine marine3(0, 0, "����1");
	Marine marine4 = marine3;
	Marine marine5(marine3);

	// ����Ʈ ����������� �Ѱ� : Ŭ������ ��� ������ ������ ������ �ּҸ� ����Ű�� ��쿡 ���� ����� �����Ѵ�. 
	// => ���� ����� ���ؼ� ���� �޸� �Ҹ� �� �ּҸ� ã�� �� ���� ������ �߻��Ѵ�.

	marine5.ShowStatus();

	// marine3 �Ҹ��� ȣ�� -> marine 4 �Ҹ��� ȣ�� -> marine 5 �Ҹ��� ȣ��
}


// 1. ���� Ŭ���� ����
// 2. �����ڿ� �Ҹ��� (ü�°� �̸��� �ʱ�ȭ�ϰ�, �Ҹ��� �� �����Ҵ� �� �ּҸ� �����ϰ� ���� ��
// 3. ��������ڸ� ��������� �ۼ��ؼ�, ���� ���簡 �ƴ� ���� ���� ������� ������ �� �ְ� �ڵ� ������ �� 

// �ٸ� Ŭ������ ���̿� ������ �����غ�����.

class Zealot
{
private:
	int hp;
	char* name;
public:
	Zealot();
	Zealot(Zealot& z1);
	~Zealot();
};

Zealot::Zealot()
{
	hp = 100;
	std::cout << "������ ȣ��!" << std::endl;
}

Zealot::Zealot(Zealot& z1)
{
	std::cout << "��������� ȣ��!" << std::endl;
}

Zealot::~Zealot()
{
	std::cout << "�Ҹ��� ȣ��!" << std::endl;
}



void lecture6_2()
{
	 // Ŭ���� 2���̻� ���� �� �����ڿ� �Ҹ��ڸ� ���� ȣ����Ѻ�����

	Zealot z1;
	Zealot z2(z1);  // ��������� ȣ�� ���
	//Zealot z2 = z1;	//Zealot z2 = z1 -> Zealot z2(z1) �����Ϸ��� �ٲپ ����

	Zealot z3;
	z3 = z1;
}

