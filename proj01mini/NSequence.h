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
      
    bool isEmpty( ) const; 
    int  getSize( ) const; 

  private:
    int numOfItems;
    int totalCapacity;
    T * items;
};

#include "NSequence.hpp"  // bring in your implementation

#endif
