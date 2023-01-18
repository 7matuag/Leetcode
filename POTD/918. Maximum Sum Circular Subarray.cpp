class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=INT_MIN,subsum=0,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            subsum=max(subsum+nums[i],nums[i]);
            ans=max(ans,subsum);
        }
        subsum=0;
        int ans1=INT_MAX;
        for(int i=0;i<n;i++){
            subsum=min(subsum+nums[i],nums[i]);
            ans1=min(ans1,subsum);
        }
        if(ans1>=0 || ans1==INT_MAX || ans1==sum){
            return ans;
        }
        cout<<ans1<<" "<<ans<<" "<<sum;
        return max(ans,sum-ans1);
    }
};
