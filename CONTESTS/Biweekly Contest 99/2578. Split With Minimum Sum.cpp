class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int i=0;
        int a=0,b=0;
        while(i<s.size()){
            a=a*10+(s[i]-'0');
            i++;
            if(i<s.size()){
                b=b*10+(s[i]-'0');
            }
            i++;
        }
        return a+b;
    }
};
