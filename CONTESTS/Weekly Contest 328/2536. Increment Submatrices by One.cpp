class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++){
            ans[queries[i][0]][queries[i][1]]+=1;
            if(queries[i][2]+1<n && queries[i][3]+1<n){
                ans[queries[i][2]+1][queries[i][3]+1]+=1;
            }
            if(queries[i][2]+1<n){
                ans[queries[i][2]+1][queries[i][1]]-=1;
            }
            if(queries[i][3]+1<n){
                ans[queries[i][0]][queries[i][3]+1]-=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]+=ans[i-1][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};
