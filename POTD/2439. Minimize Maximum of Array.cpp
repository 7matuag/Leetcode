class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        long long presum = 0;
        for (int i = 0; i < nums.size(); i++){
            presum += nums[i];
            int x = ceil((presum * 1.0) / (i + 1));
            ans = max(ans, x);
        }
        return ans;
    }
};
