class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int ans=INT_MAX,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                nums[i]*=2;
            }
            pq.push(nums[i]);
            mini=min(mini,nums[i]);
        }
        while(!pq.empty() && pq.top()%2==0){
            int x=pq.top();
            pq.pop();
            ans=min(ans,abs(x-mini));
            x/=2;
            mini=min(x,mini);
            pq.push(x);
        }
        ans=min(ans,pq.top()-mini);
        return ans;
    }
};
