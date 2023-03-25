class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, long long &count){
        vis[i] = 1;
        count++;
        for (auto &j : adj[i]){
            if(!vis[j]){
                dfs(j, adj, vis, count);
            }
        }
        return ;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, 0);
        long long ans = 0;
        vector<long long> temp;
        for (int i = 0; i < n; i++){
            if(!vis[i]){
                long long count = 0;
                dfs(i, adj, vis, count);
                cout<<count<<endl;
                temp.push_back(count);
            }
        }
        for (int i = 0; i < temp.size(); i++){
            ans += (temp[i] * (n - temp [i]));
            n -= temp[i];   
        }
        return ans;
    }
};
