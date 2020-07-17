class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0) return ans;
        ans.push_back(1);
        for(int i=1;i<n;i++){
            int end = ans.size()-1;
            int add = 1<<i;
            while(end>=0){
                ans.push_back(ans[end--]+add);
            }
        }
        return ans;
    }
};
