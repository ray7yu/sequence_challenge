template <typename Comparable>
int ComparatorWithRead<Comparable>::getDiff(const Comparable &lhs, const Comparable &rhs) const
{
    return findDiff(lhs, rhs);
}

template <typename Comparable>
int findDiff(const Comparable &a, const Comparable &b)
{
    int result = a - b;
    if (result < 0)
    {
        result *= -1;
    }
    return result;
}

template <typename Comparable, typename Comparator>
int findDiff(const Comparable &a, const Comparable &b, Comparator cmp)
{
    return cmp.getDiff(a, b);
}

template <typename T>
int maxSubRange_Cubic(const NSequence<T> &a, const T &ref, const int range, int *start)
{
    int numberFound = 0;
    int beginning;
    //3 for-loops indicate cubic time
    for (int i = 0; i < a.getSize(); i++)
    {
        for (int j = i; j < a.getSize(); j++)
        {
            bool isSequence = true;
            for (int k = i; k <= j; k++)
            {
                if ((a[k] - ref) < -range || (a[k] - ref) > range)
                {
                    isSequence = false;
                    break;
                }
            }
            if (isSequence && (j - i + 1) > numberFound)
            {
                numberFound = j - i + 1;
                beginning = i;
            }
        }
    }
    *start = beginning;
    return numberFound;
}

template <typename T>
int maxSubRange_Quad(const NSequence<T> &a, const T &ref, const int range, int *start)
{
    int numberFound = 0;
    int beginning = 0;
    //A for loop and a while loop indicate quadratic time
    for (int i = 0; i < a.getSize(); i++)
    {
        bool isSequence = true;
        int j = i;
        int current = 0;
        while (isSequence && j < a.getSize())
        {
            if ((a[j] - ref) < -range || (a[j] - ref) > range)
            {
                isSequence = false;
                break;
            }
            j++;
            current++;
            if (current > numberFound)
            {
                numberFound = current;
                beginning = i;
            }
        }
    }
    *start = beginning;
    return numberFound;
}

template <typename T>
int maxSubRange_Linear(const NSequence<T> &a, const T &ref, const int range, int *start)
{
    int numberFound = 0;
    int beginning = 0;
    int i = 0;
    int current = 0;
    //One while-loop indicates linear time
    while (i < a.getSize())
    {
        if ((a[i] - ref) < -range || (a[i] - ref) > range)
        {
            current = 0;
            i++;
            continue;
        }
        else
        {
            current++;
            if (current > numberFound)
            {
                numberFound = current;
                beginning = i - numberFound + 1;
            }
        }
        i++;
    }
    *start = beginning;
    return numberFound;
}

template <typename T>
int maxSubRange_Log(const NSequence<T> &a, const T &ref, const int range, int *start)
{
    return maxSequence(a, ref, range, start, 0, a.getSize() - 1);
}

template <typename T>
int midCross(const NSequence<T> &a, const T &ref, const int range, int *top, int l, int m, int r)
{
    //Finds the longest valid sequence that crosses the middle
    int left = 0;
    int right = 0;
    for (int i = m; i >= l; i--)
    {
        if (a[i] - ref <= range && a[i] - ref >= -range)
        {
            left++;
            *top = i;
        }
        else
        {
            break;
        }
    }
    for (int j = m + 1; j <= r; j++)
    {
        if (a[j] - ref <= range && a[j] - ref >= -range)
        {
            right++;
        }
        else
        {
            break;
        }
    }
    return left + right;
}

template <typename T>
int maxSequence(const NSequence<T> &a, const T &ref, const int range, int *front, int l, int r)
{
    //Base case
    if (l == r)
    {
        if (a[l] - ref <= range && a[l] - ref >= -range)
        {
            *front = l;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int m = (l + r) / 2;
    //Pointers to store the start points of each called function
    int leftValue = *front;
    int rightValue = *front;
    int crossValue = *front;
    //Divide and merge
    int leftSub = maxSequence(a, ref, range, &leftValue, l, m);
    int rightSub = maxSequence(a, ref, range, &rightValue, m + 1, r);
    int crossSub = midCross(a, ref, range, &crossValue, l, m, r);
    //Comparative statements that return the longest length along with
    //the starting point
    if (leftSub > rightSub && leftSub > crossSub)
    {
        *front = leftValue;
        return leftSub;
    }
    else if (rightSub >= leftSub && rightSub >= crossSub)
    {
        *front = rightValue;
        return rightSub;
    }
    else if (crossSub >= leftSub && crossSub > rightSub)
    {
        *front = crossValue;
        return crossSub;
    }
    else
    {
        return 0;
    }
}