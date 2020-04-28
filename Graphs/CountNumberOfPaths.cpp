#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int v;
	vector<int> *arr;
	bool *visited ;
	
public:
	Graph(int v)
	{
		this->v=v;
		arr =new vector<int>[v];
		visited = new bool[v]();
	}
	
   
	void add(int x,int y)
	{
		arr[x].push_back(y);
    }

    void CountPath(int s,int d,int &count)
    {
    	visited[s]=1;
    	if(s==d)
    	count++; 
    	else
    	{
    		for(auto x : arr[s])
    		{
                if(!visited[x])
                {
                	CountPath(x,d,count);
                }
    		}
        }
        visited[s]=0;
    }


 
};

int main()
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
	int c=0;
	g.CountPath(2,3,c);
	cout<<c;
	return 0;

}