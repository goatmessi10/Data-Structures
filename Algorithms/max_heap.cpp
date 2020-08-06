void heapify(vector<int> &a ,int n , int i )
{
    int largest=i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && a[l]>a[largest])
    largest=l;
    
    if(r<n && a[r]>a[largest])
    largest=r;
    
    if(i!=largest){
    swap(a[i],a[largest]);
    heapify(a,n,largest);
    }
    
}
void heapsort(vector<int> &a , int n ,int k)
{
    for(int i=(n/2)-1 ;i>=0;i--)
    heapify(a,n,i);
    
    for(int i=n-1 ;i>=0 && k>0 ; k--, i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
vector<int> Solution::solve(vector<int> &A, int B) {
    heapsort(A , A.size() ,B);
    vector<int> ans ;
    for(int i=A.size()-1, k=B ; i>=0 && k>0 ;i--,k--)
    {
        ans.push_back(A[i]);
    }
    return ans ;
    
}