using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

#define size 1000000+10

bool prime[size];
long long primes[size];

void sieve()
{
        long long i,j=0,k,sq=sqrt(size);
        prime[0]=prime[1]=true;
        primes[j++]=2;
        for(i=4;i<size;i+=2)
                prime[i]=true;

        for(i=3;i<=sq+1;i+=2)
        {
                if(prime[i]==false)
                {
                        primes[j++]=i;
                        for(k=i*i;k<size;k+=2*i)
                                prime[k]=true;
                }
        }

        for(;i<size;i+=2)
                primes[j++]=i;
}

int main()
{
        long long n,i;
        sieve();
        while(scanf("%lld",&n)&&n)
        {
                bool flag=true;
                for(i=0;flag&&primes[i]<=n/2;i++)
                {
                        if(prime[n-primes[i]]==false)
                        {
                                printf("%lld = %lld + %lld\n",n,primes[i],n-primes[i]);
                                flag=false;
                        }
                }
        }

        return 0;
}
