using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<math.h>
#include<vector>

#define N 10000+10
#define ll unsigned long long int

bool prime[N];
vector<int>primes;
int m[1000000+10],sz;
ll ans[1000000+10];

void sieve()
{
        int i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i+=2)
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

void counting_divisor(ll n)
{
        ll temp=n;
        int j,sq=sqrt(n),cnt;
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                //cout<<"check"<<endl;
                if(n%primes[j]==0)
                {
                        cnt=0;
                        while(n%primes[j]==0)
                        {
                                n/=primes[j];
                                cnt++;
                        }

                        if(m[primes[j]]<cnt)
                        {
                                ans[temp]=ans[temp]*(cnt-m[primes[j]])*primes[j];
                                m[primes[j]]+=cnt-m[primes[j]];
                                while(ans[temp] % 10 == 0)
                                        ans[temp] /= 10;
                                ans[temp] %= 10000000;
                        }
                }

                if(n==1) break;
        }

        if(n>1)
        {
                if(m[n]<1)
                {
                        ans[temp]*=n;
                        m[n]++;
                        while(ans[temp] % 10 == 0)
                                ans[temp] /= 10;
                                //if(ans[temp]>10000000)
                        ans[temp] %= 10000000;
                }
        }
}

int main()
{
        sieve(); sz = primes.size();

        ll i,n;

        ans[0]=0; ans[1]=1;
        for(i=2;i<=1000000;i++){
                ans[i]=ans[i-1];
                counting_divisor(i);
        }
        //cout<<"done :/"<<endl;

        while(scanf("%llu",&n)==1&&n)
        {
                printf("%llu\n",ans[n]%10);
        }

        return 0;
}
