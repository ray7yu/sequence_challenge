#include "Cell.h"

IntCell::IntCell(int initialValue) : storedValue{initialValue}
{
}
int IntCell::size() const
{
    return storedValue;
}
int IntCell::read() const
{
    return storedValue;
}
void IntCell::write(int x)
{
    storedValue = x;
}
bool IntCell::operator<(const IntCell &rhs) const
{
    return storedValue < rhs.size();
}
int IntCell::operator-(const IntCell &rhs) const
{
    return storedValue - rhs.size();
}