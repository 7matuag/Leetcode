class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int ans =INT_MAX;
        int mini1 = INT_MAX,mini2=INT_MAX;
        for(int i = 0;i < nums1.size();i++){
            mini1=min(mini1,nums1[i]);
            for(int j = 0; j <nums2.size();j++){
                 mini2=min(mini2,nums2[j]);
                if(nums1[i] == nums2[j]){
                    ans = min(ans,nums1[i]);
                }
            }
        }
        if(ans == INT_MAX){
            return min(mini1,mini2)*10+max(mini1,mini2);
        }
        return ans;
    }
};
