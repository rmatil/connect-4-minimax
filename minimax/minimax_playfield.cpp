#include <cmath>
#include <iostream>
#include "minimax_playfield.h"
#include "abstract_playfield.h"

minimax_playfield::minimax_playfield(const playfield &field)
{
    _playfield = field.get_playfield_representation();
}


void minimax_playfield::remove_stone(player_t player, int column)
{
    if (column > abstract_playfield::width - 1) {
        std::cerr << "Column " << column << " is out of range" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<_playfield.size(); i++) {
        if (_playfield.at(i).at(column) != 0) {
            if (_playfield.at(i).at(column) == player) {
                // reset
                _playfield.at(i).at(column) = NOBODY;
            } else {
                std::cerr << "Could not remove stone since it belongs to another player" << std::endl;
                exit(EXIT_FAILURE);
            }

            break;
        }
    }

}
