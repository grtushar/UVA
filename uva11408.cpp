using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>

#define N 5000000+10
#define ll long long int

vector<int>primes;
bool prime[N];
ll ans[N];

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

void pre_cal()
{
        memset(ans,0,sizeof(ans));

        ll i,j;
        for(i=2;i<=5000000;i+=2)
                ans[i]+=2;

        for(i=3;i<=5000000;i+=2)
        {
                if(prime[i]==false)
                {
                        for(j=i;j<=5000000;j+=i)
                                ans[j]+=i;
                }
        }
}



int main()
{
        sieve();
        pre_cal();
        //cout<<"hoise :("<<endl;
        ll a,b,i,cnt;

        while(scanf("%lld",&a)==1&&a&&scanf("%lld",&b)==1)
        {
                cnt=0;
                for(i=a;i<=b;i++)
                {
                        if(prime[ans[i]]==false)
                                cnt++;
                }

                printf("%lld\n",cnt);
        }

        return 0;
}



/*
bool check(ll n)
{
        if(prime[n]==false) return false;
        ll sum=0,j,sq=sqrt(n);
        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                        if(n%primes[j]==0)
                        {
                                sum+=primes[j];
                                while(n%primes[j]==0)
                                {
                                        n/=primes[j];
                                }
                                if(n==1) break;
                        }
        }

        if(n>1) sum+=n;

        if(prime[sum]) return false;
        return true;
}

void pre_cal()
{
        ll i;
        for(i=2;i<=5000000;i++)
        {
                if(check(i))
                        ans[i]=true;
        }
}
*/
