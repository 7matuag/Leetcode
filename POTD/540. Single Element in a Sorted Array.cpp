class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        while(j>i){
            int m=i+(j-i)/2;
            if((m>0 && nums[m-1]==nums[m])){
                if(m%2){
                    i=m+1;
                }
                else{
                    j=m-1;
                }
            }
            else if((m+1<n && nums[m]==nums[m+1])){
                if(m%2==0){
                    i=m+1;
                }
                else{
                    j=m-1;
                }
            }
            else{
                return nums[m];
            }
        }
        return nums[j];
    }
};
