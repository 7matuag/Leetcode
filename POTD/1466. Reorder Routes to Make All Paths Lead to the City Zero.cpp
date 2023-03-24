class Solution {
public:
    void dfs(int i, int &ans, vector<vector<pair<int, bool>>>& adj, vector<bool>& vis){
        for(auto &j : adj[i]){
            if(!vis[j.first]){
                vis[j.first] = 1;
                if(j.second){
                    ans++;
                }
                dfs(j.first, ans ,adj, vis);
            }
        }
        return ;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector< vector < pair<int, bool> > > adj(n);
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        int ans = 0;
        vector<bool> vis(n, 0);
        vis[0] = 1;
        dfs(0, ans, adj, vis);
        return ans;
    }
};
