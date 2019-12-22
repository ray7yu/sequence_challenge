//explicit constructor
template <typename T>
NSequence<T>::NSequence(int initSize)
    : numOfItems{initSize}, totalCapacity{initSize}
{
    if (initSize <= 0)
        numOfItems = totalCapacity = 1;
    items = new T[totalCapacity];
}
//Big Five
//Copy constructor
template <typename T>
NSequence<T>::NSequence(const NSequence &rhs)
{
    numOfItems = rhs.getSize();
    totalCapacity = rhs.getCapacity();

    if (items != nullptr)
    {
        delete[] items;
        items = nullptr;
    }
    items = new T[totalCapacity];
    for (int i = 0; i < numOfItems; i++)
    {
        items[i] = rhs[i];
    }
}
//Copy assignment operator
template <typename T>
NSequence<T> &NSequence<T>::operator=(const NSequence &rhs)
{
    numOfItems = rhs.getSize();
    totalCapacity = rhs.getCapacity();

    if (items != nullptr)
    {
        delete[] items;
        items = nullptr;
    }
    items = new T[totalCapacity];
    for (int i = 0; i < numOfItems; i++)
    {
        items[i] = rhs[i];
    }
    return *this;
}
//Destructor
template <typename T>
NSequence<T>::~NSequence()
{
    if (items != nullptr)
    {
        delete[] items;
        items = nullptr;
    }
}
//Move constructor
template <typename T>
NSequence<T>::NSequence(NSequence &&rhs)
{
    *this = std::move(rhs);
}
//Move assignment operator
template <typename T>
NSequence<T> &NSequence<T>::operator=(NSequence &&rhs)
{
    if (this != &rhs)
    {
        delete[] items;

        numOfItems = rhs.numOfItems;
        totalCapacity = rhs.totalCapacity;
        items = rhs.items;

        rhs.numOfItems = 0;
        rhs.totalCapacity = 0;
        rhs.items = nullptr;
    }
    return *this;
}
//Accessors
template <typename T>
bool NSequence<T>::isEmpty() const
{
    return getSize() == 0;
}
template <typename T>
int NSequence<T>::getSize() const
{
    return numOfItems;
}
template <typename T>
int NSequence<T>::getCapacity() const
{
    return totalCapacity;
}
template <typename T>
T &NSequence<T>::operator[](int index)
{
    return items[index];
}
template <typename T>
const T &NSequence<T>::operator[](int index) const
{
    return items[index];
}
template <typename T>
T &NSequence<T>::getFirst() const
{
    return items[0];
}
template <typename T>
T &NSequence<T>::getLast() const
{
    return items[numOfItems - 1];
}

//Mutators
// insert data element d just before item at pos position
template <typename T>
void NSequence<T>::insert(const int pos, const T &d) // copy semantics
{
    if (numOfItems >= totalCapacity)
    {
        growCapacity();
        for (int p = numOfItems - 1; p >= pos; p--)
        {
            items[p + 1] = std::move(items[p]);
        }
        items[pos] = d;
    }
    else
    {
        for (int p = numOfItems - 2; p >= pos; p--)
        {
            items[p + 1] = std::move(items[p]);
        }
        items[pos] = d;
    }
    numOfItems++;
}
template <typename T>
void NSequence<T>::insert(const int pos, T &&d) // move semantics
{
    if (numOfItems >= totalCapacity)
    {
        growCapacity();
        for (int p = numOfItems - 1; p >= pos; p--)
        {
            items[p + 1] = std::move(items[p]);
        }
        items[pos] = d;
    }
    else
    {
        for (int p = numOfItems - 2; p >= pos; p--)
        {
            items[p + 1] = std::move(items[p]);
        }
        items[pos] = d;
    }
    numOfItems++;
}
template <typename T>
void NSequence<T>::remove(const int pos) // remove item at pos position
{
    for (int p = pos; p < numOfItems - 2; p++)
    {
        items[p] = std::move(items[p + 1]);
    }
    numOfItems--;
}
template <typename T>
void NSequence<T>::push_back(const T &x) //copy semantics, insert at the end
{
    if (numOfItems >= totalCapacity)
    {
        growCapacity();
    }
    items[numOfItems] = x;
    numOfItems++;
}
template <typename T>
void NSequence<T>::push_back(T &&x) // move semantics, insert at the end
{
    if (numOfItems >= totalCapacity)
    {
        growCapacity();
    }
    items[numOfItems] = x;
    numOfItems++;
}
template <typename T>
void NSequence<T>::pop_back() // delete the last element
{
    numOfItems--;
}

//Utilities
/* Grow the totalCapacity by newCapacity, double if zero input provided) */
template <typename T>
void NSequence<T>::growCapacity(int newCapacity)
{
    T *tempItems;
    if (newCapacity == 0)
    {
        totalCapacity *= 2;
        tempItems = new T[totalCapacity];
    }
    else if (newCapacity > 0)
    {
        totalCapacity += newCapacity;
        tempItems = new T[totalCapacity + newCapacity];
    }
    std::copy(items, items + numOfItems, tempItems);
    delete[] items;
    items = tempItems;
}
/* print out the items from begin to end, up to 50 if too many */
template <typename T>
void NSequence<T>::printout(int begin, int end)
{
    for (int i = begin; i < 50 && i <= end; i++)
    {
        std::cout << " [" << i << "]=" << items[i];
    }
    std::cout << "\n";
}