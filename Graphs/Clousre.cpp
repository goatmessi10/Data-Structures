#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	vector<int> *arr;
	
public:
	Graph(int v)
	{
		this->v=v;
		arr =new vector<int>[v];
	
	}


	void add(int x,int y)
	{
		arr[x].push_back(y);
    }


	void dfs(bool **a,int s,int d)
	{ 
      a[s][d]=1;

      for(auto x : arr[d])
      {
      	if(!a[s][x])
      	{
      		dfs(a,s,x);
      	}
      }
    }


	void clousre()
	{
       bool **a= new bool*[v];
       for(int i=0;i<v;i++)
       	a[i]=new bool[v]();

       for(int i=0;i<v;i++)
       	dfs(a,i,i);

       for(int i=0;i<v;i++)
       {
       	for(int j=0;j<v;j++)
       	{
       		cout<<a[i][j]<<" ";
       	}
       	cout<<endl;
       }
	}

	
};
int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		g.add(x,y);
	}
    g.clousre();

	return 0;
}