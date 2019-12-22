#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "NSequence.h"

using namespace std;

int main()
{
    NSequence<int> v1(0); /* one item added for an empty sequence */
    for (int i = 0; i < v1.getSize(); i++)
    {
        v1[i] = i + 10;
    }

    for (int i = 0; i < 5; i++)
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

    cout << "v1 items:" << v1.getSize() << endl;
    v1.printout(0, v1.getSize() - 1);

    NSequence<IntCell> v2(0);
    for (int i = 0; i < v2.getSize(); i++)
    {
        v2[i].write(i + 11);
    }
    for (int i = 0; i < 5; i++)
    {
        int val = 5 * i + 7 + 100;
        v2.push_back(IntCell{val});
    }
    for (int i = 0; i < v2.getSize(); i += 2)
    {
        v2.remove(i);
    }
    for (int i = 0; i < v2.getSize(); i += 4)
    {
        v2.insert(i, IntCell(13 * i + 13));
    }

    cout << "v2 items:" << v2.getSize() << endl;
    v2.printout(0, v2.getSize() - 1);

    NSequence<string> v3(0);
    for (int i = 0; i < v3.getSize(); i++)
    {
        string val = "AAA";
        val += (char)('A' + i);
        v3[i] = val;
    }
    for (int i = 0; i < 5; i++)
    {
        string val = "BBB";
        val += (char)('B' + i);
        v3.push_back(val);
    }
    for (int i = 0; i < v3.getSize(); i += 2)
    {
        v3.remove(i);
    }
    for (int i = 0; i < v3.getSize(); i += 4)
    {
        string val = "FFF";
        val += (char)('F' + i);
        v3.insert(i, val);
    }

    cout << "v3 items:" << v3.getSize() << endl;
    v3.printout(0, v3.getSize() - 1);

    return 0;
}
