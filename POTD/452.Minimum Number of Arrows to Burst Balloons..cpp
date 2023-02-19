class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end());
        int mini=points[0][0];
        int maxi=points[0][1];
        for(int i=1;i<points.size();i++){
            if(maxi<points[i][0]){
                ans++;
                maxi=points[i][1];
                mini=points[i][0];
            }
            else{
                maxi=min(maxi,points[i][1]);
                mini=max(mini,points[i][0]);
            }
        }
        return ans;
    }
};
