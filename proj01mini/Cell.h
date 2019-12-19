#ifndef Cell_H
#define Cell_H

#include <iostream>

using namespace std;

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    friend ostream & operator<< ( ostream & out, const IntCell & rhs)
    {
	out << rhs.read();
	return out;
    }

    /* XXX: you need to implement the following functions in Cell.cpp */
    explicit IntCell( int initialValue = 0 );
    int read( ) const;
   
  private:
    int storedValue;
};

#endif
