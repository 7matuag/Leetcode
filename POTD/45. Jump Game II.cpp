class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int cj=nums[0],mj=nums[0],jmp=1;
        for(int i=1;i<nums.size();i++){
            if(i>mj){
                return -1;
            }
            if(i==nums.size()-1){
                break;
            }
            mj=max(mj,i+nums[i]);
            if(cj==i){
                cj=mj;
                jmp++;
            }
        }
        return jmp;
    }
};
