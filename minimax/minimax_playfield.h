#ifndef CONNECT_4_MINIMAX_MINIMAX_PLAYFIELD_H
#define CONNECT_4_MINIMAX_MINIMAX_PLAYFIELD_H


#include <playfield.h>

class minimax_playfield : public playfield
{
public:
    minimax_playfield() {};
    minimax_playfield(const playfield &field);
    ~minimax_playfield() {};

    void remove_stone(player_t player, int column);
};


#endif //CONNECT_4_MINIMAX_MINIMAX_PLAYFIELD_H
