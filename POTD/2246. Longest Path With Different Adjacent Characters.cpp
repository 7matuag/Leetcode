class Solution {
public: 
    int dfs(int i,vector<vector<int>>&adj,string &s,int &ans){
        int maxi=0,secmaxi=0;
        for(auto &j:adj[i]){
            int res=dfs(j,adj,s,ans);
            if(s[i]!=s[j]){
                if(res>maxi){
                    secmaxi=maxi;
                    maxi=res;
                }
                else if(res>secmaxi){
                    secmaxi=res;
                }
            }
        }
        ans=max(ans,1+maxi+secmaxi);
        return 1+maxi;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int ans=0;
        dfs(0,adj,s,ans);    
        return ans;
    }
};
