
#ifndef CONNECT_4_MINIMAX_ABSTRACT_PLAYER_H
#define CONNECT_4_MINIMAX_ABSTRACT_PLAYER_H

#include <iostream>
#include "abstract_playfield.h"

/**
 * Use this class as base class for any players
 * which should be runned in the game
 */
class abstract_player {
public:
    virtual int play(const abstract_playfield &field) = 0;
    virtual std::string get_name() = 0;
    virtual ~abstract_player() {}
};

#endif // CONNECT_4_MINIMAX_ABSTRACT_PLAYER_H
