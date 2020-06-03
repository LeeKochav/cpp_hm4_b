#pragma once

#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic
{
public:
    ParamedicCommander(uint player_number);
    void action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location);
    uint get_initial_hp();
    void print();
    ~ParamedicCommander(){};
};
