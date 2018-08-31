#include <iostream>

#include "Miscellaneous.h"

using std::cout;
using std::endl;

constexpr size_t SIZE_1 = 6;
constexpr size_t SIZE_2 = 4;

int main(int argc, char** argv)
{
	Miscellaneous misc;

	array<int, SIZE_1> arr1{ 10, 2, 5, 1, 8, 20 };
	array<int, SIZE_2> arr2{ 10, 50, 5, 1 };

	cout << misc.CountTrianglesInArray<SIZE_1>(arr1) << endl;
	cout << misc.CountTrianglesInArray<SIZE_2>(arr2) << endl;

	return 0;
}