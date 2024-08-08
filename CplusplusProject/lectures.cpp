/*
* 학습목표 : c++ 언어 학습. c언어에서 배운 내용을 복습해본다
* 작성일   : 2024-08-08
* 작성자   : 정현준
*/

/*
* hello world 출력 해주는 함수 <- 입출력 함수 : <stdio.h> printf, scanf
* hello world 출력 해주는 함수 <- 입출력 함수 : <iostream> cout, cin
* cout : 출력 함수
* 사용법 : std::cout << "hello world" << std::endl; = "\n"
* cin : 입력 함수
* 사용법 : std::cin >> num;
*/

/*
* 1. 변수 : int, char, float, double
* 2. 반복문, 조건문 : for, while, if, switch
* 3. 포인터(변수) : int*, char*, &num, &al, *num, *al
*/

/*
* namespace 이름 공간이 무엇인가?
*/

/*
* 함수, 변수를 작성을 하는데, 다른 사람이 쓴 코드를 가져다 쓰면서 중복된 이름을 가진 함수를 사용할 확률이 높아집니다.
* C++ 문법에서 이를 구분하기 위해서 namespace라는 문법을 제공합니다.
* 사용법 namespce (이금공간)이름 {} : 부산-김동훈 서울-김동훈
*/

/*
* 범위 지정 연산자 '::'
* 사용법 : 이름공간:: 변수 또는 함수;
* 이름 공간안에 있는 변수 또는 함수를 사용할 수 있다.
* 만약에 이름 공간이 너무 길어서, 편리하게 쓰는 방법이 없을까?
* using 키워드
* using TODATISTHRUSDAY::num;
*/

#include "lectures.h"
#include "cstring"

namespace TODATISTHRUSDAY
{
	int num;
	int num2;
}

using TODATISTHRUSDAY::num; // num 이름만 이름 공간에서 사용한다.
// using namespace TODATISTHRUSDAY; // 모든 변수 또는 함수를 이름공간에서 가져온다.
// 이 페이지안에서 사용하는 모드 변수는 또는 함수는 using namespace 이름을 사용해라.
// 장점 : 이름이 긴 namespace를 굳이 입력안해도 된다.
// 단점 : namespace 안에 변수와 함수가 많을수록, 다른함수 또는 변수와 이름이 겹치는 경우가 생긴다.

// 사용 추천안
// using namespace를 이용해서 모든 변수를 참조하는 방신은 지양해라.
// 필요한 함수만 필요한 변수만 지정해서 사용해라.

// namespace using 예제
// std::cout -> cout 사용할 수 있게끔 using문을 사용해서 만들어 보세요

namespace JHJ
{
	int age;
	char name[30];

	void printfMyName()
	{
		std::cout << "제 이름은 " << name << "입니다.\n";
		std::cout << "나이는 " << age << "입니다.\n";
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

	// 이름이 나오면 :: namespace이구나
	// std 이름공간입니다. : c++ 표준 라이브러리의 이름 공간

	strcpy_s(JHJ::name ,30, "정현준");
	JHJ::printfMyName();

	int a1;
	// scanf_s(%d, &a1); :: c언어에서 입력 받는 방법
	std::cout << "입력 받을 수를 입력해 주세요 : " << std::endl;
	std::cin >> a1;
	std::cout << "입력받은 수 " << a1;

	// int형 변수 LuckyNumber 선언해주세요 = 5.
	// c++ 출력 함수 " 나의 숫자를 맞추어 보세요" << std::endl;
	// int UserIput 선언을 해줍니다.
	// C++ 입력 함수 Userinput에 데이터를 받아주세요

	//
	int LuckyNumber = 5;
	std::cout << "나의 숫자를 맞추어 보세요 : " << std::endl;
	int UserIput;

	while (true)
	{
		std::cin >> UserIput;
		if (LuckyNumber == UserIput)
		{
			std::cout << "정답을 맞추었습니다." << std::endl;
			break;
		}
		else if (LuckyNumber != UserIput)
		{
			std::cout << "오답입니다. 다시입력하세요." << std::endl;
		}
	}
}