class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size()){
            while(j<nums.size() && nums[i]==nums[j]){
                j++;
            }
            if(j<nums.size() && nums[i]<nums[j]){
                ans++;
            }
            i++;
            j++;
        }
        return ans;
    }
};
