#include <iostream>
#include <algorithm>
#include <array>


using namespace std; 
  
const int kNumPegs = 5;

/*main alg and juice */
void ComputeTowerHanoiSteps(int num_rings_to_move
        ,array<stack<int>,kNumPegs> &pegs, int from_peg, int to_peg, int use_peg, vector<vector<int>>* result_ptr) {
    if (num_rings_to_move >= 0) {
        ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg, to_peg, result_ptr);
        // in essence transfer pegs from one to another 
        pegs[to_peg].push(pegs[from_peg].top());
        pegs[from_top].pop(); 
        result_ptr -> emplace_back(vector<int>{from_peg, to_peg}); 
        ComputeTowerHanoiSteps(num_rings_to_move -1, pegs, use_peg, to_peg, from_peg, result_ptr); 
    }
}   


/*set up tower using an array of stacks */
vector<vector<int>> ComputeTowerHanoi(int num_rings) {
    array<stack<int>,kNumPegs> pegs; 
    for (int i = num_rings; i >= 1; --i) {
        pegs[0].push_back(i);
    }
}

/*results vector*/
vector<vector<int>> results; 

ComputeTowerHanoiSteps(num_rings,pegs, 0, 1, 2, &results); 

return result; 

/*temporary*/
int main() {

    return 0; 
}
