class Solution {
public:
    int solve(string s1,string s2,int n,int m,vector<vector<int>>&memo){
        if(memo[n][m]!=-1){
            return memo[n][m];
        }
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(s1[n-1]==s2[m-1]){
            return memo[n][m]=solve(s1,s2,n-1,m-1,memo);
        }
        return memo[n][m]=1+min(solve(s1,s2,n-1,m-1,memo),min(solve(s1,s2,n,m-1,memo),solve(s1,s2,n-1,m,memo)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n,m,memo);
    }
};
