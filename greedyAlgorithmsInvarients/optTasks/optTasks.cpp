// given an array of tasks, in ints, returns optimal task assigned 
// each worker is assigned two tasks, each task must be subsequent 

#include <iostream>
#include <vector>

using namespace std; 

struct PairedTask {
	int task_one;
	int task_two; 
}; 

std::vector<PairedTask> opTaskAssign(vector<int> task_durations) {
	sort(begin(task_durations), end(task_durations)); 
	std::vector<PairedTask> optimum_assignments; 
	
	// nice cpp trick to know 
	for (int i = 0, j = task_durations.size() - 1; i < j; ++i, --j) {
		cout << "i " << i << endl; 
		cout << "j " << j << endl; 
		
		optimum_assignments.emplace_back(
			PairedTask{task_durations[i], task_durations[j]});
	}

	return optimum_assignments; 
}

int main() {
	
	std::vector<int> durations = {5,2,1,6,4,4}; 
	std::vector<PairedTask> results = opTaskAssign(durations); 
	
	// just prints out the values 
	cout << "just difff stuff" << endl;  
	for (PairedTask t: results) {	
		cout << "(" << t.task_one << "," << t.task_two << ")" << endl; 
	}
	
	return 0; 
}
