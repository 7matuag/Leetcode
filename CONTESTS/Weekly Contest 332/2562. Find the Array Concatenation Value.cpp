class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int i=0,j=nums.size()-1;
        while(j>=i){
            string s="";
            if(i==j){
                s+=to_string(nums[i]);
            }
            else{
                s+=to_string(nums[i])+to_string(nums[j]);
            }
            ans+=stol(s);
            i++;
            j--;
        }
        return ans;
    }
};
