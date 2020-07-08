class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        vector<vector<int>> ans ;
        for(int i=0;i<nums.size();i++)
        {   if(i>0 && nums[i]==nums[i-1])
            continue;
            int want = -nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==want)
                {
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    if(ans.size()>0)
                    {int n=ans.size()-1;
                        if(ans[n][0]!=temp[0] || ans[n][1]!=temp[1] || ans[n][2]!=temp[2])
                             ans.push_back(temp);
                    }
                    else
                        ans.push_back(temp);
                   
                    j++;
                }
                else if(sum<want)
                {
                    j++;
                }
                else
                    k--;
            }
        }
        return ans;
    }
};
