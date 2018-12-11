#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

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