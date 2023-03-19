class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[(nums[i]%value+value)%value]++;
        }
        int count=0;
        while(1){
            if(m[count%value]){
                m[count%value]--;
                count++;
            }
            else{
                break;
            }
        }
        return count; 
    }
};
