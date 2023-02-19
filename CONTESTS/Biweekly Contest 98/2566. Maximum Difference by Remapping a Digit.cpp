class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char a='9';
        for(int i=0;i<s.size();i++){
            if(s[i]!='9'){
                a=s[i];
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==a){
                s[i]='9';
            }
        }
        int maxi=stoi(s);
        s=to_string(num);
        a='9';
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                a=s[i];
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==a){
                s[i]='0';
            }
        }
        int mini=stoi(s);
        return maxi-mini; 
    }
};
