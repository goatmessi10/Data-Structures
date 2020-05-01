#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int RomanToInteger(string str)
{
        map<string,int> mp ;
        mp["M"]=1000;
        mp["CM"]=900;
        mp["D"]=500;
        mp["CD"]=400;
        mp["C"]=100;
        mp["XC"]=90;
        mp["L"]=50;
        mp["XL"]=40;
        mp["X"]=10;
        mp["IX"]=9;
        mp["V"]=5;
        mp["IV"]=4;
        mp["I"]=1;
        int i=0;
        int ans=0;
        while(i<str.length())
        {   
        	if((i+1)<str.length())
        	{
        	   string ss = str[i]+str[i+1] ;
        	    if(mp.count(ss)>0)
        	   {
                 ans+=mp[ss];
                 i=i+2;
        	   }
        	   else
        	   {
        	   	ans+=mp[str[i]];
        	   	i=i+1;
        	   }
            }
            else
            {
            	ans+=mp[str[i]];
            	i++;
            }

            

        }
        return ans;
 }

int main(int argc, char const *argv[])
{
     string str ;
     cin>>str;
     cout<<RomanToInteger(str);
	return 0;
}