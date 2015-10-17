#include <ostream>
#include <iostream>

#ifndef CONNECT_4_MINIMAX_COLUMN_OUT_OF_RANGE_EXCEPTION_H
#define CONNECT_4_MINIMAX_COLUMN_OUT_OF_RANGE_EXCEPTION_H

/**
 * Thrown if the index of the column is out
 * of the playfield width
 */
class column_out_of_range_exception
{
public:

    column_out_of_range_exception(int index) : _index(index)
    { }

    ~column_out_of_range_exception()
    { };

    void mesg();

private:
    int _index;
};

#endif //CONNECT_4_MINIMAX_COLUMN_OUT_OF_RANGE_EXCEPTION_H

inline void column_out_of_range_exception::mesg()
{
    std::cerr << "Index of column must lie between 1 and 7 but was " << _index << std::endl;
}
