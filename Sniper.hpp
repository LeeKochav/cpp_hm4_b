#pragma once

#include "Soldier.hpp"

class Sniper : public Soldier
{
public:
    Sniper(){};
    Sniper(uint player_number);
    virtual void action(std::vector<std::vector<Soldier *>> &b,pair<int, int> location);
    virtual uint get_initial_hp();
    virtual void print();
    virtual ~Sniper(){};
};
