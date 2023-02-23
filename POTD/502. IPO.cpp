class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({profits[i],capital[i]});
        }
        queue<pair<int,int>>q;
        while(k>0 && !pq.empty()){
            while(!pq.empty() && pq.top().second>w){
                q.push(pq.top());
                pq.pop();
            }
            if(pq.empty()){
                break;
            }
            if(!pq.empty() && pq.top().second<=w){
                w+=pq.top().first;
                k--;
                pq.pop();
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return w;
    }
};
