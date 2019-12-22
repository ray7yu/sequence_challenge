#include <iostream>
#include "Cell.h"
#include "NSequence.h"
#include "FunClassTemp.h"

using namespace std;

/* This driver program is nearly identical to MaxSubRange.cpp, but it 
    uses the IntCell class to create the NSequence, seeing if FunClassTemp.hpp
    can handle that case */
int main()
{
    NSequence<IntCell> cells(0); /* one item added for an empty sequence */
    for (int i = 0; i < cells.getSize(); i++)
    {
        cells[i].write(i + 10);
    }
    for (int i = 0; i < 15; i++)
    {
        int number = 7 * i + 7;
        cells.push_back(IntCell{number});
    }
    for (int i = 0; i < cells.getSize(); i += 2)
    {
        cells.remove(i);
    }
    for (int i = 0; i < cells.getSize(); i += 3)
    {
        cells.insert(i, IntCell(8 * i + 8));
    }
    cout << "Sequence has " << cells.getSize() << " items:";
    cells.printout(0, cells.getSize() - 1);

    int begin = 0;
    int sub = maxSubRange_Cubic<IntCell>(cells, IntCell{30}, 20, &begin);
    cout << "Cubic func found " << sub << " items:";
    cells.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Quad<IntCell>(cells, IntCell{30}, 20, &begin);
    cout << "Quadratic func found " << sub << " items:";
    cells.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Linear<IntCell>(cells, IntCell{30}, 20, &begin);
    cout << "Linear func found " << sub << " items:";
    cells.printout(begin, begin + sub - 1);

    begin = 0;
    sub = maxSubRange_Log<IntCell>(cells, IntCell{30}, 20, &begin);
    cout << "Log func found " << sub << " items:";
    cells.printout(begin, begin + sub - 1);

    return 0;
}
