class Solution {
public:
    void dfs(int i, int count, int& ans, vector<bool>& vis, vector<bool>& chk, vector<int>& dist, vector<int>& edges){
        if(i != -1){
            if(!vis[i]){
                vis[i] = 1;
                chk[i] = 1;
                dist[i] = count;
                dfs(edges[i], count + 1, ans, vis, chk, dist, edges);
            }
            else if(chk[i]){
                ans = max(ans, count - dist[i]);
            }
            chk[i] = 0;
        }
    }
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n = edges.size();
        vector<bool> vis(n, 0);
        vector<bool> chk(n, 0);
        vector<int> dist(n, 0);
        for (int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, 0, ans, vis, chk, dist, edges);
            }
        }
        return ans;
    }
};
