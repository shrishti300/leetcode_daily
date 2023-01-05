/* 368. Largest Divisible Subset */

class Solution {
public:
     
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int lp=points[0][1];
        int ans=1;
        for(auto point:points){
            if(point[0]>lp){
                ans++;
                lp=point[1];
            }
            lp=min(point[1],lp);
        }
        return ans;
    }
};