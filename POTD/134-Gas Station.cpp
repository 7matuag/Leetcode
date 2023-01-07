//Naive Approach
class Solution {
public:
    bool solve(int i,vector<int>&gas,vector<int>&cost){
        int gasin=gas[i]-cost[i];
        for(int j=(i+1)%gas.size();;j=(j+1)%gas.size()){
            if(j==i){
                return 1;
            }
            else if(gasin+gas[j]>=cost[j]){
                gasin+=gas[j];
                gasin-=cost[j];
            }
            else{
                return 0;
            }
        }
        return 0;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            if(gas[i]>=cost[i] && solve(i,gas,cost)){
                return i;
            }
        }
        return -1;
    }
};


//Optimal Solution (Greedy)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0;
        int tgas=0,tcost=0,gasin=0;
        for(int i=0;i<gas.size();i++){
            tgas+=gas[i];
            tcost+=cost[i];
            gasin+=(gas[i]-cost[i]);
            if(gasin<0){
                ans=i+1;
                gasin=0;
            }
        }
        if(tgas-tcost>=0){
            return ans;
        }
        return -1;
    }
};
