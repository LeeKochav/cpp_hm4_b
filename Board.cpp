#include "Board.hpp"

using namespace WarGame;

Soldier *&Board::operator[](std::pair<int, int> location)
{
    return board[location.first][location.second];
}

Soldier *Board::operator[](std::pair<int, int> location) const
{
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{
    int size = board.size();
    if (source.first >= size || source.second >= size || source.first < 0 || source.second < 0)
    {
        throw std::invalid_argument("Source position is not valid");
    }
    Soldier *s = board[source.first][source.second];
    if (s == nullptr)
    {
        throw std::invalid_argument("No soldier in this position");
    }
    if (s->get_player_number() != player_number)
    {
        throw std::invalid_argument("The soldier belongs to the other player");
    }
    std::pair<int, int> target = source;
    switch (direction)
    {
    case MoveDIR::Up:
        target.first = target.first + 1;
        break;
    case MoveDIR::Down:
        target.first = target.first - 1;
        break;
    case MoveDIR::Right:
        target.second = target.second + 1;
        break;
    case MoveDIR::Left:
        target.second = target.second - 1;
        break;
    default:
        break;
    }
    int x = target.first;
    int y = target.second;
    if (x >= size || y >= size || x < 0 || y < 0)
    {
        throw std::invalid_argument("Target position is not valid");
    }
    if (board[target.first][target.second] != nullptr)
    {
        throw std::invalid_argument("Target position is not empty");
    }
    board[target.first][target.second] = s;
    board[source.first][source.second] = nullptr;
    s->action(board, target);
}

bool Board::has_soldiers(uint player_number) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->get_player_number() == player_number)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::print() const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << "[" << i << "," << j << "]";
            if (board[i][j] != nullptr)
            {
                board[i][j]->print();
            }
            else
            {
                cout << "{(NULL): NULL, hp: NULL}";
            }
        }
        cout << endl;
    }
}
