//O(logn) time complexity
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long bigmod(long long a,long long p,long long M)
{
    if(p==0)
        return 1%M;
    long long x=bigmod(a,p/2,M);
    x=(x*x)%M;
    if(p%2==1)
        x=(a*x)%M;
    return x;
}
int main()
{
    long long n,p;
    cin>>n>>p;
    cout<<bigmod(n,p,MOD)<<endl;
    return 0;
}


