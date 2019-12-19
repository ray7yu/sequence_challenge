#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "NSequence.h"
#include "FunClassTemp.h"

using namespace std;

int main( )
{
    vector<int>     v1 = { 3, 5, 8, 2, 4 };
    vector<IntCell> v2 = { IntCell{100}, IntCell{10}, IntCell{300} };

    cout << "function template with int " << findDiff (v1[1], v1[2]) << endl;
    return 0;
}

