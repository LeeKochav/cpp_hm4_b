
#include "Paramedic.hpp"

Paramedic::Paramedic(uint player_number)
{
    m_player_number = player_number;
    m_hp = 100;
    m_power = 0;
    m_t = Type::ParamedicS;
}

void Paramedic::action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location)
{
    int size = b.size();
    int x = location.first;
    int y = location.second;
    Soldier *curr_sol;

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
}

uint Paramedic::get_initial_hp()
{
    return 100;
}

void Paramedic::print()
{
    printf("{(%d): ParamedicS, hp: %d}", m_player_number, m_hp);
}