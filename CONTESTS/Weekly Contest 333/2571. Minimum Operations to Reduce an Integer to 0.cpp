class Solution {
public:
    int minOperations(int n) {
        if(!(n&(n-1))){
            return 1;
        }
        int x=log2(n);
        int k=min(n-pow(2,x),pow(2,x+1)-n);
        return 1+minOperations(k);
    }
};
