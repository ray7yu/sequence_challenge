#ifndef NSEQUENCE_H
#define NSEQUENCE_H

#include <algorithm>
#include <iostream>
#include <utility>

/* XXX: Implement all member functions for NSequence in NSequence.hpp */

template <typename T>
class NSequence
{
  public:
    explicit NSequence( int initSize = 0 ); 
      
    NSequence( const NSequence & rhs );
    NSequence & operator= ( const NSequence & rhs );
    ~NSequence( );
    NSequence( NSequence && rhs );
    NSequence & operator= ( NSequence && rhs );
    
    bool isEmpty( ) const; 
    int  getSize( ) const;
    int  getCapacity( ) const;

    T & operator[]( int index );
    const T & operator[]( int index ) const;

    T & getFirst ( ) const;
    T & getLast ( ) const;

    // insert data element d just before item at pos position
    void insert(const int pos, const T & d); // copy semantics
    void insert(const int pos, T && d); // move semantics
    void remove(const int pos); // remove item at pos position

    void push_back( const T & x ); //copy semantics, insert at the end
    void push_back( T && x ); // move semantics, insert at the end
    void pop_back( ); // delete the last element

    /* Grow the totalCapacity by newCapacity, double if zero input provided) */
    void growCapacity (int newCapacity = 0);

    /* print out the items from begin to end, up to 50 if too many */
    void printout (int begin, int end);

  private:
    int numOfItems;
    int totalCapacity;
    T * items;
};

#include "NSequence.hpp"  // bring in your implementation

#endif
