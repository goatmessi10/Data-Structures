#include <iostream>
using namespace std;
int findWays(int **dp , int *coin,int n , int amount)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=amount;j++)
	{
        if(j>=coin[i-1])
        { 
        	int picked = dp[i][j-coin[i-1]] == 0 ? 0 : dp[i][j-coin[i-1]];
        	int notPicked = dp[i-1][j] ;
        	dp[i][j]=picked+notPicked;
        }
        else
        	dp[i][j]=dp[i-1][j];
    }
    return dp[n][amount];
}
int main(int argc, char const *argv[])
{
	int n,amount;
	cin>>n>>amount;
	int *coin=new int[n];
	for(int i=0;i<n;i++)
		cin>>coin[i];
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=new int[amount+1]();
	for(int i=0;i<=n;i++)
		dp[i][0]=1;

   cout<<findWays(dp,coin,n,amount);


	return 0;
}