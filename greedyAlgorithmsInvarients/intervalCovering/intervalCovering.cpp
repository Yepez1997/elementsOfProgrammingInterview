#include <iostream>
#include <vector>
#include <limits>

using namespace std; 

struct Interval {
	int left; 
	int right; 
}; 

int FindMinimumVisits(vector<Interval> intervals) {
	// learn this cheeaaattt
	sort(begin(intervals), end(intervals), [](const Interval& a, const Interval& b) { return a.right < b.right; });
	
	for (Interval i : intervals) {
		cout << "(" << i.left << "," << i.right << ")" << '\n';
	}
	
	int last_visit_time = numeric_limits<int>::min();
 	int num_visits = 0;
	
	for (const Interval& interval : intervals) { 
		if (interval.left > last_visit_time) {
			last_visit_time = interval.right; 
			cout << last_visit_time << endl;
			++num_visits;
			 
		}
	}
	
	return num_visits; 
}

int main() {
	// set up all Intervals and put them into to a struct 
	vector<Interval> intervals;  
	Interval one{1,2}; 
	Interval two{2,3};
	Interval three{3,4};
	Interval four{2,3};
	Interval five{4,5};
	Interval six{3,4}; 
	
	intervals.push_back(one);
	intervals.push_back(two);
	intervals.push_back(three); 
	intervals.push_back(four); 
	intervals.push_back(five); 
	intervals.push_back(six); 
	
	int result = FindMinimumVisits(intervals); 
	
	cout << result << '\n'; 
}