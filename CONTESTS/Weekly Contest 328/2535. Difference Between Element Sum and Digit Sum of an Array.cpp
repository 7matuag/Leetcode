class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0,sum1=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int k=nums[i];
            while(k>0){
                sum1+=k%10;
                k/=10;
            }
        }
        return abs(sum-sum1);
    }
};
