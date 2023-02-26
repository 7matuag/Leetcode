class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int>a,b,c;
        int presum=0,postsum=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            a.push_back(presum);
        }
        for(int i=nums.size()-1;i>=0;i--){
            postsum+=nums[i];
            b.push_back(postsum);
        }
        reverse(b.begin(),b.end());
        for(int i=0;i<nums.size();i++){
            c.push_back(abs(a[i]-b[i]));
        }
        return c;
    }
};
