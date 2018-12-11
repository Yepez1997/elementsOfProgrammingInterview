#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string>
#include <stack>


using namespace std; 

int evaluate(const string& expression) {
	
	stack<int> inter_result;
	stringstream ss(expression); 
	string token; 
	const char delimeter = ',';
	
	const unordered_map<string, function<int(int, int)>> kOperators = {
		// completion functions ? 
		{"+", [](int x, int y) -> int {return x + y;}},
		{"-", [](int x, int y) -> int {return x - y;}},
		{"*", [](int x, int y) -> int {return x * y;}},
		{"/", [](int x, int y) -> int {return x / y;}}};
	
	while (getline(ss, token, delimeter)) {
		if (kOperators.count(token)) {
			const int y = inter_result.top(); 
			inter_result.pop();
			const int x = inter_result.top(); 
			inter_result.pop(); 
			inter_result.emplace(kOperators.at(token)(x,y));
		}
		else {
			// string to int ? 
			inter_result.emplace(stoi(token)); 
		}
	}
	return inter_result.top(); 
}

int main() {
	
	string input = "3,4,+,2,*,1"; 
	int result = evaluate(input);
	cout << result << endl;
	 
	return 0; 
}