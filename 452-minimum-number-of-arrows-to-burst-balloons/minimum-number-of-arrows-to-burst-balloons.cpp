class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), cmp);

        int end = points[0][1];
        int cnt = 1;
        int i = 0;
        while( i < n){
            if(points[i][0] > end){
                cnt++;
                end = points[i][1];
            }
            i++;
        }

        return cnt;
    }
};