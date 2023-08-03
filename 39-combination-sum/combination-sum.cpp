class Solution {
public:

    void f(vector<int>&candidates,int target,vector<vector<int>>&arr,vector<int>&temp,int idx)
    {
        if(target == 0)
        {
            arr.push_back(temp);
            return;
        }
        if(idx == candidates.size())
        {
            return;
        }

        if(candidates[idx] <= target)
        {
            temp.push_back(candidates[idx]);
            f(candidates,target-candidates[idx],arr,temp,idx);
            temp.pop_back();
        }

        f(candidates,target,arr,temp,idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>>arr;
        vector<int>temp;

        f(candidates,target,arr,temp,0);

        return arr;    
    }
};