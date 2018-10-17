/**
* CountBits: counts the number of bits in an int 
* i.e. whereever there exists a 1 in binary form for 
* the number rep
*/

/*
* example: 
*	* 12 -> 0110 (1byte) -> 2bits
* 	* 2 ->  1000 -> 1 bit
*/

#include <iostream>


using namespace std;

/** countBits: counts bits in an int
*/
short CountBits(unsigned int x) {
	short num_bits = 0; 
	while (x) {
		num_bits += x & 1; 
		x >>= 1;
	}
	return num_bits;
}

int main() {
	
	int number_to_test = 32; 
	short result = CountBits(number_to_test); 
	cout << "result: " << result << endl;
	return 0; 
	
}

