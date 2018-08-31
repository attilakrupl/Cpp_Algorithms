#pragma once

#include <algorithm>
#include <array>

using std::sort;
using std::size_t;
using std::array;

class Miscellaneous
{
public:

	/*	\brief CountTrianglesInArray(array<int, N> T) template function calculates how many possible triangles can be formed out of the different 
	*	elements of an array (the elements of the array represent the lengths of the sides of the triangles) One element can not be used twice for
	*	a triangle, so each sides must have a unique length.
	*
	*	\param a std::array T of type int with size N
	*
	*	\return the number of possible triangles
	*/
	template<size_t N>
	int CountTrianglesInArray(array<int, N> T)
	{
		int count{ 0 };
		sort(T.begin(), T.end(), [](int a, int b) { return a < b; });

		for (size_t iSmallest = 0; iSmallest < N - 2; ++iSmallest)
		{
			for (size_t iMiddle = iSmallest + 1; iMiddle < N - 1; ++iMiddle)
			{
				size_t iGreatest = iMiddle + 1;
				while ( (iGreatest < N) && (T[iMiddle] + T[iSmallest] > T[iGreatest]))
				{
					++iGreatest;
				}
				count += iGreatest - iMiddle - 1;
			}
		}
		return count;
	}

};