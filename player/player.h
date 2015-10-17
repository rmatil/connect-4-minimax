#ifndef CONNECT_4_MINIMAX_PLAYER_H
#define CONNECT_4_MINIMAX_PLAYER_H

#include "abstract_player.h"
#include "abstract_playfield.h"
#include "playfield.h"

/**
 * A simple player which allows to
 * input the next turn via cli after
 * starting the game
 */
class player : public abstract_player {
public:
    player() {}
    player(std::string name) : _name(name) {}
    ~player() {}

    int play(const abstract_playfield &field) {return 0;};
    int play(const playfield &field);

    std::string get_name();

protected:
    std::string _name;
};


#endif //CONNECT_4_MINIMAX_PLAYER_H
