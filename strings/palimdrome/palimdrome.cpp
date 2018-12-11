/* Palimdrome.cpp: There exists a palimdrome 
* if and only if the forward words are the same 
* as the reversed 
*/
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


#include <iostream>
#include <deque>
#include <sstream>
#include <stack>

#define watch(x) cout << (#x) <<  " is " << (x) << '\n'  


using namespace std; 

std::stack<std::string> palindrome;

/* Is Palimdrome if the word can be reversed 
* and achieve the same word ie pop deque backwards 
*/
bool is_palindrome(std::string palim) {
    
    std::string glued_string = ""; 
    
    while (!palindrome.empty()){
	glued_string += (std::string)palindrome.pop();
    }

    if (palim == glued_string) {
	return true; 
    
    return false; 

    }

}


/*  str_to_deque: puts individual string in a deque
*/
void str_to_deque(std::string palim) {
    
    std:stringstream ss(palim); 
    std::string holder = ""; 

    while (ss) {
	watch (ss.get());
	palindrome.push((ss.get()));
    }
}

// list of palindrome words include mom, anna, level, racecar 
TEST_CASE("Palndrome checked", "[is_palaindrome]") {

    SECTION("Tests false word") {

	std::string test = "dlkjfdkjs";
	str_to_deque(test);
	REQUIRE(is_palindrome(test) == 0); 

    }

    SECTION("Test true word") { 
	std::string test = "civil"; 
	str_to_deque(test); 
	REQUIRE(is_palindrome(test) == 1);
    }
}






