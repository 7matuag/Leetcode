class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int count=1;
        long long mod=1e9+7;
        sort(ranges.begin(),ranges.end());
        int s=ranges[0][0],e=ranges[0][1];
        for(int i=1;i<ranges.size();i++){
            if(ranges[i][0]>=s && ranges[i][0]<=e){
                e=max(e,ranges[i][1]);
            }
            else{
                count++;
                s=ranges[i][0];
                e=ranges[i][1];
            }
        }
        long long ans=1;
        while(count--){
            ans*=2;
            ans=ans%mod;
        }
        return ans%mod;
    }
};
