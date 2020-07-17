#include<iostream>
using namespace std; 
int main(int argc, char const *argv[])
{
	int d=256;
	int mod=101;
	string pat;
	string text;
	cin>>pat>>text;
	int patLength=pat.length();
	int textLength=text.length();
    int h=1;
    int patHashCode=0;
    int textHashCode=0;
    for (int i = 0; i < patLength-1; ++i)
    {
    	h*=d;
    }
    for (int i = 0; i < patLength; ++i)
    {
    	patHashCode=d*patHashCode+pat[i];
    }
    for (int i = 0; i < patLength; ++i)
    {
    	textHashCode=d*textHashCode+text[i];
    }
  for (int i = 0; i <= textLength-patLength ; ++i)
  {
     	if(patHashCode==textHashCode)
  	   {
  		int j;
      for ( j = 0 ; j < patLength ; j++)
      {
      	if(pat[j]!=text[j+i])
          break ;
           }
           if(j==patLength)
           	cout<<"Pattern found at "<<i<<"th Position"<<endl;
       }
       textHashCode= d*( textHashCode - h*(text[i]))+text[i+patLength];
    }



	return 0;
}