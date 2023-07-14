#include<bits/stdc++.h>
using namespace std;
int squarRoot(int n)
{ 
     if(n==0)
{
    return 0;
}
     int l=1, h=n , mid= 0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if((mid*mid)==n)
        {
           return mid; 
        }
        
        if((mid*mid)>n)
        {
            h=mid-1;
        
        }
        else 
        l= mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cin>> n;
    int m=squarRoot(n);
    cout<<m ;
 
    return 0;
}