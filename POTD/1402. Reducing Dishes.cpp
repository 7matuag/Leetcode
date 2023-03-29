class Solution {
public:
    int solve(int i, int count, vector<int>& satis, vector<vector<int>>& memo){
        if(memo[i][count] != -1){
            return memo[i][count];
        }
        if(i == satis.size()){
            return memo[i][count] = 0;
        }
        return memo[i][count] = max(count * satis[i] + solve(i + 1, count + 1, satis, memo), solve(i + 1, count, satis, memo));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> memo(n + 1, vector<int>(n + 2, -1));
        return solve(0, 1, satisfaction, memo);
    }
};
