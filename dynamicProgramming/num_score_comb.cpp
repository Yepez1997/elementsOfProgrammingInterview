

#include <iostream>
#include <vector> 

using namespace std; 



//TEST

int NumCombinationsForFinalScore(int final_Score, const vector<int>& individual_play_scores) {
    
    vector<vector<int>> num_combinations_for_score(size(individual_play_scores), vector<int>(final_Score + 1, 0));
    for (int i = 0; i < size(individual_play_scores); ++i) {
        num_combinations_for_score[i][0] = 1; 
        for (int j = 1; j <= final_Score; ++j) {
            int without_this_play = i >= 1 ? num_combinations_for_score[i-1][j] : 0; 
            int with_this_play = j >= individual_play_scores[i] ? num_combinations_for_score[i][j - individual_play_scores[i]] : 0 ; 
            num_combinations_for_score[i][j] = with_this_play + without_this_play; 
        }
    }
    return num_combinations_for_score.back().back(); 
}



int main(){
    return 0;
}















