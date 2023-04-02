class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans =0 ;
        for(int i=0;i<s.size();i ++){
            int c1 = 0,c0=0;
            for (int j = i; j < s.size(); j++ ){
                if(s[j]=='0'){
                    if(c1){
                        c1 =0;
                        c0 =0;
                    }
                    else{
                        c0++;
                    }
                }
                else{
                    c1++;
                }
                if(c1 == c0){
                    ans = max(ans, c1 + c0);
                }
                else if(c1 > c0){
                    if(c0){
                        c1=0;
                        c0=0;
                    }
                    else{
                        c1++;
                    }
                }
            }
        }
        return ans;
    }
};
