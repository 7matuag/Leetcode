class Solution {
public:
    bool solve(int i,int j,int count,vector<vector<int>>& grid){
        grid[i][j]=-1;
        count++;
        if(count==grid.size()*grid[0].size()){
            return 1;
        }
        if(i+1<grid.size() && j+2<grid[0].size() && grid[i+1][j+2]==count){
            return solve(i+1,j+2,count,grid);
        }
        if(i-1>=0 && j+2<grid[0].size() && grid[i-1][j+2]==count){
            return solve(i-1,j+2,count,grid);
        }
        if(i-2>=0 && j+1<grid[0].size() && grid[i-2][j+1]==count){
            return solve(i-2,j+1,count,grid);
        }
        if(i-2>=0 && j-1>=0 && grid[i-2][j-1]==count){
            return solve(i-2,j-1,count,grid);
        }
        if(i-1>=0 && j-2>=0 && grid[i-1][j-2]==count){
            return solve(i-1,j-2,count,grid);
        }
        if(i+1<grid.size() && j-2>=0 && grid[i+1][j-2]==count){
            return solve(i+1,j-2,count,grid);
        }
        if(i+2<grid.size() && j-1>=0 && grid[i+2][j-1]==count){
            return solve(i+2,j-1,count,grid);
        }
        if(i+2<grid.size() && j+1<grid[0].size() && grid[i+2][j+1]==count){
            return solve(i+2,j+1,count,grid);
        }
        return 0;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return solve(0,0,0,grid);
    }
};
