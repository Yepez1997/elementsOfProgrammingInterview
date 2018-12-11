#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std; 

unsigned long MinTotalWaitTime(vector<unsigned long> service_times) {
	sort(begin(service_times), end(service_times)); 
	
	unsigned long total_wait_time = 0; 
	
	unsigned long queries_remaining;
	
	for (unsigned long i = 0; i < service_times.size(); i++) {
		// 1 2 3 5 
		// first iter 4 - (1) = 3
		// 1 * 3 = 3
		// second iter 4 - 2 = 2
		// 2 * 2 = 4
		// third iter 4 - 3  = 1
		// 3 * 1 = 3
		// 3 + 4 + 3 = 10 
		queries_remaining = service_times.size() - (i + 1);
		cout << "remain: " << queries_remaining << '\n'; 
		cout << "times: " << service_times[i] * queries_remaining << '\n';
		total_wait_time += service_times[i] * queries_remaining; 
		
		cout << "total: " << total_wait_time << '\n'; 
	}
	
	return total_wait_time; 
}


int main() {
	std::vector<unsigned long> times = {1,5,3,2}; 
	unsigned long result = MinTotalWaitTime(times); 
	cout << result << endl; 
	return 0;
}
