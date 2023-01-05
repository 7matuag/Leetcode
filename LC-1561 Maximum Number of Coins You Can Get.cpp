class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int k=0,i=1;
        int ans=0;
        while(k<piles.size()/3){
            ans+=piles[i];
            k++;
            i+=2;
        }
        return ans;
    }
};
