#include "SniperCommander.hpp"

SniperCommander::SniperCommander(uint player_number)
{
    m_player_number = player_number;
    m_hp = 120;
    m_power = 100;
    m_t = Type::SniperC;
}

void SniperCommander::action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)
{
    std::vector<Soldier *> sqaudTeam;
    std::vector<pair<int, int>> sqaudTeamLocations;
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
                else if (temp->get_type() == SniperS)
                {
                    sqaudTeam.push_back(temp);
                    sqaudTeamLocations.push_back({i, j});
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
    for (int i = 0; i < sqaudTeam.size(); i++)
    {
        sqaudTeam[i]->action(b, sqaudTeamLocations[i]);
    }
}

uint SniperCommander::get_initial_hp()
{
    return 120;
}

void SniperCommander::print()
{
    printf("{(%d): SniperC, hp: %d}", m_player_number, m_hp);
}