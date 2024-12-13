#include "lectures.h"

/*
*  클래스 상속
*  1. class Parent{};
*  2. class Child : public Parent{}

*  class Pet
*  hungry, happy
*  
*  dog, cat, bird... 추가 컨텐츠 :Pet 클래스 상속 받는 클래스 구현
*/

// 몬스터 : 추상적인 개념의 객체
// Gobllin..(인간형), -> 몬스터 상속받게 만든다.

/*
*  객체 포인터 참조관계
*  c++에서 포인터 변수는 해당 객체를 직접 혹은 간접적으로 가르킬 수 있다.
*  Dog : public Pet   
*  Pet* pet; : 당연히 된다.
*  Pet* dog; : 상속된 클래스를 부모 포인터가 가르킬 수 있다.
*  Dog* dog;
*  Dog* pet; // 컴파일 에러 : 문법적으로 자식 클래스 포인터가 부모 클래스를 직접 가르키는 것을 막아두었다. -> 형변환
*  (Pet)Dog
*/

/*
*   정리 : 클래스의 확장성에 대한 문제를 개선하기 위한 방안1. <-> 시간
*   Dog클래스. Cat클래스도 Play(Dog* dog) Play(Cat* cat), Feed 함수로 표현
*   Cat과 Dog를 동시에 상속하는 Pet클래스를 인자로 넘겨준다.
*   Play(Pet* pet)  <- Dog 
*/

/*
*  부모 클래스를 인자로 사용해서 범용성 있는 함수를 구현하였다.   
*  void Play(Pet* pet)  => pet을 상속받는 모든 클래스를 범용적으로 표현가능하게 함.
*  문제가 발생했다. pet을 상속받는 Dog, HuntDog 자식 클래스와 부모 클래스가 같은 함수를 구현을 했는데,,
*  => 부모가 갖고 있는 함수를 자식 버전으로 변경하고 싶다.
*  가상 함수,  override 키워드
*  virtual 키워드 => 가상 함수
*  override 키워드 => virtual과 함께 사용된다. 덮어쓰다.
*/

/*
*   Pet*     a  = Pet; (o)
*   Pet*     b = dog;  (o)
*   Pet*     c = hdog; (o)
* 
*   Dog*     a  = Pet ; (X)
*   Dog*     b  = dog;  (o)
*   Dog*     c  = hdog; (o)
* 
*   HuntDog* a = hdog;
*   HuntDog* b = dog; (x)
*   HuntDog* c = pet; (x) 
*/

class Pet // 플레이어가 추상적인 대상으로 접근할 수 있는 객체
{
protected:
    int hungry;
    int happy;
public:
    Pet() {};
    Pet(int hungry, int happy) : hungry(hungry), happy(happy) 
    {
        std::cout << "Pet을 생성했습니다." << std::endl;
    }
    void ShowInfo()
    {
        std::cout << "배고픔 : " << hungry << std::endl;
        std::cout << "행복도 : " << happy << std::endl;
    }

    virtual void PlayWithMaster()
    {
        std::cout << "펫과 놀아주었다" << std::endl;
        hungry -= 10;
        happy += 5;
    }
};

class Dog2 : public Pet
{
public:
    Dog2() {}
    Dog2(int hungry, int happy) : Pet(hungry,happy)
    {
        std::cout << "개를 생성했습니다." << std::endl;
    }

    void PlayWithMaster() override // virtual 함수로 작성된 함수가 있으면 반드시 이 함수로 override해라
    {
        std::cout << "개와 놀아주었다." << std::endl;
        hungry -= 10;
        happy += 5;
    }

    void Bark()
    {
        std::cout << "왈왈" << std::endl;
    }
};

// Is- A 사냥개는 개이다.
class HuntDog : public Dog2
{
public:
    HuntDog() {}
    HuntDog(int hungry, int happy) : Dog2(hungry, happy) {}
    void Hunting()
    {
        std::cout << "사냥개가 사냥을 합니다." << std::endl;
    }

    //void PlayWithMaster() override
    //{
    //    std::cout << "사냥개와 놀아주었다." << std::endl;
    //    hungry -= 20;
    //    happy += 10;
    //}
};

class Cat : public Pet
{
public:
    Cat() {}
    Cat(int hungry, int happy) : Pet(hungry, happy) {}

    void Hide()
    {
        std::cout << "고양이가 숨었습니다." << std::endl;
    }
};

// PetController, PetHandler : Pet클래스를 제어하는 클래스다.
// pet과 놀아주다. Pet에 먹이를 주다.

class PetController // 펫관리자는 펫이다.(IS-A X), (Has-A o)
{
private:
    Pet* myPet; 
    int money;   // 펫 먹이 비용, 알바를 통해서 돈 획득, 새로운 펫 구입
    int ActivePoint; // 행동력

    void UseActivePoint()
    {
        std::cout << "행동력을 1 소모했습니다." << std::endl;
        ActivePoint--;
        std::cout << "남은 행동력: " << ActivePoint << std::endl;
    }

public:
    PetController() {};  // 기본(디폴트) 생성자
    PetController(Pet* pet, int money, int AP) : money(money), ActivePoint(AP)
    {
        myPet = pet;
    }
    
    void EarnMoney(int pay) // 행동력을 소모해서 돈을 획득하는 함수
    {
        std::cout << pay << "만큼 돈을 획득했습니다." << std::endl;
        UseActivePoint();      
        money += pay;
    }

    void Play()
    {
        myPet->PlayWithMaster();
        UseActivePoint();
    }


    // Pet 클래스를 이용해서 고유 함수를 실행시키고 싶다.
    // Pet을 고유 클래스로 타입 변환(Casting) 시키고 싶다.
    // 문제. 모든 Pet이 상속 받는 하나의 자식 클래스로 변환할 수 없다.
    // 조건이 필요해집니다.

    // c언어 형변환   (타입) 이름;
    // c++언어 형변환 조건을 추가해서 연산자로 만듦.
    // static_cast, dynamic_cast, reinterpret_cast, const_cast

    // dynamic_cast 형변환
    // if조건문으로 제한을 걸어서 표현

    void Play2() // Cat, Dog, Bird 고유한 함수를 만들어주세요.
    {
       /* if (myPet 만약에 huntDog라면)
            hunyDog->Hunting();                */
        HuntDog* huntDog = dynamic_cast<HuntDog*>(myPet);
        if(huntDog != nullptr)
            huntDog->Hunting();

        Cat* cat = dynamic_cast<Cat*>(myPet);
        if (cat != nullptr)
            cat->Hide();

        Dog2* dog = dynamic_cast<Dog2*>(myPet);
        if(dog != nullptr)
            dog->Bark();
    }


    void ShowInfo()
    {
        std::cout << "소지 금액 : " << money << std::endl;
        std::cout << "남은 행동력 : " << ActivePoint << std::endl;
        std::cout << "------펫의 정보------" << std::endl;
        myPet->ShowInfo();
    }
};

// 객체프로그래밍의 다형성 : 동일 형태로 복수의 기능을 구현
// 클래스를 확장할 때 마다 동일 함수의 오버로딩을 구현하는 것을 피하고
// 하나의 함수로 표현하기 위해서.
// PetController의 변수 player.Play(); 형태가 모두 동일합니다.
// 결과는 모두 다릅니다.

// 공통된 함수 Virtual void PlayWithMaster();
// 이름과 반환 값이 같은 함수를 상속받는 클래스에 선언을 해줘야한다.

// Pet을 상속받는 클래스인데, 각 클래스 고유의 메서드를 실행하는 방법
// Hunting 실행하는 법.. Cat. Hide 실행을 하려면 어떻게 해야하는가?

// Play(Pet* pet)으로 Cat고유의 함수, Dog고유의 함수를 실행하는 법
// PlayWithCat(Cat* cat); (Cat& cat);  cat->Hide();
// PlayWithDog(Dog* dog);
// PlayWithBird(Bird* bird);

// 클래스를 상속하는 이유 첫번째. PetController에서 Pet을 사용하는 공통된 함수로 한번에 표현한다.
// 두번째. 클래스 확장성. Pet-> Dog, Cat, Bird 고유한 함수를 갖게 된다. Cat, Dog, Bird 인자로 만드려고 하면 복잡해진다.
// 형변환(자식 <-> 부모) dynamic_cast : 형변환이 불가능하면 nullPtr 특징.


void lecture9()
{
    Pet pet(100, 100);
    Dog2 dog(100,100);
    HuntDog huntDog(100,100);
    PetController player(&pet, 1000, 3);
    player.Play();
    player.ShowInfo();

    PetController p2(&dog, 1000, 3);
    p2.Play();
    p2.Play2();
    p2.ShowInfo();

    PetController p3(&huntDog, 1000, 3);
    p3.Play();
    p3.Play2();
    p3.ShowInfo();

    Cat cat(100, 100);
    PetController p4(&cat, 1000, 3);
    p4.Play2();
}