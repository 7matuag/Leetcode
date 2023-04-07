class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 1;
        if(i + 1 < grid.size() && grid[i + 1][j] == 0){
            dfs(i + 1, j, grid);
        }
        if(j + 1 < grid[0].size() && grid[i][j + 1] == 0){
            dfs(i, j + 1, grid);
        }
        if(i - 1 >= 0 && grid[i - 1][j] == 0){
            dfs(i - 1, j, grid);
        }
        if(j - 1 >= 0 && grid[i][j - 1] == 0){
            dfs(i, j - 1, grid);
        }
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 0){
                dfs(i, 0, grid);
            }
            if(grid[i][grid[0].size() - 1] == 0){
                dfs(i, grid[0].size() - 1, grid);
            }
        }
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[0][i] == 0){
                dfs(0, i, grid);
            }
            if(grid[grid.size() - 1][i] == 0){
                dfs(grid.size() - 1, i, grid);
            }
        }
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
