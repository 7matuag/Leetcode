class Solution {
public:
    int smallestValue(int n) {
        int ans=0;
        if(n<=5){
            return n;
        }
        int k=n;
        for(int i=2;i<=n/2;i++){
            while(k%i==0){
                ans+=i;
                k/=i;
            }
            if(k==1){
                break;
            }
        }
        if(ans==0){
            return n;
        }
        return smallestValue(ans);
    }
};
