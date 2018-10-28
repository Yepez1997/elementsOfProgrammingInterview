
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
        
        // sets new min sum
        if (running_sum < min_sum) {
            min_sum = running_sum; 
        }
        
        // set new max sum
        if (running_sum - min_sum > max_sum) {
            max_sum = running_sum - min_sum 
        }
    }
    return max_sum; 
}



int main() {
    return 0;
}













