#include<queue>
#include<vector>
#include <iostream>
#include <utility>

// MAX TO HOLD IN A SINGLE FILE
#define MAX_SIZE = 10;

using namespace std;

struct file {
    int times;
    int shares;
    string name; 
    int size; 
};

typedef pair<int, file> filesT;

typedef priority_queue<filesT, vector<filesT > > maxHeap;

file createFile(file f, int t, int s, string n, int sz) {
    f.times = t;
    f.shares = s;
    f.name = n;
    f.size = sz;
    return f;
}
void orderFiles(vector<file> f, int maxSize) {
    maxHeap mh; 
    int totalSize = 0; 
    for(int i = 0; i < (int)f.size(); ++i ) {
        int times = f[i].times;
        if (totalSize > maxSize) {
            break;
        }
        mh.push(make_pair(times, f[i]));
        totalSize += f[i].size;
    }

    vector<file> results;
    int count = 2;
    while(count != 0) {
        results.push_back(mh.top().second);
        mh.pop();
        --count;
     }

     for (auto i : results) {
         cout << i.size << endl;
     }
    
    // pop the k biggest files 

}

int main() {

    vector<file> files;
    file apple;
    file microsoft;
    file samsung;
    file citi;
    file fb;
    file file1 = createFile(apple, 2, 10, "apple", 2);
    file file2 = createFile(microsoft,3,5,"microsoft", 4);
    file file3 = createFile(samsung,1, 10, "samsung", 5);
    file file4 = createFile(citi, 5, 10, "citi", 4);
    file file5 = createFile(fb, 9, 2, "facebook", 5);
    files.push_back(file1);
    files.push_back(file2);
    files.push_back(file3);
    files.push_back(file4);
    files.push_back(file5);

    int maxSize = 10;
    orderFiles(files, maxSize);

    

    return 0;
}