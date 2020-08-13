vector<int> Solution::maxone(vector<int> &A, int m) {
    int lw=0 ;
    int rw=0 ;
    int bl=0 ;
    int br=0 ;
    int zc=0 ;
    int len=INT_MIN ;
    int Bl=0;
    int n=A.size();
     while(rw<n)
     {
         if(zc<=m)
         {
             if(A[rw]==0)
             zc++;
             rw++;
         }
         if(zc>m)
         {
             
             if(A[lw]==0)
             zc--;
             lw++;
         }
         if(rw-lw>len)
         {
             len=rw-lw;
             Bl=lw;
         }
     }
     vector<int> best ; 
     for(int i=0 ; i<len ; i++)
     {
         best.push_back(i+Bl);
     }
     return best ;
}
