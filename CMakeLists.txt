cmake_minimum_required(VERSION 3.3)
project(connect_4_minimax)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(game interfaces playfield player exceptions minimax)

set(SOURCE_FILES main.cpp interfaces/abstract_playfield.h interfaces/abstract_player.h playfield/playfield.cpp playfield/playfield.h player/player.cpp player/player.h interfaces/player_t.h game/game.cpp game/game.h exceptions/column_full_exception.h exceptions/column_out_of_range_exception.h minimax/minimax.cpp minimax/minimax.h minimax/minimax_playfield.cpp minimax/minimax_playfield.h)
add_executable(connect_4_minimax ${SOURCE_FILES})