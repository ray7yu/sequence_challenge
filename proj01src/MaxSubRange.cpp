#include <iostream>
#include "Cell.h"
#include "NSequence.h"
#include "FunClassTemp.h"

using namespace std;

int main()
{
    NSequence<int> v1(0); /* one item added for an empty sequence */
    for (int i = 0; i < v1.getSize(); i++)
    {
        v1[i] = i + 10;
    }
    for (int i = 0; i < 15; i++)
    {
        v1.push_back(7 * i + 7);
    }
    for (int i = 0; i < v1.getSize(); i += 2)
    {
        v1.remove(i);
    }
    for (int i = 0; i < v1.getSize(); i += 3)
    {
        v1.insert(i, 8 * i + 8);
    }

    cout << "Sequence has " << v1.getSize() << " items:";
    v1.printout(0, v1.getSize() - 1);

    int begin = 0;
    int sub = maxSubRange_Cubic<int>(v1, 30, 20, &begin);
    cout << "Cubic func found " << sub << " items:";
    v1.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Quad<int>(v1, 30, 20, &begin);
    cout << "Quadratic func found " << sub << " items:";
    v1.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Linear<int>(v1, 30, 20, &begin);
    cout << "Linear func found " << sub << " items:";
    v1.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Log<int>(v1, 30, 20, &begin);
    cout << "Log func found " << sub << " items:";
    v1.printout(begin, begin + sub - 1);

    return 0;
}
