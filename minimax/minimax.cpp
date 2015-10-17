#include "minimax.h"

int minimax::play(const playfield &field)
{
    _playfield = minimax_playfield(field);
    _role = determine_player_role();

    if (PLAYER_ONE == _role) {
        return play_next(PLAYER_TWO);
    }

    return play_next(PLAYER_ONE);
}

int minimax::play_next(int enemy_player)
{
    double max_value = INT32_MIN;
    int move = 0;

    for (int column=0; column<abstract_playfield::width; column++) {
        if ( ! _playfield.is_column_full(column)) {
            double value = move_value(column);

            if (value > max_value) {
                max_value = value;
                move = column;

                if (WIN_REVENUE == value) {
                    break;
                }
            }
        }
    }

    return move;
}

double minimax::move_value(int column)
{
    _playfield.insert_stone(_role, column);
    double val = calculate_minimax(MAX_DEPTH, INT32_MIN, INT32_MAX, false);
    _playfield.remove_stone(_role, column);

    return val;
}

/**
 * https://www.youtube.com/watch?time_continue=62&v=2xsXEpdyDUg
 * 
 * @depth int The current depth in the recursion. Start with MAX_DEPTH
 * @alpha double The best value for the maximizing player. Initialize with minus infinity
 * @beta double The best value for the minimizing player. Initialize with infinity
 * @maximizing_player bool Whether to start with the maximizing player. Since we start with MAX_DEPTH and decrementing depth, we start with false here.
 */
double minimax::calculate_minimax(int depth, double alpha, double beta, bool maximizing_player)
{
    // https://en.wikipedia.org/wiki/Minimax#Pseudocode

    bool has_winner = _playfield.is_player_winning(PLAYER_ONE) || _playfield.is_player_winning(PLAYER_TWO);

    // terminate recursion if one of these happen
    if (depth == 0 || has_winner) {
        double score = 0.0;

        if (has_winner) {
            score = _playfield.is_player_winning(_role) ? WIN_REVENUE : LOSE_REVENUE;
        } else {
            score = UNCERTAIN_REVENUE;
        }

        // earlier bad moves from the opponent are more important
        // than later ones. I.e. we weight the
        // value smaller, the deeper we are in the recursion
        return score / (MAX_DEPTH - depth + 1);
    }

    if (maximizing_player) {
        for (int column=0; column < abstract_playfield::width; column++) {
            if ( ! _playfield.is_column_full(column)) {
                _playfield.insert_stone(_role, column);
                alpha = std::max(
                        alpha,
                        calculate_minimax(depth - 1, alpha, beta, false)
                );
                _playfield.remove_stone(_role, column);

                if (beta <= alpha) {
                    break;
                }
            }
        }

        return alpha;
    } else {
        player_t enemy_player_role = _role == PLAYER_TWO ? PLAYER_ONE : PLAYER_TWO;

        for (int column=0; column < abstract_playfield::width; column++) {
            if ( ! _playfield.is_column_full(column)) {
                _playfield.insert_stone(enemy_player_role, column);

                beta = std::min(
                        beta,
                        calculate_minimax(depth - 1 , alpha, beta, true)
                );

                _playfield.remove_stone(enemy_player_role, column);

                if (beta <= alpha) {
                    break;
                }
            }
        }

        return beta;
    }
}

player_t minimax::determine_player_role()
{
    int nr_of_moves = 0;

    std::vector<std::vector<int> > playfield_rep = _playfield.get_playfield_representation();

    for (int i=0; i<abstract_playfield::height; i++) {
        for (int j=0; j<abstract_playfield::width; j++) {
            if (NOBODY != playfield_rep.at(i).at(j)) {
                nr_of_moves++;
            }
        }
    }

    if (0 == nr_of_moves % 2 ) {
        return PLAYER_ONE;
    }

    return PLAYER_TWO;
}

std::string minimax::get_name()
{
    return _name;
}
