class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>m;
        int presum=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]<0){
                nums[i]+=k;
            }
            presum+=nums[i];
            if(presum%k==0){
                ans++;
            }
            ans+=m[presum%k];
            m[presum%k]++;
        }
        return ans;
    }
};
