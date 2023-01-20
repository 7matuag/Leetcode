class Solution {
public:
    set<vector<int>>s;
    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()>1 && s.find(temp)==s.end()){
            s.insert(temp);
            ans.push_back(temp);
        }
        if(i==nums.size()){
            return ;
        }
        if(temp.size()==0 || nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
            solve(i+1,nums,temp,ans);
        }
        else{
            solve(i+1,nums,temp,ans);
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};
