class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int>arr;
        for(auto it : heights)arr.push_back(it);

        sort(arr.begin(),arr.end());

        int cnt = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            cnt += (arr[i] != heights[i]);
        }    

        return cnt;
    }
};