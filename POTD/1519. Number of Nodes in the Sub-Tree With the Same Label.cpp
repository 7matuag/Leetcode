class Solution {
public:
    vector<int> dfs(int i,vector<vector<int>>&adj,string &labels,vector<bool>&visited,vector<int>&ans){
        visited[i]=1;
        vector<int>temp(26,0);
        temp[labels[i]-'a']++;
        for(auto &j:adj[i]){
            if(!visited[j]){
                vector<int>v=dfs(j,adj,labels,visited,ans);
                for(int k=0;k<26;k++){
                    temp[k]+=v[k];
                }
            }
        }
        ans[i]+=temp[labels[i]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(n,0);
        vector<bool>visited(n,0);
        dfs(0,adj,labels,visited,ans);
        return ans;
    }
};
