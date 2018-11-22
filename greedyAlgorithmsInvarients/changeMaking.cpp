#include <iostream>
#include <algorithm>
#include <vector> 


using namespace std; 

int changeMake(int cents) {

    std::vector<int> coins = {100,50,25,10,5,1};
    int num_coins = 0;
    
    for (int c : coins) {
        num_coins += cents / c; 
        cents %= c; 
    }

    return num_coins; 
}

int main() { 
    int result = changeMake(100);
    cout << result << endl;  

    return 0; 
}