#include <iostream>
#include <cmath>
#include "playfield.h"
#include <sstream>
#include <column_full_exception.h>
#include <column_out_of_range_exception.h>


playfield::playfield()
{
    // assign zeros to the complete playfield
    std::vector<int> vec;
    vec.assign(playfield::width, 0);
    _playfield.assign(playfield::height, vec);
}

player_t playfield::stone_at(int column, int row) const
{
    if (PLAYER_ONE == _playfield.at(row).at(column)) {
        return PLAYER_ONE;
    } else if (PLAYER_TWO == _playfield.at(row).at(column)) {
        return PLAYER_TWO;
    }

    return NOBODY;
}

void playfield::draw_playfield()
{
    std::cout << "      -----------------------------" << std::endl;
    std::cout << "      | 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << std::endl;
    std::cout << "      -----------------------------" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < playfield::height; i++) {
        std::cout << "      |";

        for (int j = 0; j < playfield::width; j++) {
            if (NOBODY == _playfield.at(i).at(j)) {
                std::cout << "   |";
            } else {
                std::cout << " " << _playfield.at(i).at(j) << " |";
            }
        }

        std::cout << std::endl;
    }

    std::cout << "      -----------------------------" << std::endl;
    std::cout << "      | 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << std::endl;
    std::cout << "      -----------------------------" << std::endl;
}

bool playfield::is_playfield_full()
{
    for (int i = 0; i < playfield::width; i++) {
        if (!is_column_full(i)) {
            return false;
        }
    }

    return true;
}

bool playfield::is_column_full(int column) const
{
    for (int i = 0; i < playfield::height; i++) {
        if (NOBODY == _playfield.at(i).at(column)) {
            return false;
        }
    }

    return true;
}

void playfield::insert_stone(player_t player, int column)
{
    if (column > playfield::width - 1) {
        throw column_out_of_range_exception(column);
    }

    if (is_column_full(column)) {
        throw column_full_exception(column);
    }

    int free_row_index = 0;
    for (int i = 0; i < playfield::height; i++) {
        if (NOBODY == _playfield.at(i).at(column)) {
            free_row_index = i;
        }
    }

    _playfield.at(free_row_index).at(column) = player;
}

bool playfield::is_player_winning(player_t player) const
{
    uint64_t bitboard = get_bitboard_for_player(player);
    return is_player_winning(bitboard);
}

bool playfield::is_player_winning(uint64_t bitboard) const
{
    // The bits corresponding to the field entries
    // Note, that the bits 6, 13, ... etc are 0
    // 5 12 19 26 33 40 47
    // 4 11 18 25 32 39 46
    // 3 10 17 24 31 38 45
    // 2  9 16 23 30 37 44
    // 1  8 15 22 29 36 43
    // 0  7 14 21 28 35 42

    // they are set to 1 if there is a stone of the player
    uint64_t y = bitboard & (bitboard >> 6);
    // check \ diagonal
    if (y & (y >> 2 * 6)) {
        return true;
    }

    y = bitboard & (bitboard >> 7);
    // check horizontal -
    if (y & (y >> 2 * 7)) {
        return true;
    }

    y = bitboard & (bitboard >> 8);
    // check / diagonal
    if (y & (y >> 2 * 8)) {
        return true;
    }

    y = bitboard & (bitboard >> 1);
    // check vertical |
    if (y & (y >> 2)) {
        return true;
    }

    return false;
}

std::vector<std::vector<int> > playfield::get_playfield_representation() const
{
    std::vector<std::vector<int> > copy;

    // init with zeroes
    std::vector<int> vec;
    vec.assign(playfield::width, 0);
    copy.assign(playfield::height, vec);

    for (int i = 0; i < playfield::height; i++) {
        for (int j = 0; j < playfield::width; j++) {
            copy.at(i).at(j) = _playfield.at(i).at(j);
        }
    }

    return copy;
}

uint64_t playfield::get_bitboard_for_player(player_t player) const
{
    // idea from http://stackoverflow.com/questions/4261332/optimization-chance-for-following-bit-operations
    // and http://stackoverflow.com/questions/7044670/how-to-determine-game-end-in-tic-tac-toe/7046415#7046415
    // and http://www.fzibi.com/cchess/bitboards.htm

    // init all 64 bits with 0
    uint64_t bitboard = 0;

    // The bits corresponding to the field entries
    // Note, that the bits 6, 13, ... etc are 0
    // 5 12 19 26 33 40 47
    // 4 11 18 25 32 39 46
    // 3 10 17 24 31 38 45
    // 2  9 16 23 30 37 44
    // 1  8 15 22 29 36 43
    // 0  7 14 21 28 35 42

    for (int i = 0; i < playfield::width; i++) {
        for (int j = 0; j < playfield::height; j++) {
            if (player == _playfield.at(j).at(i)) {
                // increase bitboard value for each field which is occupied
                // 2^(j + (i*7))
                bitboard += std::pow(2, j + (i * 7));
            }
        }
    }

    return bitboard;
}
