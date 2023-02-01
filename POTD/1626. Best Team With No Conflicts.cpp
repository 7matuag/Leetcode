class Solution {
public:
    int solve(int i,vector<pair<int,int>>&vp,int j,vector<vector<int>>&memo){
        if(i>=vp.size()){
            return 0;
        }
        if(memo[j+1][i]!=-1){
            return memo[j+1][i];
        }
        int p=0,np=0;
        if(j==-1 || vp[i].second<=vp[j].second){
            p=vp[i].first+solve(i+1,vp,i,memo);
        }
        np=solve(i+1,vp,j,memo);
        return memo[j+1][i]=max(p,np);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>memo(ages.size()+1,vector<int>(ages.size()+1,-1));
        vector<pair<int,int>>vp;
        for(int i=0;i<ages.size();i++){
            vp.push_back({scores[i],ages[i]});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        return solve(0,vp,-1,memo);
    }
};
