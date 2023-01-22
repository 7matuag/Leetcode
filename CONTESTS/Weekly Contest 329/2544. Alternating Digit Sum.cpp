class Solution {
public:
    int alternateDigitSum(int n) {
        int k=log10(n)+1;
        if(k==1){
            return n;
        }
        bool f=0;
        if(k%2){
            f=1;
        }
        int sum=0;
        while(n){
            if(f){
                sum+=(n%10);
                f=0;
            }
            else{
                sum-=(n%10);
                f=1;
            }
            n/=10;
        }
        return sum;
    }
};
