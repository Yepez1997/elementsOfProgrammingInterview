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
#define START cout << "*TEST*" << '\n' 
#define DONE cout << "*FINISHED*" << '\n' 

/* Parity: if number of ones is odd return 1 else 0
* Runs in linear time ... can improve 
*/
short Parity(unsigned long x) {
    // look at whars happening in a brute force approach
    short result = 0; 
    while(x) {
	
	// if has one 
	result ^= (x & 1); 
	watch(result); 
	watch(x); 
	// shift bit by 1 
	x >>= 1; 
	watch(x); 
    }
    cout << "final" << '\n';
    watch(result);
    return result; 

}


TEST_CASE("Parities computed","[Parity]") {

    // stuff
    SECTION("Binary 1") {
	START;
	unsigned long x = 10; 
	REQUIRE(Parity(x) == 0); 
	// this is not a parity;
	// has binary form 1010 initially;
	//  1010 >> 1 = 1101
	DONE;	
    }

    SECTION("Binary 2") {
	START;
	unsigned long x = 2;
	REQUIRE(Parity(x) == 1);   
	// this is a parity; 
	// has formm in binart as 0b10; 
	DONE;
    }
    
}



