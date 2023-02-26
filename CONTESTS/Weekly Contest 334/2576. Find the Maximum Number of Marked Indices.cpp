class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        int ans=0;
        int i=0,j=(n+1)/2;
        while(j<n){
            if(nums[i]*2<=nums[j]){
                ans+=2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
