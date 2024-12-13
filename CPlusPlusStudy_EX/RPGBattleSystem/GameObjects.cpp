#include "GameObjects.h"

void Player::Attack(Monster* monster)
{
    std::cout << "�÷��̾��� ����!" << std::endl;
    monster->BeAttacked(this);

    // monster->BeAttacked(AP);   : ���Ͱ� ������ ����

    // ������ ���� : bool isDead()

    // ���࿡ ���Ͱ� �׾����� -> ����(Reward)Has-A ����(Monster)
    // monster->reward->GetExp, GetGold, GetItem
}

void Player::BeAttacked(int damage)
{
    std::cout << "�÷��̾ ������ : " << damage << "����!" << std::endl;

    HP -= damage;

    // ���࿡ �÷��̾� ����ߴٸ� -> *���� ����* �Լ��� ȣ���Ѵ�.
    if (IsDead())
    {
        HP = 0;
        std::cout << "�÷��̾ ����Ͽ����ϴ�." << std::endl;
        exit(0);
        // GameManager->GameEnd() // ReturnLobby()
    }
}

bool Player::IsDead()
{
    if (HP <= 0) // �÷��̾ ���� �׳�? HP <= 0
        return true;
    else
        return false;
}

void Player::GetMoney(int money)
{
    std::cout << "ȹ���� ��ȭ : " << money << std::endl;
    this->money += money;
}

void Player::GetExp(int exp)
{
    std::cout << "����ġ ȹ�� : " << exp << std::endl;
    this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
    return &inventory;
}

void Player::ShowStatus()
{
    std::cout << "���� ü�� : " << HP << std::endl;
    std::cout << "���� ���ݷ� : " << AP << std::endl;
    std::cout << "���� ����ġ : " << exp << std::endl;
    std::cout << "====�÷��̾� ����ǰ====" << std::endl;
    std::cout << "���� �ݾ� : " << money << std::endl;
    // �ݺ���. �������� �ִ� ��. Item �迭[i] -> ������ �̸�, ������ ��ȣ, ���..
    std::cout << "���� ������ : " << "�Լ��� ����(�̱���)" << std::endl;
}

void Slime::Attack(Player* player)
{
    std::cout << "�������� ����!" << std::endl;
    player->BeAttacked(AP);
}

void Slime::BeAttacked(Player* player)
{
    std::cout << "�������� �����������" << std::endl;
    HP -= player->GetAttackPower(); // player->AP   // return player.AttackPower;

    if (IsDead())
    {
        HP = 0;
        std::cout << "�������� óġ�߽��ϴ�." << std::endl;
       
        // ������ ����
        DropReward(player);
    }
}

void Slime::DropReward(Player* player)
{
    std::cout << "���� óġ ���� " << std::endl;
    monsterReward->RewardExp();
    monsterReward->RewardMoney();
    monsterReward->RewardItem(player->GetInventory());
}

bool Slime::IsDead()
{
    if (HP <= 0) 
        return true;
    else
        return false;
}

void Reward::RewardItem(std::vector<Item>* inventory)
{
    if (item != nullptr) // �������� ���� ��쿡�� �÷��̾� inventory�� �߰��ϱ� ���� ����
    {
        inventory->push_back(*item);
        std::cout << "������ ȹ��!" << std::endl;
        item->ShowItemInfo();
    }
}

