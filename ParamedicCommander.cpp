#include "ParamedicCommander.hpp"

ParamedicCommander::ParamedicCommander(uint player_number)
{
    m_player_number = player_number;
    m_hp = 200;
    m_power = 0;
    m_t = Type::ParamedicC;
}

void ParamedicCommander::action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)
{
    int size = b.size();
    int x = location.first;
    int y = location.second;
    Soldier *curr_sol;
    std::vector<Soldier *> sqaudTeam;
    std::vector<pair<int, int>> sqaudTeamLocations;
    int col = b.size();
    int row = b.size();

    if (x + 1 < size)
    {
        curr_sol = b[x + 1][y];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if (y + 1 < size)
    {
        curr_sol = b[x][y + 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if (x - 1 >= 0)
    {
        curr_sol = b[x - 1][y];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if (y - 1 >= 0)
    {
        curr_sol = b[x][y - 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if ((y - 1 >= 0) && (x - 1 >= 0))
    {
        curr_sol = b[x - 1][y - 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if ((y + 1 < size) && (x + 1 < size))
    {
        curr_sol = b[x + 1][y + 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if ((y + 1 < size) && (x - 1 >= 0))
    {
        curr_sol = b[x - 1][y + 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    if ((y - 1 >= 0) && (x + 1 < size))
    {
        curr_sol = b[x + 1][y - 1];
        if (curr_sol != nullptr)
        {
            if (curr_sol->get_player_number() == this->get_player_number())
            {
                uint initHp = curr_sol->get_initial_hp();
                curr_sol->set_hp(initHp);
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (b[i][j] != nullptr)
            {
                Soldier *temp = b[i][j];
                if (temp->get_player_number() == this->get_player_number())
                {
                    if (temp->get_type() == ParamedicS)
                        temp->action(b, {i, j});
                }
            }
        }
    }
}

uint ParamedicCommander::get_initial_hp()
{
    return 200;
}

void ParamedicCommander::print()
{
    printf("{(%d): ParamedicC, hp: %d}", m_player_number, m_hp);
}