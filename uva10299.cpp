using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<vector>

#define N 100000+10
#define ll long long int

bool prime[N];
vector<int>primes;

void sieve()
{
        long i,j;
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=1000;i++)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

ll phi(ll n)
{
        if(n==1) return 0;
        ll ans=n,j,sz=primes.size(),sq=sqrt(n);
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                if(n%primes[j]==0)
                {
                        ans=ans-ans/primes[j];
                        while(n%primes[j]==0)
                                n/=primes[j];
                }

                if(n==1) break;
        }

        if(n>1) ans=ans-ans/n;

        return ans;
}

int main()
{
        sieve();
        ll n;

        while(scanf("%lld",&n)==1&&n)
        {
                printf("%lld\n",phi(n));
        }

        return 0;
}
