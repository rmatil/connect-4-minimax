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
    minimax player_2("Minimax");

    game<player, minimax> game(player_1, player_2);

    game.run(field);



    return 0;
}