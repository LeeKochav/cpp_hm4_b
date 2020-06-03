#pragma once

#include "Soldier.hpp"

class FootSoldier : public Soldier
{

public:
    FootSoldier(){};
    FootSoldier(uint player_number);
    virtual void action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    virtual uint get_initial_hp();
    virtual void print();
    virtual ~FootSoldier(){};
};
