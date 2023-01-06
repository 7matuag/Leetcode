class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                count++;
            }
        }
        if(count!=pattern.size()-1){
            return 0;
        }
        unordered_map<char,string>m1;
        unordered_map<string,char>m2;
        int k=0;
        int i=0;
        while(i<s.size()){
            string temp="";
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(m1.find(pattern[k])==m1.end() && m2.find(temp)==m2.end()){
                m1[pattern[k]]=temp;
                m2[temp]=pattern[k];
            }
            else if(m1.find(pattern[k])!=m1.end() && m2.find(temp)==m2.end()){
                return 0;
            }
            else if(m1.find(pattern[k])==m1.end() && m2.find(temp)!=m2.end()){
                return 0;
            }
            else{
                if(m1[pattern[k]]!=temp || m2[temp]!=pattern[k]){
                    return 0;
                } 
            }
            i++;
            k++;
        }
        return 1;
    }
};
