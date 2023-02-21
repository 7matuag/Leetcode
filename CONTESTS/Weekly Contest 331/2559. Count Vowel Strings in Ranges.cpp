class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>ans;
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') && (words[i][words[i].size()-1]=='a' || words[i][words[i].size()-1]=='e' || words[i][words[i].size()-1]=='i' || words[i][words[i].size()-1]=='o' || words[i][words[i].size()-1]=='u')){
                temp[i]++;
            }
        }
        for(int i=1;i<n;i++){
            temp[i]=temp[i]+temp[i-1];
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                ans.push_back(temp[queries[i][1]]);
            }
            else{
                ans.push_back(temp[queries[i][1]]-temp[queries[i][0]-1]);
            }
        }
        return ans;
    }
};
