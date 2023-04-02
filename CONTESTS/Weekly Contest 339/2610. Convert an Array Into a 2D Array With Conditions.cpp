class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        int n = m.size();
        while(1){
            vector<int> temp;
            int count = 0;
            for(auto &i : m){
                if(i.second > 0){
                    temp.push_back(i.first);
                    i.second--;
                }
                else{
                    count++;
                }
            }
            if(count == n){
                break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
