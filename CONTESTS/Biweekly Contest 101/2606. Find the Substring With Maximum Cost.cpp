class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>m;
        for(int i = 0;i < chars.size();i++){
            m[chars[i]] = vals[i];
        }
        vector<int>temp;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                temp.push_back(s[i] - 'a' + 1);
            }
            else{
                temp.push_back(m[s[i]]);
            }
        }
        int ans = 0,sum =0;
        for(int i =0;i<temp.size();i++){
            sum = max(sum + temp[i], temp[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};
