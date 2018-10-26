/* Parity.cpp: 
* Definition parity of a binary bit
*/

// for testing stuff 
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>

using namespace std; 

// used for debugging 
#define watch(x) cout << (#x) << " is " <<  (x) << '\n' 

/* Parity: if number of ones is odd return 1 else 0
*/
short Parity(unsigned long x) {
    // look at whars happening in a brute force approach
    short result = 0; 
    while(x) {
		
	result ^= (x & 1); 
	watch(result); 
	watch(x); 
	x >>= 1; 
	watch(x); 
    }

    return result; 

}


TEST_CASE("Parities computed","[Parity]") {

    // stuff
    SECTION("Binary 1") {
	unsigned long x = 10; 
	REQUIRE(Parity(x) == 0); 
	// this is not a parity;
	// has form in binary as 1010;
    }

    SECTION("Binary 2") {
	unsigned long x = 2;
	REQUIRE(Parity(x) == 1);   
	// this is a parity; 
	// has formm in binart as 0001; 
    
    }
    
}



