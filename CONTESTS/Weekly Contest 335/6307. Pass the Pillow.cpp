class Solution {
public:
    int passThePillow(int n, int time) {
        bool f=1;
        int ans=1;
        while(time--){
            if(ans==n){
                f=0;
            }
            else if(ans==1){
                f=1;
            }
            if(f){
                ans++;
            }
            else{
                ans--;
            }
        }
        return ans;
    }
};
