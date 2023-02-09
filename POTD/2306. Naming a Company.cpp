class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>s;
        for(auto &i:ideas){
            s.insert(i);
        }
        vector<vector<int>>tab(26,vector<int>(26,0));
        long long k=0;
        for(int i=0;i<ideas.size();i++){
            for(int j=0;j<26;j++){
                char ch=j+'a';
                swap(ideas[i][0],ch);
                if(s.find(ideas[i])==s.end()){
                    tab[ch-'a'][j]++;
                }
                swap(ideas[i][0],ch);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                k+=(tab[i][j]*tab[j][i]);
            }
        }
        return k;
    }
};
