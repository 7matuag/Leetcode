class Solution {
public:
    int findKthPositive(vector<int>& arr,int k) {
        int p=0;
        vector<int>v(2001,0);
        for(auto &i:arr){
            v[i]++;
        }
        for(int i=1;i<2001;i++){
            if(v[i]==0){
                p++;
            }
            if(p==k){
                return i;
            }
        }
        return -1;
    }
};
