class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int, int>>pq;
        for(int i = 0; i < reward1.size(); i++){
            pq.push({reward1[i] - reward2[i] , reward2[i]});
        }
        int i = 0;
        int ans = 0;
        while(i < k){
            ans += (pq.top().first + pq.top().second);
            pq.pop();
            i++;
        }
        while(!pq.empty()){
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
