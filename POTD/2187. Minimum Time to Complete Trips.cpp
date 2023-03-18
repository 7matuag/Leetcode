class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long ans=0;
        long long s=LONG_MAX;
        for(int i=0;i<n;i++){
            s=min(s,(long long)time[i]);
        }
        long long e=s*(long long)totalTrips;
        while(e>=s){
            long long m=s+(e-s)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                count+=(m/time[i]);
                if(count>totalTrips){
                    break;
                }
            }
            if(count>=totalTrips){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};
