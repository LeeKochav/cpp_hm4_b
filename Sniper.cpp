
#include "Sniper.hpp"

Sniper::Sniper(uint player_number)
{
    m_player_number = player_number;
    m_hp = 100;
    m_power = 50;
    m_t = Type::SniperS;
}

void Sniper::action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)
{
    Soldier *strongestEnemy = nullptr;
    pair<int, int> enemy_location;
    int col = b.size();
    int row = b.size();
    uint maxHp = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (b[i][j] != nullptr)
            {
                Soldier *temp = b[i][j];
                if (temp->get_player_number() != this->get_player_number())
                {
                    uint temp_hp = temp->get_hp();
                    if (temp_hp > maxHp)
                    {
                        maxHp = temp_hp;
                        strongestEnemy = temp;
                        enemy_location = {i, j};
                    }
                }
            }
        }
    }
    if (strongestEnemy != nullptr)
    {
        int enemyHp = strongestEnemy->get_hp();
        int attackerPower = this->get_power();
        int newHp = enemyHp - attackerPower;
        if (newHp <= 0)
        {
            b[enemy_location.first][enemy_location.second] = nullptr;
        }
        else
        {
            strongestEnemy->set_hp(newHp);
        }
    }
}

uint Sniper::get_initial_hp()
{
    return 100;
}

void Sniper::print()
{
    printf("{(%d): Sniper, hp: %d}", m_player_number, m_hp);
}