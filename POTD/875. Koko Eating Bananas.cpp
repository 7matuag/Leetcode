class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini=1,maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int ans=-1;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            long long count=0;
            for(int i=0;i<piles.size();i++){
                long double temp=piles[i]*1.0/mid;
                count+=ceil(temp);
            }
            if(count>h){
                mini=mid+1;
            }
            else{
                ans=mid;
                maxi=mid-1;
            }
        }
        return ans;
    }
};
