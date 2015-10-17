#include <iostream>
#include <minimax.h>
#include "playfield.h"
#include "player_t.h"
#include "game.h"
#include "game.cpp"
#include "player.h"

using namespace std;

int main() {

    playfield field;
    player player_1("Player 1");
    player player_2("Player 2");
    minimax player_3("Minimax 1");
    minimax player_4("minimax 2");

    game<minimax, minimax> game(player_3, player_4);

    game.run(field);



    return 0;
}