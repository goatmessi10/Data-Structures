#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 
void makePrimeSeive(vector<int> &p)
{
    std::vector<int> ps(10000,1);
	for (int i = 2; i*i <= 9999 ; ++i)
	{
		if(ps[i]==1)
		{
            for (int j = i*i; j <=9999; j+=i)
            {
            	ps[j]=0;
            }
		}
	}
	for(int i=1000 ; i<=9999 ;i++)
		if(ps[i])
		p.push_back(i);
}
bool conmpare(int a ,int b)
{
	string s1 = to_string(a);
	string s2 = to_string(b);
    int c=0;
	if(s1[0]!=s2[0])
    c++;
    if(s1[1]!=s2[1])
  	c++;
    if(s1[2]!=s2[2])
  	c++;
    if(s1[3]!=s2[3])
  	c++;
    return (c==1);
}
int bfs(std::vector<int> ad[] ,int n , int s , int d)
{
	queue<int> q ;
	vector<int> v(n,0);
	v[s]=1;
	q.push(s);
	
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for(int i=0 ; i <ad[a].size() ; i++)
		{
			if(v[ad[a][i]]==0)
			{
				v[ad[a][i]]=1+v[a];
				q.push(ad[a][i]);
            }
            if(ad[a][i]==d)
            {
              return v[ad[a][i]]-1;
            }
        }
	}

	return v[d];
}
int main(int argc, char const *argv[])
{
	int a , b ;
	cin>>a>>b;
	std::vector<int> primeSeive;
	makePrimeSeive(primeSeive);
	vector<int> adj[primeSeive.size()+1];
	for(int i=0 ; i<primeSeive.size(); i++)
	{
		for(int j=i+1; j<primeSeive.size(); j++)
		{
			if(conmpare(primeSeive[i],primeSeive[j]))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
        }
	}
	
	int idx1 , idx2 ; 
	for(int i=0 ; i<primeSeive.size() ;i++)
	{
		if(primeSeive[i]==a)
			idx1=i;
		
	}
	
	for(int i=0 ; i<primeSeive.size() ;i++)
	{
		if(primeSeive[i]==b)
			idx2=i;
		
	}
	cout<<bfs(adj,primeSeive.size()+1,idx1,idx2);

  return 0 ;
}