#pragma once

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef enum Type
{
    FootS,
    FootC,
    SniperS,
    SniperC,
    ParamedicS,
    ParamedicC
} Type;
class Soldier
{
protected:
    uint m_player_number;
    uint m_hp;
    uint m_power;
    Type m_t;

public:
    Soldier(){};
    virtual ~Soldier(){};
    virtual void action(std::vector<std::vector<Soldier *>> &b, pair<int, int> location) = 0;
    virtual void print() = 0;
    uint get_player_number() { return m_player_number; }
    uint get_hp() { return m_hp; }
    uint get_power() { return m_power; }
    virtual uint get_initial_hp() = 0;
    void set_hp(uint hp) { m_hp = hp; };
    Type get_type() { return m_t; }
    double distUtil(int x1, int x2, int y1, int y2)
    {
        double distX = pow((x1 - x2), 2);
        double distY = pow((y1 - y2), 2);
        return sqrt(distX + distY);
    }

    // uint getPlayerNumber() { return m_player_number; }
};
