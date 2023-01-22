class Solution {
public:
    int n;
    void solve(int i,int k,string s,string res,vector<string>&ans){
        if(i==n){
            return ;
        }
        if(k==0){
            string temp=s.substr(i,n-i);
            if(temp.size()!=1 && temp[0]=='0'){

            }
            else{
                long long int x=stol(temp);
                if(x<=255){
                    ans.push_back(res+temp);
                }
            }
            return ;
        }
        for(int j=i;j<n;j++){
            string temp=s.substr(i,j-i+1);
            if(temp.size()!=1 && temp[0]=='0'){
                break;
            }
            long long int x=stol(temp);
            if(x<=255){
                solve(j+1,k-1,s,res+temp+".",ans);
            }
            else{
                break;
            }
        }
    } 
    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        vector<string>ans;
        string res="";
        solve(0,3,s,res,ans);
        return ans;
    }
};
