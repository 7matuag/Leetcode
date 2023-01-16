class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,int>m;
        int count=0;
        int i=0,j=0;
        while(j<n){
            m[nums[j]]++;
            if(m[nums[j]]>1){
                count+=(m[nums[j]]-1);
            }
            while(count>=k){
                ans+=(n-j);
                if(m[nums[i]]>1){
                    count-=(m[nums[i]]-1);
                }
                m[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
