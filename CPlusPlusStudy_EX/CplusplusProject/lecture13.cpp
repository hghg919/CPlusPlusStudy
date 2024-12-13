#include "lectures.h"

/*
*  template Ű����
*  �ڵ带 ���� Ʋ�� ����� ��.(������ Ÿ��)
*/
class One;

template <typename T>
void Plus(T a, T b)
{
	std::cout << a << "+" << b << " : " << a + b << std::endl;
}

template <typename T1, typename T2>
void SomeFunc(T1 a, T2 b) {}

template <typename T1>
void SomeFunc(T1 a, int b) {}

class One
{
public:
	void operator+(const One& one)
	{
		std::cout << " a + b�� ������ �����ε� ���" << std::endl;
	}
};

template <typename T>
class Point
{
private:
	T posX;
	T posY;
public:
	Point() {}
	Point(T x, T y) : posX(x), posY(y) {}
	void Show()
	{
		std::cout << "pos X : " << posX << std::endl;
		std::cout << "pos Y : " << posY << std::endl;
	}
};

/*
*  Ŭ���� ���ø��� �Լ� ���ø��� ������
* - �Լ� ���ø��� �Լ��� ȣ�� �ÿ� <type> ������� ������ (����)�� ���ؼ� Ÿ���� �����Ѵ�.
* - ���������� ���ø� �Լ��� �����Ѵ�. �Ϲ� �Լ��� �����Ѵٸ�, �Ϲ� �Լ��� ���� ������ �ȴ�. 
* - Ŭ���� ���ø��� ���������� Ÿ���� �������ִ� ����� ����.
*/


// non type teplate<typename T, int VAL>

template <typename T, int N>
class MyArray // �츮�� ���� ����� �迭
{
private:
	T data[N]; // size ũ�� ��ŭ �迭�� �����ϰڴ�.

public:
	MyArray() {}
	MyArray(T(&arr)[N]) // �迭�� �����ؼ� �����ϴ� ������
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}

	T* GetArray() { return data; }
	int Size() { return N; }

	void ShowInfo()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << ",";
		}
		std::cout << std::endl;
	}

	// ������ �����ε� [] 
};

/*
*  C, C++ << �𸮾� ����, Ŭ���� ����� ��. ��ü ���� ���α׷���.
*  �߻�ȭ : ���ǿ� �������� �ʴ� �͵� �ڵ�� ǥ���ϴ� ��
*  ���� ����, ĸ��ȭ => ���α׷��� �Ǽ��� ����.
*  ������ : Play();  dynamic_cast<Dog*>
*  STL << Standard Template Library 
*  - �������� ������ �ȴ�. 
*  - Template : ������ Ÿ���� ��� �����ϴ� �Ϲ�ȭ ���α׷���.
*  Vector<Item>. ���� �迭 << �ڷ� ����
*/

// �÷��̾� <-> ���� ��Ʋ �ý���  (player - monster)
// GameManager Ŭ������ ������.  
// ��� : ��Ʋ ����. ���� �ý���. ����. ����. ����. �ҷ�����.

//GameManager GM;	 // ����, ����
//GameManager GM2; //	����, ����
// Ŭ������ �Ѱ��� �����ؾ� �ϴ� ����ȭ - �̱��� ����
// template Ŭ������ ǥ���ϸ� -> �̱��� ������ �ʿ��� Ŭ������ ��� ����� �� �ִ�.
// ��� + ���ø� Ŭ����

template <typename T>
class SingleTon
{
    // �ݵ�� ��ü�� �ϳ��� �־�� �Ѵ�.
private:
	static T* singleTon;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleTon)
		{
			singleTon = new T;
		}
		return singleTon;
	}

	static void Release()
	{
		delete singleTon;
		singleTon == nullptr;
	}
};

template <typename T>
T* SingleTon<T>::singleTon = nullptr;

class GameManager : public SingleTon<GameManager>
{
private:
	int score;

public:
	GameManager() {}
	~GameManager() {}
	GameManager(int s) : score(s) {}
	int GetScore(){ return score; }
	void SetScore(int val) { score = val; }

	// ���� ����, ���� ����, ���� ����...
	void GameStart()
	{
		std::cout << "���� ����" << std::endl;
	}

	void GameEnd()
	{
		std::cout << "���� ����" << std::endl;
	}

	void GameSave()
	{
		std::cout << "���� ����" << std::endl;
	}
};

// GameData. �÷��� Ÿ��. ���� �������� é��. 

class GameData : public SingleTon<GameData>
{
private:
	int areaInfo; // 1�� 1������....
public:
	GameData() {}

	int GetAreaInfo() { return areaInfo; }
	void SetAreaInfo(int area) { areaInfo = area; }
};


void lecture13()
{
	Point<int> p1(1, 2);
	p1.Show();
	Point<float> p2(1.1, 2.2);
	p2.Show();

	// �迭
	int arrNum[3] = { 1, 5, 9 };
	MyArray<int, 3> mArray(arrNum);
	std::cout << "MyArray Ŭ������ ũ�� : " << mArray.Size() << std::endl;
	mArray.ShowInfo();

	double arrDouble[5] = { 1.1, 2.2, 3.3, 4.4 ,5.5 };
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "GameManager Ŭ����" << std::endl;

	GameManager* gm = GameManager::GetSingleTon();
	gm->SetScore(100);
	GameManager* gm2 = GameManager::GetSingleTon();
	gm2->SetScore(150);
	std::cout << gm->GetScore() << std::endl;

    // ���� ����
	gm->GameStart();
	// ���� �޴�

	// ���� �÷���

	// ����
	gm->GameEnd();

	GameData* gameData = GameData::GetSingleTon();
	gameData->SetAreaInfo(10);
	std::cout << gameData->GetAreaInfo();

	GameData* gameData2 = GameData::GetSingleTon();
	std::cout << gameData2->GetAreaInfo();
}