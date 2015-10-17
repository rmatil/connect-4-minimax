#ifndef CONNECT_4_MINIMAX_ABSTRACT_PLAYFIELD_H
#define CONNECT_4_MINIMAX_ABSTRACT_PLAYFIELD_H

#include "player_t.h"

/**
 * Use this class as base class
 * for any playfields which should be used within the game
 */
class abstract_playfield {
public:
    // the size of the field
    const static int width=7;
    const static int height=6;
    
    // returns the stone (none/player1/player2) at the position
    // 0 <= x <= width
    // 0 <= y <= height
    // stone_at(0,0) ................ top left
    // stone_at(width-1,height-1) ... bottom right
    // if we insert a stone in a new game in column i,
    // it lands at (i,height-1)
    virtual player_t stone_at(int x, int y) const = 0;
    virtual ~abstract_playfield() {}
}; 


#endif // CONNECT_4_MINIMAX_ABSTRACT_PLAYFIELD_H
