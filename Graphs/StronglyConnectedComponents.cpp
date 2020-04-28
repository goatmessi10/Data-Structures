void fun(vector<int> adj[],int v,stack<int> &st , int s,bool *visited)
{
    
    visited[s]=1;
    for(auto x : adj[s])
    {
        if(!visited[x])
        {
            fun(adj,v,st,x,visited);
        }
    }
    st.push(s);
    
}
void fill(vector<int> nadj[], vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x : adj[i])
        {
            nadj[x].push_back(i);
        }
    }
    
}
void dfs(vector<int> adj[] , int v ,bool *visited,int start)
{ 
 visited[start]=1;
 
 for(auto x : adj[start])
 {
     if(!visited[x])
     {
         dfs(adj,v,visited,x);
     }
 }
    
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> s ;
    bool *visited = new bool[V]();
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
    fun(adj,V,s,i,visited);
    }
    for(int i=0;i<V;i++)
    visited[i]=0;
    vector<int> nadj[V];
    fill(nadj,adj,V);
    int count =0 ;
      while(!s.empty())
      {
        int tbp=s.top();
        s.pop();
        if(!visited[tbp])
        {
            count++;
        visited[tbp]=1;
        dfs(nadj,V,visited,tbp);
        }
      }
       return count ;

}