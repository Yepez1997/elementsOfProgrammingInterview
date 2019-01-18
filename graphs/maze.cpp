#include <iostream>
#include <stack>
#include <vector>

using namespace std; 
bool path = false;


void dfs(vector<vector<char> > grid,int r,int c) {
    // want to set bounds
         // number rows
     int nr = grid.size();
     // number columns 
     int nc = grid[0].size();
     if (grid[r][c] == 'e'){
             path = true;
     }
     grid[r][c] = 'b';
     /* check row down*/
     if (r - 1 >= 0 && grid[r-1][c] != 'b') {
         dfs(grid, r - 1, c);
     }
     /* check row up*/
     if (r + 1 < nr && grid[r+1][c] != 'b') { 
         dfs(grid, r + 1, c);
     }
         /* check colum left */
     if (c - 1 >= 0 && grid[r][c-1] != 'b') {
         dfs(grid, r, c - 1);
     }
         /*check column right */
     if (c + 1 < nc && grid[r][c+1] != 'b') {
         dfs(grid, r, c + 1);
     }
}

bool isPath(vector<vector<char> > grid) {
    int nr = grid.size();
    if (!nr) return 0;
     /* checks row size */
    int nc = grid[0].size();
 
     /* essentially do dfs */
     // always want to iterate row over column
     for (int r = 0; r < nr; r++){
         for (int c = 0; c < nc; c++) {
             if (grid[r][c] == 'w'){
                dfs(grid, r, c);
             }
         }
     }
    return path;
}


int main() {
    // set up grid 
    // want to define two types of whites ->  
    // b -> denote black area 
    // w -> whites denotes valid path 
    // e -> denotes end 
    // question ? can we reach end ? 
    vector<vector<char> > grid {
        {'w','b','w','w'},
        {'w','b','b','b'},
        {'w','b','b','w'},
        {'w','w','w','w'} };
    // output should be that there is a path 
    //cout << grid[0][0] << endl; 
    bool path = isPath(grid);
    cout << path << endl;


    return 0;
}