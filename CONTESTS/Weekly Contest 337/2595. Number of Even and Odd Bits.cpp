class Solution {
public:
    vector<int> evenOddBit(int n) {
        int e=0,o=0,cnt=0;
        while(n){
            if(n%2==1 && cnt%2==0){
                e++;
            }
            else if(n%2==1 && cnt%2==1){
                o++;
            }
            n/=2;
            cnt++;
        }
        return {e,o};
    }
};
