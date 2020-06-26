class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid,int i,int j,bool** visited)
    {
        if(grid[i][j]==1)
            return 1;
        if(grid[i][j]==-1)
            return 0;
        if(visited[i][j]==1)
            return 1;
        visited[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n )
            return 0 ;
        
      
              
               bool up= dfs(grid,i-1,j,visited);
             
               bool down= dfs(grid,i+1,j,visited);
            
               bool right= dfs(grid,i,j+1,visited);
              
               bool left= dfs(grid,i,j-1,visited);
           
         if(up && down && left && right)
             return 1;
        else
            return 0;
       
     
        
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        bool**visited = new bool*[grid.size()];
        for(int i=0 ; i<grid.size() ;i++)
            visited[i]=new bool[grid[0].size()]();
        int ans=0;
        for(int i=0 ; i<grid.size() ;i++)
        {
            if(grid[i][0]==0)
                grid[i][0]=-1;
            if(grid[i][(grid[0].size())-1]==0)
             grid[i][(grid[0].size())-1]=-1;
        }
         for(int i=0 ; i<grid[0].size() ;i++)
        {
            if(grid[0][i]==0)
                grid[0][i]=-1;
            if(grid[grid.size()-1][i]==0)
            grid[grid.size()-1][i]=-1;
        }
       
        for(int i=1; i<grid.size()-1 ;i++)
        {
            for(int j=1 ;j<grid[0].size()-1; j++)
            {
                if(grid[i][j]==0 && visited[i][j]==0)
                  if(dfs(grid,i,j,visited))
                  {  ans++;
                   
                  }
            }
        }
         
        return ans;
    }
};
