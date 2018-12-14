/* twoSum: let alpha be an array with elements x0, x1, ... xn 
 * in a set of real numbers. Given alpha deteramine if elements 
 * i and j in the array x0 <= i , j <= n add up to a target sum.
 * if so return true, else return fasle
 * */

#include <iostream>
#include <vector>
#include <algorithm>

/* note this is just one implementaion, can be solved wiht a map */
using namespace std; 
/* algorithm for finding two sum*/
bool hasTwoSum(vector<int>& a, int t) {
	sort(begin(a), end(a)); 
	
	int i = 0; 
	int j = (a.size() - 1);
	
	while (i < j) {
		if (a[i] + a[j] == t) {
			return true;
		}
		else if (a[i] + a[j] < t) {
			i++;
		}
		else {
			// greater than
			j--; 
		}
	}
	
	return false; 	
}

int main() {
	
	vector<int> values = {1,2,3,5,52,1};
	int t = 8; // target
	bool hasSum = hasTwoSum(values, t); 
	
	cout << "Target: " << t << " has two sum: " << hasSum << '\n'; 
	  
	return 0; 
}

// other stuff to note : common in interview is indexing in the right places ...
//  
