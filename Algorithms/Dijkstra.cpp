#include <iostream>
#include<bits/stdc++.h>
using namespace std ; 
int main(int argc, char const *argv[])
{
	int N,E;
	cin>>N>>E;
	vector<pair<int,int>> adj[N];
	for(int i=0;i<E;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
    }
    std::vector<int> visited(N,0);
    std::vector<int> distance(N,INT_MAX);
    priority_queue<pair<int,int>> q;
    int startingNode ; 
    cin>>startingNode;
    distance[startingNode]=0;
    q.push({0,startingNode});
    // Algorithm
    while(!q.empty())
    {
    	int node = q.top().second;
    	q.pop();
    	if(visited[node])
    		continue;
    	visited[node]=1;
    	for(auto u : adj[node])
    	{
    		if(distance[node]+u.second<distance[u.first]){
    			distance[u.first]=distance[node]+u.second;
    			q.push({distance[u.first],u.first});
    		}
    	}
    }
    for(int i=0;i<N;i++)
    	cout<<startingNode<<" -> "<<distance[i]<<endl;


	return 0;
}