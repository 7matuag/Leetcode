class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=INT_MAX;
        int sum=0,maxi=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            maxi=max(weights[i],maxi);
        }
        int i=maxi,j=sum;
        while(j>=i){
            int m=i+(j-i)/2;
            int x=0;
            int k=0;
            while(k<n){
                int s=0;
                while(k<n && s+weights[k]<=m){
                    s+=weights[k];
                    k++;
                }
                x++;
            }
            if(x>days){
                i=m+1;
            }
            else{
                j=m-1;
                ans=min(ans,m);
            }
        }
        return ans;
    }
};
