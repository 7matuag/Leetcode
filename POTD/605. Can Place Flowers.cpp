class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n=flowerbed.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(count==k){
                return 1;
            }
            if(!flowerbed[i]){
                if(i-1<0 && i+1>=n){
                    flowerbed[i]=1;
                    count++;
                }
                else if(i-1<0 && i+1<n && !flowerbed[i+1]){
                    flowerbed[i]=1;
                    count++;
                }
                else if(i+1>=n && i-1>=0 && !flowerbed[i-1]){
                    flowerbed[i]=1;
                    count++;
                }
                else if(i-1>=0 && i+1<n && !flowerbed[i-1] && !flowerbed[i+1]){
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return count==k;
    }
};
