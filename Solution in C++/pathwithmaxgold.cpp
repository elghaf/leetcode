//problem : 
/*



example 1 : 
input : grid = [[0,6,0],[0,6,9],[0,6,10]]
output : 6 + 9 + 10 = 25









*/
#include <vector>
#include <iostream>
using namespace std;
    


class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j){
        int ans = 0;
        int org = grid[i][j];
        grid[i][j] = 0;
        
        for(auto& direction : directions){
            int x = direction[0], y = direction[1];
            if(i + x >= 0 && j + y >= 0 && i + x < grid.size() && j + y < grid[0].size() && grid[i+x][j+y] != 0){
                ans = max(ans, grid[i+x][j+y] + dfs(grid, i + x, j + y));
            }
        }
        grid[i][j] = org;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    ans = max(ans, grid[i][j] + dfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
        // Initialize a vector of vectors
    vector<vector<int>> grid_solution = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    int result;
    result = sol.getMaximumGold(grid_solution);


    printf("ayob");
}