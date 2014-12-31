using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>

#define N 10000000+10
#define ll long long int

vector<int>primes;
ll prime[N];

void sieve()
{
        ll i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i++)
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

int main()
{
        sieve();
        ll n,i,j,cnt,ans,sz=primes.size();

        while(scanf("%lld",&n)&&n)
        {
                if(n<0) n*=-1;
                cnt=0,ans=-1;
                for(j=0;j<sz&&primes[j]<n;j++)
                {
                        if(n%primes[j]==0)
                        {
                                cnt++;
                                while(n%primes[j]==0)
                                {
                                        n/=primes[j];
                                }
                                ans=primes[j];

                                if(n==1) break;
                        }
                }

                if(n==1)
                {
                        if(cnt>1) printf("%lld\n",ans);
                        else printf("-1\n");
                }

                else
                {
                        if(cnt>0) printf("%lld\n",n);
                        else printf("-1\n");
                }
        }

        return 0;
}
