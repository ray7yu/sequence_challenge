/**
 * Return the difference between two objects: a and b
 * Comparable objects must provide operator< and operator-
 */
template <typename Comparable>
int findDiff( const Comparable & a, const Comparable & b)
{
    int diff = 0;

    if (a < b)
	diff = b - a; 
    else
	diff = a - b;
    
    return diff;
}

