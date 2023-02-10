class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>vis(101,vector<bool>(101,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        if(q.size()==0 || q.size()==n*n){
            return -1;
        }
        int res=-1;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first.first;
            int y=a.first.second;
            int d=a.second;
            res=max(res,d);
            if(x+1<n && !grid[x+1][y] && !vis[x+1][y]){
                q.push({{x+1,y},d+1});
                vis[x+1][y]=1;
            }
            if(y-1>=0 &&  !grid[x][y-1] && !vis[x][y-1]){
                q.push({{x,y-1},d+1});
                vis[x][y-1]=1;
            }
            if(y+1<n &&  !grid[x][y+1] && !vis[x][y+1]){
                q.push({{x,y+1},d+1});
                vis[x][y+1]=1;
            }
            if(x-1>=0 &&  !grid[x-1][y] && !vis[x-1][y]){
                q.push({{x-1,y},d+1});
                vis[x-1][y]=1;
            }
        }
        return res;
    }
};
