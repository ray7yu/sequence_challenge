#include "Cell.h"
#include "NSequence.h"

/** 
 * XXX: Implement all seven functions declared here, i.e., including getDiff
 * your implementation should be in the file FunClassTemp.hpp
 */
template <typename Comparable>
class ComparatorWithRead
{
    public: 
	/* a Class template calculates the difference in the size of two inputs*/
	int getDiff( const Comparable & lhs, const Comparable & rhs ) const;
};

/* a function template calculates the difference in the size of two inputs*/
template <typename Comparable>
int findDiff( const Comparable & a, const Comparable & b);

/**
 * a function template that takes a class template to calculate
 * the difference in the size of the first two inputs.
 */
template <typename Comparable, typename Comparator>
int findDiff (const Comparable & a, const Comparable & b, Comparator cmp);

/**
 * All functions below take four parameters (three inputs and one output).
 *
 * It searches from a NSequence <a> for a maximal subsequence in which all items 
 * should fall within the range from the input <ref>, i.e., 
 * [<ref>.size - range, <ref>.size + range]
 * 
 * Output <start>: the starting position of the maximum subsequence 
 * return value: the length of the maximum subsequence as the return value.
 */
template <typename T>
int maxSubRange_Cubic(const NSequence <T> & a, const T & ref, const int range, int * start);

template <typename T>
int maxSubRange_Quad(const NSequence <T> & a, const T & ref, const int range, int * start);

template <typename T>
int maxSubRange_Linear(const NSequence <T> & a, const T & ref, const int range, int * start);

template <typename T>
int maxSubRange_Log(const NSequence <T> & a, const T & ref, const int range, int * start);

#include "FunClassTemp.hpp"
