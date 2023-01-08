class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int>m1,m2;
        for(int i=0;i<word1.size();i++){
            m1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            m2[word2[i]]++;
        }
        for(auto &i:m1){
            int temp=i.first;
            for(auto &j:m2){
                unordered_map<char,int>um1=m1,um2=m2;
                um2[temp]++;
                um1[j.first]++;
                um1[temp]--;
                um2[j.first]--;
                if(um1[temp]==0){
                    um1.erase(temp);
                }
                if(um2[j.first]==0){
                    um2.erase(j.first);
                }
                if(um1.size()==um2.size()){
                    return 1;
                }
            }
        }
        return 0;
    }
};
