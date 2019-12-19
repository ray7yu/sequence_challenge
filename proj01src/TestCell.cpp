#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "FunClassTemp.h"

using namespace std;

int main( )
{
    vector<int>     v1 = { 3, 5, 8, 2, 4 };
    vector<IntCell> v2 = { IntCell{100}, IntCell{10}, IntCell{300} };
    vector<IntCell> v3 = { IntCell{5}, IntCell{ 200 }, IntCell{15} };

    /* test operators: <, - and << */
    if (v3[0] < v2[0]) {
	cout << "V2[0] value:" << v2[0] <<endl;
	cout << "Gap is: " << v3[0] - v2[0] <<endl;
    }

    cout << "function template with int " << findDiff (v1[1], v1[2]) << endl;
    cout << "function template with IntCell: " << findDiff ( v2[0], v2[2]) << endl;
    cout << "function+class template with IntCell: " << findDiff ( v3[0], v3[2], ComparatorWithRead<IntCell>{ } ) << endl;

    return 0;
}

