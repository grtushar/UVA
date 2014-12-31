using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define size 48000

bool prime[size];
long primes[size];

typedef long long int ll_d;

void sieve()
{
        long long i,j=0,k;
        prime[0]=prime[1]=true;
        primes[j++]=2;
        for(i=4;i<size;i+=2)
                prime[i]=true;

        for(i=3;i<size;i+=2)
        {
                if(prime[i]==false)
                {
                        primes[j++]=i;
                        for(k=i*i;k<size;k+=2*i)
                                prime[k]=true;
                }
        }
}

int main()
{
        ll_d n,j;
        sieve();
        while(scanf("%lld",&n)&&n)
        {
                bool flag=false;
                if(n<0){
                        n*=-1;
                        printf("-%lld = -1 x",n);
                }
                else
                        printf("%lld =",n);

                long sq = sqrt(n);

                for(j=0;primes[j]<=sq;j++)
                {
                        while(n%primes[j]==0)
                        {
                                if(flag){
                                        printf(" x");
                                }
                                n/=primes[j];
                                printf(" %ld",primes[j]);
                                flag=true;
                        }
                        if(n==1)
                                break;
                }

                if(n!=1&&flag)
                        printf(" x %d",n);
                else if(n!=1)
                        printf(" %d",n);
                printf("\n");

        }

        return 0;
}

