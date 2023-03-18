class cmp{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        unordered_set<int>s;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(s.find(x.second)==s.end()){
                ans+=x.first;
                if(x.second+1<n){
                    s.insert(x.second+1);
                }
                if(x.second-1>=0){
                    s.insert(x.second-1);
                }
            }
        }
        return ans;
    }
};
