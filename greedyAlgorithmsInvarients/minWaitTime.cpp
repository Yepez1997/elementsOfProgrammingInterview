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
	
	for (int i = 0, j = task_durations.size() - 1; i < j; ++i, --j) {
		optimum_assignments.emplace_back(
			PairedTask{task_durations[i], task_durations[j]});
	}

	return optimum_assignments; 
}

int main() {
	
	std::vector<int> durations = {5,2,1,6,4,4}; 
	std::vector<PairedTask> results = opTaskAssign(durations); 
	
	// just prints out the values 
	for (PairedTask t: results) {	
		cout << "(" << t.task_one << "," << t.task_two << ")" << endl; 
	}
	
	return 0; 
}
