class Solution {
public:
    int ans=0;
    void dfs(int i ,int j ,vector<vector<int>>& grid ,bool **visited ,int row, int col )
    {   
        if(i<0 || j<0 || i==row || j==col || !grid[i][j])
        {
            ans++;
            return;
        }
        if(visited[i][j])
        {
            return;
        }
        visited[i][j]=1;
        dfs(i-1,j,grid,visited,row,col);
        dfs(i,j+1,grid,visited,row,col);
        dfs(i,j-1,grid,visited,row,col);
        dfs(i+1,j,grid,visited,row,col);
        return ;
       
    }
    int islandPerimeter(vector<vector<int>>& grid) {
       int row= grid.size();
        int col= grid[0].size();
        bool **visited= new bool*[row];
        for(int i=0;i<row;i++)
            visited[i]=new bool[col]();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                   dfs(i,j,grid,visited,row,col);
                    break;
                }
            }
        }
        return ans;
        
    }
};
