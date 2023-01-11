class Solution {
public:
    int dfs(int i,vector<vector<int>>&adj,vector<bool>& hasApple,vector<bool>&visited){
        int t=0;
        visited[i]=1;
        for(auto &j:adj[i]){
            if(!visited[j]){
                t+=dfs(j,adj,hasApple,visited);
            }
        }
        if(i==0){
            return t;
        }
        else if(hasApple[i] || t){
            return t+2;
        }
        else{
            return 0;
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,adj,hasApple,visited);
    }
};
