#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void add(vector<int> arr[],int a,int b)
{
	arr[a].push_back(b);
	arr[b].push_back(a);
	
}
int main(int argc, char const *argv[])
{
	 int v,e;
	 cin>>v>>e;
	 vector<int> arr[v];
	 for(int i=0;i<e;i++)
	 {
	 	int a,b;
	 	cin>>a>>b;
	 	add(arr,a,b);
	 } 
	 for(int i=0;i<v;i++)
	 {
	 	for(auto x : arr[i] )
	 		cout<<"-> "<<x;
	 	cout<<endl;
	 }
	 
	return 0;
}
