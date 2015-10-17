#ifndef CONNECT_4_MINIMAX_PLAYFIELD_H
#define CONNECT_4_MINIMAX_PLAYFIELD_H

#include <vector>
#include "abstract_playfield.h"
#include "player_t.h"

class playfield : public abstract_playfield {
public:
    playfield();
    ~playfield() {}
    player_t stone_at(int x, int y) const;

    void insert_stone(player_t player, int column);
    void draw_playfield();

    bool is_playfield_full();
    bool is_column_full(int column) const;
    bool is_player_winning(player_t player) const;
    bool is_player_winning(uint64_t bitboard) const;

    uint64_t get_bitboard_for_player(player_t player) const;
    std::vector<std::vector<int> > get_playfield_representation() const;

protected:
    std::vector<std::vector<int>> _playfield;
};


#endif //CONNECT_4_MINIMAX_PLAYFIELD_H
