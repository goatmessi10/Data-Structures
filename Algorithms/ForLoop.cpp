#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0 ;i<n ;i++)
	   cin>>a[i];
	int count =0 ;
	 for (int i = 0; i < n ; ++i)
	 {
	 	if(a[i]%2==0)
	 		count++;
	 }
	 cout<<count<<'\n';
	
	return 0;
}