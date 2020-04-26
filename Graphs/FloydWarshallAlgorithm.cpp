#include <iostream>
using namespace std;
#define INF 99999 
void printsolution(int graph[][4])
{
	int v=4;
int dist[v][v],i,j,k;
for(int i=0;i<v;i++)
for(int j=0;j<v;j++)
	dist[i][j]=graph[i][j];



  for(int k=0;k<v;k++)
  {
  	for(int i=0;i<v;i++)
  	{
  		for(int j=0;j<v;j++)
  		{
  			if(dist[i][k]+dist[k][j]<dist[i][j])
  				dist[i][j]=dist[i][k]+dist[k][j];
  		}
  	}
  }

 for(int i=0;i<v;i++)
 {
 	for(int j=0;j<v;j++)
 		cout<<dist[i][j]<<" ";
 	cout<<endl;
 }


}

int main(int argc, char const *argv[])
{
	//enter graph 
	
	    int graph[4][4] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
    printsolution(graph);
	return 0;
}