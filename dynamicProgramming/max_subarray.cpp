
#include <iostream>
#include <vector> 


using namespace std; 


/*  find_max_subarray: finds max subarray in a vector (c++)
 *  algorithm achieves O(n)
 * */
int find_max_subarray(const vector<int>& A) {
   
    int min_sum = 0;    
    int max_sum = 0;
    int running_sum = 0; 

    // finds max sum but not indicies 
    for (int i = 0; i < size(A); i++) {
        running_sum += A[i]; 
		// -3
		// 1
		// 6
        
        // sets new min sum
		// - 3 < 0 
		// 1 < 0 
		// 6 < 0 
        if (running_sum < min_sum) {
			// -3 
            min_sum = running_sum; 
        }
        
        // set new max sum
		// -3 -3 > 0 true
		// -6 > 0 ? nope 
		// 1 -- 3 = 4 > 0 
		// 1 - 0 > 0
		// 6 - 0 > 1 
        if (running_sum - min_sum > max_sum) {
			// max sum = -3
			// max sum = 1
			// max sum  = 6
			// max sum hat = 4
            max_sum = running_sum - min_sum 
        }
    }
    return max_sum; 
}



int main() {
	const vector<int> inputs = {-3,4,5,2,3,-2}
    return 0;
}













