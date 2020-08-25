//Sieve of erastosthenes for finding primes in a large range in O(n*log(logn))
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool isprime[N+50];
vector<int> prime;
void sieve();
int main()
{
    sieve();
    int n;
    cout<<"Print primes till?";
    cin>>n;
    for(auto x: prime)
    {
        if(x>n)
            break;
        cout<<x<<" ";
    }
    cout<<endl;
}
void sieve()
{
    for(int i=4;i<=N;i+=2)
        isprime[i]=true;
    isprime[1]=true,isprime[2]=false;
    for(int i=3;i*i<=N;i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                isprime[j]=true;
            }
        }
    }
    prime.emplace_back(2);
    for(int i=3;i<=N;i+=2)
    {
        if(!isprime[i])
            prime.push_back(i);
    }
}

