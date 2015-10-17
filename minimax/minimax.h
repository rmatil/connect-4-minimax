#ifndef CONNECT_4_MINIMAX_MINIMAX_H
#define CONNECT_4_MINIMAX_MINIMAX_H


#include <abstract_player.h>
#include "minimax_playfield.h"

/**
 * This class implements a player which is using
 * the Minimax algorithm to calculate its next turn.
 *
 * For information about the Minimax algorithm see:
 * - https://en.wikipedia.org/wiki/Minimax#Pseudocode
 *
 * Note, that this implementation is highly inspired by
 * https://johannes89.wordpress.com/2014/02/09/teaching-a-computer-to-play-connect-four-using-the-minimax-algorithm/
 *
 */
class minimax : abstract_player
{
public:
    minimax() {};
    minimax(std::string name) : _name(name) {};
    ~minimax() {};

    int play(const playfield &field);
    int play(const abstract_playfield &field) { return 0; } // override the virtual function of super class player

    std::string get_name();

protected:
    const static int MAX_DEPTH = 8;
    constexpr static double WIN_REVENUE = 1.0;
    constexpr static double LOSE_REVENUE = -1.0;
    constexpr static double UNCERTAIN_REVENUE = 0.0;

    minimax_playfield _playfield;
    player_t _role;
    std::string _name;

    int play_next(int enemy_player);
    double move_value(int column);
    double calculate_minimax(int depth, double alpha, double beta, bool maximizing_player);
    player_t determine_player_role();
};


#endif //CONNECT_4_MINIMAX_MINIMAX_H
