#include "player.h"
#include "abstract_playfield.h"


int player::play(const playfield &field)
{
    int column = -1;

    std::cout << "Type in the column where the stone should be placed:" << std::endl;
    std::cout << "> ";
    std::cin >> column;

    // we expect inputs between 1 and 7
    while (column < 1 || column > abstract_playfield::width) {
        std::cerr << "Column must be between 1 and 7. Try again" << std::endl;
        std::cout << "> ";
        std::cin >> column;

        while (field.is_column_full(column)) {
            std::cerr << "Column " << column << " is already full. Choose another one:" << std::endl;
            std::cout << "> ";
            std::cin >> column;
        }
    }

    return column - 1 ;
}

std::string player::get_name()
{
   return _name;
}
