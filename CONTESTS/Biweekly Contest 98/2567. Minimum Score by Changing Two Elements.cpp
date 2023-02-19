class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()<4){
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans1=INT_MAX,ans2=INT_MAX;
        int a=nums[0],b=nums[1];
        nums[0]=nums[2];
        nums[1]=nums[2];
        for(int i=0;i<n-1;i++){
            ans1=min(ans1,nums[i+1]-nums[i]);
        }
        ans1+=(nums[n-1]-nums[0]);
        nums[0]=a;
        nums[1]=b;
        int c=nums[n-2],d=nums[n-1];
        nums[n-2]=nums[n-3];
        nums[n-1]=nums[n-3];
        for(int i=0;i<n-1;i++){
            ans2=min(ans2,nums[i+1]-nums[i]);
        }
        ans2+=(nums[n-1]-nums[0]);
        nums[n-2]=c;
        nums[n-1]=d;
        return min(nums[n-2]-nums[1],min(ans1,ans2));
    }
};
