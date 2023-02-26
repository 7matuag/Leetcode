class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans;
        long long int r=0;
        for(int i=0;i<word.size();i++){
            long long int x=word[i]-'0';
            r=(r*10+x)%m;
            if(r==0){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
