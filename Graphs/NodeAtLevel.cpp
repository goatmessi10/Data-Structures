#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Nod
{
  int value ; 
  int level ;	
};
class Graph
{
	int v;
	vector<int> *arr;
	Nod *q ;
	int fr,re ;
	
public:
	Graph(int v)
	{
		this->v=v;
		arr =new vector<int>[v];
		q=new Nod[1000];
		fr =0 ; 
		re= 0 ;

	}
	void push(int a,int b)
	{
		Nod nn ;
		nn.level = b;
		nn.value =a ;
        q[re]=nn;
        re++;
	}
	void pop()
	{
	 fr++;  
	}
	bool empty()
	{
		if(fr==re)
			return 1;
		return 0;
	}
	Nod fron()
	{
		return q[fr];
	}

   
	void add(int x,int y)
	{
		arr[x].push_back(y);
    }
    void PrintNode(bool *visited,int lvl)
    {
         push(0,1);
         visited[0]=1; 
         while(!empty())
         {
         	Nod x = fron();
             pop();
             if(x.level==lvl)
             	cout<<x.value<<" ";
         	for(auto nn : arr[x.value])
         	{
         		if(!visited[nn])
         		{
         			visited[nn]=1;
         			push(nn,x.level+1);
         		}
         	}

         }




    }

};
int main(int argc, char const *argv[])
{
	
	int e,v;
	cin>>e>>v;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		int aa,bb;
		cin>>aa>>bb;
		g.add(aa,bb);
	}
	bool *visited= new bool[v]();
	g.PrintNode(visited,2);

	return 0;
}