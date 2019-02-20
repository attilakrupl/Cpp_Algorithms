#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

void DoTheSwap( std::vector<char>& aVector
              , char aFirst
              , char aSecond )
{
    auto lFirst          = std::find( aVector.begin(), aVector.end(), aFirst );
    int  lDistanceFirst  = ( lFirst - aVector.begin() );
    auto lSecond         = std::find( aVector.begin(), aVector.end(), aSecond );
    int  lDistanceSecond = ( lSecond - aVector.begin() );

    if ( lDistanceFirst >= lDistanceSecond )
    {
        std::iter_swap( lFirst, ( lFirst - 1 ) );
        DoTheSwap( aVector, aFirst, aSecond );
    }
}

void GenerateUniqueVector( const std::vector<std::vector<char>>& aInput,
                                 std::vector<char>&              aOutput )
{
    std::for_each( aInput.begin(), aInput.end(), [&]( auto lCharVec )
    {
        std::for_each( lCharVec.begin(), lCharVec.end(), [&]( char aChar )
        {
            if ( std::find( aOutput.begin(), aOutput.end(), aChar ) == aOutput.end() )
            {
                aOutput.push_back( aChar );
            }
        });
    });
}

void GenrateStringOutOfVector( const std::vector<char>& aInput 
                             ,       std::string&       aOutputString )
{
    for ( auto lChar : aInput )
    {
        aOutputString += lChar;
    }
}

std::string RecoverSecret( std::vector<std::vector<char>> aChars )
{
    std::vector<char> lCharVector{};

    GenerateUniqueVector( aChars, lCharVector );

    for ( auto lVec : aChars )
    {
        for ( size_t i = 0; i < lVec.size() - 1; ++i )
        {
            DoTheSwap( lCharVector, lVec[i], lVec[i + 1] );
        }
    }

    std::string lRetString = "";

    GenrateStringOutOfVector( lCharVector, lRetString );

    return lRetString;
}


int main()
{
    std::vector<std::vector<char>> lChars = { {'t', 'u', 'p'},
                                              {'w', 'h', 'i'},
                                              {'t', 's', 'u'},
                                              {'a', 't', 's'},
                                              {'h', 'a', 'p'},
                                              {'t', 'i', 's'},
                                              {'w', 'h', 's'} };

    std::cout << RecoverSecret(lChars) << std::endl;

    std::vector<std::vector<char>> lChars2 = { { 't', 's', 'f'},
                                              { 'a', 's', 'u' },
                                              { 'm', 'a', 'f' },
                                              { 'a', 'i', 'n' },
                                              { 's', 'u', 'n' },
                                              { 'm', 'f', 'u' },
                                              { 'a', 't', 'h' },
                                              { 't', 'h', 'i' },
                                              { 'h', 'i', 'f' },
                                              { 'm', 'h', 'f' },
                                              { 'a', 'u', 'n' },
                                              { 'm', 'a', 't' },
                                              { 'f', 'u', 'n' },
                                              { 'h', 's', 'n' },
                                              { 'a', 'i', 's' },
                                              { 'm', 's', 'n' },
                                              { 'm', 's', 'u' } };

    std::cout << RecoverSecret(lChars2) << std::endl;

    std::vector<std::vector<char>> lChars3 = { {'l', 'e', 'd'},
                                               {'o', 'e', 'd'},
                                               {'o', 'l', 'e'},
                                               {'o', 'v', 'e'},
                                               {'s', 'o', 'l'},
                                               {'s', 'e', 'd'},
                                               {'s', 'l', 'e'},
                                               {'v', 'e', 'd'},
                                               {'o', 'l', 'v'},
                                               {'l', 'v', 'd'} };

    std::cout << RecoverSecret(lChars3) << std::endl;

    return 0;
}