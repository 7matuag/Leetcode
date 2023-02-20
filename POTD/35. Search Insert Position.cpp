class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[n-1]){
            return n;
        }
        int ans=0;
        int i=0,j=n-1;
        while(j>=i){
            int m=i+(j-i)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                ans=m;
                j=m-1;
            }
            else{
                ans=m;
                i=m+1;
            }
        }
        if(nums[ans]<target){
            return ans+1;
        }
        return ans;
    }
};
