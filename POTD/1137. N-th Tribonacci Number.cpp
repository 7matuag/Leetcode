class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n<3){
            return 1;
        }
        vector<int>tab(n+1);
        tab[0]=0;
        tab[1]=1;
        tab[2]=1;
        for(int i=3;i<=n;i++){
            tab[i]=tab[i-3]+tab[i-2]+tab[i-1];
        }
        return tab[n];
    }
};
