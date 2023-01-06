class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0,s=0;
        for(int i=0;i<word.length();++i){
            if(word[i]>='A' && word[i]<='Z') {
                c++;
            } 
            else{
                s++;
            }
        }
        if(c==word.length() || (c==1 && word[0]>='A' && word[0]<='Z') || s==word.length()){
            return true;
        }
        return false;
    }
};
