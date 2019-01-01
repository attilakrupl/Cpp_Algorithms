#include <iostream>

#include "Miscellaneous.h"
#include "Base.h"

using std::cout;
using std::endl;

constexpr size_t SIZE_1 = 6;
constexpr size_t SIZE_2 = 4;
constexpr size_t SIZE_3 = 1;
constexpr size_t SIZE_4 = 5;

int main(int argc, char** argv)
{
	Miscellaneous misc;

	array<int, SIZE_1> arr1{ 10, 2, 5, 1, 8, 20 };
	array<int, SIZE_2> arr2{ 10, 50, 5, 1 };
	array<int, SIZE_3> arr3{ 10 };
	array<int, SIZE_4> arr4{ 10, 13, 18, 23, 25 };

	cout << misc.CountTrianglesInArray<SIZE_1>(arr1) << endl;
	cout << misc.CountTrianglesInArray<SIZE_2>(arr2) << endl;
	cout << misc.CountTrianglesInArray<SIZE_3>(arr3) << endl;
	cout << misc.CountTrianglesInArray<SIZE_4>(arr4) << endl;

    drkrBase::Timer lTimer;
    lTimer.setInterval( [] { std::cout << "Interval passed" << std::endl; }, 3000 );
    lTimer.setTimeout( [] { std::cout << "Timeout passed" << std::endl; }, 13000 );

	return 0;
}