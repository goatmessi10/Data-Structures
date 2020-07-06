class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k,int sum , int target , vector<int> &candidates,vector<int> curr)
    {
        if(sum==target)
        {
            ans.push_back(curr);
            return ;
        }
        if(sum>target)
        return;
        
        for(int i=k;i<candidates.size();i++)
        {
            curr.push_back(candidates[i]);
            solve(i,sum+candidates[i],target,candidates,curr);
            curr.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int> curr;
        solve(0,sum,target,candidates,curr);
        return ans;
    }
};
