class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long int ans=0;
        while(k--){
            int x=pq.top();
            pq.pop();
            ans+=x;
            if(x%3==0){
                x=x/3;
            }
            else{
                x=x/3+1;
            }
            pq.push(x);
        }
        return ans;
    }
};
