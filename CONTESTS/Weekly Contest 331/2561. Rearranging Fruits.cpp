class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size();
        int mini=INT_MAX;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[basket1[i]]++;
            m[basket2[i]]++;
            mini=min(mini,min(basket1[i],basket2[i]));
        }
        for(auto &i:m){
            if(i.second%2){
                return -1;
            }
            else{
                i.second/=2;
            }
        }
        vector<int>temp;
        for(auto &i:m){
            while(i.second--){
                temp.push_back(i.first);
            }
        }
        m.clear();
        for(int i=0;i<n;i++){
            m[basket1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(m.find(temp[i])!=m.end()){
                m[temp[i]]--;
                if(m[temp[i]]==0){
                    m.erase(temp[i]);
                }
            }
            else{
                ans.push_back(temp[i]);
            }
        }
        for(auto &i:m){
            while(i.second--){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        long long res=0;
        for(int i=0;i<ans.size()/2;i++){
            res+=min(ans[i],2*mini);
        }
        return res;
    }
};
