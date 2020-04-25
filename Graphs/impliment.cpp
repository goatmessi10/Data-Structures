#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class mqueue
{
public:
	int q[100000];
	int front=0;
	int rear=0;

	void mpush(int x)
	{
		q[rear]=x;
		rear++;
	}
	int mfront()
	{
		return q[front];
	}
	int mpop()
	{
		int x=q[front];
		front++;
		return x;
	}
	bool mempty()
	{
		if(front==rear)
			return 1;
		else
			return 0;
	}
	
};


void add(vector<int> arr[],int a,int b)
{
	arr[a].push_back(b);
	arr[b].push_back(a);
	
}


void print(vector<int> arr[],int v)
{
	 for(int i=0;i<v;i++)
	 {
	 	for(auto x : arr[i] )
	 		cout<<"-> "<<x;
	 	cout<<endl;
	 }
	 
}


void dfs(vector<int> arr[],bool* visited, int v ,int start)
{
	visited[start]=1;
	cout<<start<<" ";
	for(auto x : arr[start])
	{
		if(!visited[x])
		{
			dfs(arr,visited,v,x);
		}
	}

}

void bfs(vector<int> arr[],int v,int start)
{
mqueue q;
bool *visited = new bool[v]();
q.mpush(start);
visited[start]=1;
while(!q.mempty())
{
	int x=q.mfront();
	q.mpop();
	cout<<x<<" ";
	for(auto i : arr[x])
	{
		if(!visited[i])
		{
			visited[i]=1;
			q.mpush(i);
		}
	}

} 


}
int main(int argc, char const *argv[])
{
	 int v,e;
	 cin>>v>>e;
	 vector<int> arr[v];
	 bool *visited = new bool[v]();
	 for(int i=0;i<e;i++)
	 {
	 	int a,b;
	 	cin>>a>>b;
	 	add(arr,a,b);
	 } 
	 print(arr,v);
	 bfs(arr,v,0);
	 cout<<"\n";
	 dfs(arr,visited,v,0);

	 
	return 0;
}
