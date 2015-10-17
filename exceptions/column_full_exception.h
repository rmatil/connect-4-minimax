#ifndef CONNECT_4_MINIMAX_COLUMN_FULL_EXCEPTION_H
#define CONNECT_4_MINIMAX_COLUMN_FULL_EXCEPTION_H

#include <exception>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

/**
 * Thrown, if the column where the stone should be inserted
 * is already filled up
 */
class column_full_exception
{
public:

    column_full_exception(int column) : _column(column)
    { };

    ~column_full_exception()
    { }

    void mesg();

private:
    int _column;

};

inline void column_full_exception::mesg()
{
    std::cerr << "Column " << _column << " is already full" << std::endl;
}

#endif //CONNECT_4_MINIMAX_COLUMN_FULL_EXCEPTION_H
