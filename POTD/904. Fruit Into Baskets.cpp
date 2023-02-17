class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int i=0;
        unordered_map<int,int>m;
        for(int j=0;j<fruits.size();j++){
            m[fruits[j]]++;
            if(m.size()==3){
                while(m.size()!=2){
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0){
                        m.erase(fruits[i]);
                    }
                    i++;
                }
            }
            else{
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
