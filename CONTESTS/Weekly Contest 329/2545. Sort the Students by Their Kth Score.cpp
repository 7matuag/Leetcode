class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>>vp;
        for(int i=0;i<score.size();i++){
            vp.push_back({score[i][k],i});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        vector<vector<int>>ans;
        for(int i=0;i<vp.size();i++){
            ans.push_back(score[vp[i].second]);
        }
        return ans;
    }
};
