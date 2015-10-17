#include <column_full_exception.h>
#include <column_out_of_range_exception.h>
#include "game.h"

template<typename P1, typename P2>
game<P1, P2>::game(P1 &player_1, P2 &player_2)
{
    _player_1 = player_1;
    _player_2 = player_2;
    is_running = true;
}

// starts the gameloop
template<typename P1, typename P2>
void game<P1, P2>::run(playfield &field)
{
    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "             STARTING GAME" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "  Player 1: " << _player_1.get_name() << std::endl;
    std::cout << "    vs." << std::endl;
    std::cout << "  Player 2: " << _player_2.get_name() << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << std::endl;
    field.draw_playfield();

    while (is_running) {
        if (is_running) {
            // Player 1
            std::cout << _player_1.get_name() << "'s turn:" << std::endl;
            int column = _player_1.play(field);

            while ( ! validate_insertion(field, PLAYER_ONE, column)) {
                column = _player_1.play(field);
            }

            // checks
            if (field.is_player_winning(PLAYER_ONE)) {
                std::cout << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << "             PLAYER 1 WINS" << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << std::endl;

                is_running = false;
            }

            if (field.is_playfield_full()) {
                std::cout << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << "          NO WINNER. GAME ENDS" << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << std::endl;
                is_running = false;
            }

            field.draw_playfield();
        }

        if (is_running) {
            // Player 2
            std::cout << _player_2.get_name() << "'s turn: " << std::endl;
            int column = _player_2.play(field);

            while ( ! validate_insertion(field, PLAYER_TWO, column)) {
                column = _player_2.play(field);
            }

            // checks
            if (field.is_player_winning(PLAYER_TWO)) {
                std::cout << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << "             PLAYER 2 WINS" << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << std::endl;
                is_running = false;
            }

            if (field.is_playfield_full()) {
                std::cout << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << "           NO WINNER. GAME ENDS" << std::endl;
                std::cout << "*****************************************" << std::endl;
                std::cout << std::endl;
                is_running = false;
            }

            field.draw_playfield();

        }
    }

    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "             GAME ENDED" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << std::endl;
}

template<typename P1, typename P2>
bool game<P1, P2>::validate_insertion(playfield &field, player_t player, int column)
{
    try {
        // we expect a column between 0 and 6
        field.insert_stone(player, column);
    } catch (column_full_exception &e) {
        e.mesg();
        return false;
    } catch (column_out_of_range_exception &e) {
        e.mesg();
        return false;
    }

    return true;
}