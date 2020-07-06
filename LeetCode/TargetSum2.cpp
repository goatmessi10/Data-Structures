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
            if(i!=k && candidates[i]==candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            solve(i+1,sum+candidates[i],target,candidates,curr);
            curr.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=0;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        solve(0,sum,target,candidates,curr);
        return ans;
    }
   
};
