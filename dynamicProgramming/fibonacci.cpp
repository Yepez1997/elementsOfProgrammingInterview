// fibonacci brute force and optimzed algorithms 

#include <iostream>
#include <unordered_map>

unordered_map<int,int> cache; 

/* DP Fibonacci with cache 
 * F(n) runs in linear time O(n) and in O(1) space
 * */
int Fibonacci (int n) { 
    if (n <= 1) {
        return n; 
    }

    else if (!cache.count(n)) {
        cache[n] = Fibonacci(n-2) + Fibonacci()
    }


}

/* FibonacciOpt: helps reduce space complexity by storing in bottom
 * opt fashion 
 */ 
int FibonacciOpt(int n) {
    if (n <= 1) {
        return n;
    }
    int f_minus2 = 0;
    int f_minus1 = 1; 

    for (int i = 2; i <= n; i++) {
        int f = f_minus2 + f_minus1;
        f_minus2 = f_minus1;
        f_minus1 = f;
    }
    return f_minus1; 
}

int main(){ 

    return 0;

}






