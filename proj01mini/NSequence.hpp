template <typename T>
NSequence<T>::NSequence (int initSize )
    : numOfItems{ initSize }, totalCapacity{ initSize}
{ 
    if (initSize == 0)
	numOfItems = totalCapacity = 1; /* leave the last one as end marker */
    items = new T[ totalCapacity ]; 
}

#if 0
template <typename T>
bool NSequence<T>::isEmpty( ) const
{ return getSize( ) == 0; }

template <typename T>
int NSequence<T>::getSize( ) const
{ return numOfItems; }
#endif
