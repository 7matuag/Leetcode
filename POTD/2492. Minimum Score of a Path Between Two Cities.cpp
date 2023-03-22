class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
        vis[i] = 1;
        for(auto &j : adj[i]){
            if(!vis[j]){
                dfs(j, adj, vis);
            }
        }
        return ;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> vis(n + 1, 0);
        dfs(1, adj, vis);
        int ans = INT_MAX;
        for(int i = 0; i < roads.size(); i++){
            if(vis[roads[i][0]] && vis[roads[i][1]]){
                ans = min(ans, roads[i][2]);
            }
        }
        return ans;
    }
};
