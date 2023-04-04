class Solution {
public:
    int partitionString(string s) {
        int i = 0;
        long long f = 0;
        int count = 1;
        int n = s.size();
        for (int i = 0; i < n; i++){
            int k = s[i] - 'a';
            if(f & (1 << k)){
                count++;
                f = 0;
            }
            f = f | (1 << k);
        }
        return count;
    }
};
