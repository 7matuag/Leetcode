class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long ans=0;
        long long s=0,e=0;
        for(int i=0;i<n;i++){
            e=max(e,(long long)ranks[i]);
        }
        e=e*(long long)cars*(long long)cars;
        while(e>=s){
            long long m=s+(e-s)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                long long val=ranks[i];
                count+=(sqrt(m/val));
            }
            if(count>=cars){
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
