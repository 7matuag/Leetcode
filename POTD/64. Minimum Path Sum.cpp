class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if(i == grid.size() - 1 && j == grid[i].size() - 1){
            return grid[i][j];
        }
        if(i == grid.size() || j == grid[i].size()){
            return INT_MAX;
        }
        if(memo[i][j] != -1){
            return memo[i][j] ;
        }
        int a = dfs(i + 1, j, grid, memo); 
        int b = dfs(i , j + 1, grid, memo);
        return memo[i][j] = grid[i][j] + min(a, b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        return dfs(0, 0, grid, memo);
    }
};
