class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& memo){
        if(memo[i] != -1){
            return memo[i];
        }
        if(i >= days.size()){
            return memo[i] = 0;
        }
        int one,seven,thirty;
        one = costs[0] + solve(i + 1, days, costs, memo);
        int j = i, x = days[i] + 6;
        while(j < days.size() && days[j] <= x){
            j++;
        }
        seven = costs[1] + solve(j, days, costs, memo);
        int k = i, y = days[i] + 29;
        while(k < days.size() && days[k] <= y) {
            k++;
        }
        thirty = costs[2] + solve(k, days, costs, memo);
        return memo[i] = min(one, min(seven, thirty));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size() + 1, -1);
        return solve(0, days, costs, memo);
    }
};
