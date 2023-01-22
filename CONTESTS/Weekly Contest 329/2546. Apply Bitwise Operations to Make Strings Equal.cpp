class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n=s.size();
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
            }
        }
        for(int i=0;i<n;i++){
            if(target[i]=='1'){
                cnt1++;
            }
        }
        if((cnt0==n && cnt1>=1) || (cnt0<n && cnt1==0)){
            return 0;
        }
        return 1;
    }
};
