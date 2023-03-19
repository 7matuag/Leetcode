class Solution {
public:
    void solve(int i,int k,vector<int>& nums,unordered_map<int,int>&m,int &ans){
        if(i==nums.size()){
            if(m.size()!=0){
                ans++;
            }
            return ;
        }
        if(!m[nums[i]+k] && !m[nums[i]-k]){
            m[nums[i]]++;
            solve(i+1,k,nums,m,ans);
            m[nums[i]]--;
        }
        solve(i+1,k,nums,m,ans);
        return ;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>m;
        solve(0,k,nums,m,ans);
        return ans-1;
    }
};
