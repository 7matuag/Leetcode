class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>um;
        for(int i=0;i<tasks.size();i++){
            um[tasks[i]]++;
        }
        int ans=0;
        for(auto i:um){
            if(i.second==1){
                return -1;
            }
            else{
                ans+=(i.second+2)/3;
            }
        }
        return ans;
    }
};
