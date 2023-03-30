class Solution {
public:
    bool solve(string s1 ,string s2, unordered_map<string, int>& m){
        if(s1 == s2){
            return 1;
        }
        int n = s1.size();
        string s = s1 + "_" + s2;
        if(m.find(s) != m.end()){
            return m[s];
        }
        for(int i = 1; i < n ; i++){
            string str1 = s1.substr(0, i);
            string str2 = s1.substr(i, n - i);
            string str3 = s2.substr(0, i);
            string str4 = s2.substr(i, n - i);
            string str5 = s2.substr(0, n - i);
            string str6 = s2.substr(n - i, i);
            if((solve(str1,str3, m) && solve(str2, str4, m)) || (solve(str1,str6, m) && solve(str2, str5, m))){
                return m[s] = 1;
            }
        }
        return m[s] = 0;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string, int> m;
        return solve(s1 ,s2, m);
    }
};
