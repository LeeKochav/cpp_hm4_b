
#include "FootSoldier.hpp"

FootSoldier::FootSoldier(uint player_number)
{
    m_player_number = player_number;
    m_hp = 100;
    m_power = 10;
    m_t = Type::FootS;
}

void FootSoldier::action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)
{
    Soldier *closestEnemy = nullptr;
    pair<int, int> enemy_location;
    int col = b.size();
    int row = b.size();
    double min_distance = row * col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (b[i][j] != nullptr)
            {
                Soldier *temp = b[i][j];
                if (temp->get_player_number() != this->get_player_number())
                {
                    double d_temp = this->distUtil(location.first, i, location.second, j);
                    if (d_temp < min_distance)
                    {
                        min_distance = d_temp;
                        closestEnemy = temp;
                        enemy_location = {i, j};
                    }
                }
            }
        }
    }
    if (closestEnemy != nullptr)
    {
        int enemyHp = closestEnemy->get_hp();
        int attackerPower = this->get_power();
        int newHp = enemyHp - attackerPower;
        if (newHp <= 0)
        {
            b[enemy_location.first][enemy_location.second] = nullptr;
        }
        else
        {
            closestEnemy->set_hp(newHp);
        }
    }
}

uint FootSoldier::get_initial_hp()
{
    return 100;
}

void FootSoldier::print()
{
    printf("{(%d): FootS, hp: %d}", m_player_number, m_hp);
}