#ifndef CONNECT_4_MINIMAX_GAME_H
#define CONNECT_4_MINIMAX_GAME_H

#include <iostream>
#include "playfield.h"
#include "player.h"

/**
 * Controls the game.
 * Constructor with two players implementing @see abstract_player.h can be passed
 * to the constructor.
 * To start the game, invoke run() with a playfield implementing
 * @see abstract_playfield.h as argument
 */
template<typename P1, typename P2>
class game {
public:
    game(P1 &player_1, P2 &player_2);
    ~game() {};

    void run(playfield &field);

protected:
    bool validate_insertion(playfield &field, player_t player, int column);

private:
    P1 _player_1;
    P2 _player_2;
    playfield _playfield;
    bool is_running = false;
};

#endif // CONNECT_4_MINIMAX_GAME_H
