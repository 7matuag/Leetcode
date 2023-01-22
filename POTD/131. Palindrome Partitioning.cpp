class Solution {
public:
    bool pal(string &s){
        int i=0,j=s.size()-1;
        while(j>i){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    void solve(int i,string &s,vector<string>&res,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(res);
            return ;
        }
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(pal(temp)){
                res.push_back(temp);
                solve(j+1,s,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        solve(0,s,res,ans);
        return ans;
    }
};
