using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>

#define N 11000
#define eps 1e-9

typedef long long int ll_d;

bool prime[N],ans[N];
vector<int>primes;

void sieve()
{
        ll_d sq=sqrt(N),i,k;
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(k=i*i;k<N;k+=2*i)
                                prime[k]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

ll_d Euler_prime(int n)
{
        return (n*n)+n+41;
}

bool prime_check(ll_d n)
{
        if(n<N&&prime[n]==false)
                return true;
        int i,sz=primes.size(),sq=sqrt(n);
        for(i=0;i<sz&&primes[i]<=sq;i++)
        {
                if(n%primes[i]==0)
                        return false;
        }
        return true;
}

void calc()
{
        for(int i=0;i<10002;i++)
        {
                ll_d k=Euler_prime(i);
                if(prime_check(k))
                        ans[i]=true;
        }
}

int main()
{
        int a,b,i,cnt1;
        sieve();
        calc();

        while(scanf("%d%d",&a,&b)==2)
        {
                cnt1=0;
                for(i=a;i<=b;i++)
                {
                        if(ans[i]) cnt1++;
                }

                //printf("%.2lf\n",(double)((100.0*(double)cnt1)/(double)(b-a+1)));
               printf("%.2lf\n",(cnt1*100.0)/((b-a+1)*1.0)+eps);
        }

        return 0;
}
