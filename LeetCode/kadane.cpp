#include <iostream>
#include<climits>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int *a=new int[n];
int cm=0,gm=INT_MIN;
 for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{
     	
	cm=cm+a[i];
     if(cm>gm)
     {
     	gm=cm;
     }
     if(cm<=0)
     {
     	cm=0;
     }




 }
 cout<<gm;





return 0;

}