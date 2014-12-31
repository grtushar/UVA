using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

bool prime[1050];
int primes[1050];

void sieve()
{
        int i,j=0,k;
        prime[0]=true;
        primes[j++]=1;
        primes[j++]=2;
        for(i=4;i<1050;i+=2)
                prime[i]=true;

        for(i=3;i<1050;i+=2)
        {
                if(prime[i]==false)
                {
                        primes[j++]=i;
                        for(k=i*i;k<1050;k+=2*i)
                                prime[k]=true;
                }
        }
}

int main()
{
        int n,c,start,end,i,center;
        sieve();

        while(scanf("%d%d",&n,&c)==2)
        {
                for(i=0;primes[i]<=n;i++);
                center=(i-1)/2;

                if((i-1)%2)
                        start = center-c+1;
                else
                        start=center-(2*c-1)/2;

                if(start<0)
                {
                        start=0;
                        end=i;
                }
                else
                {
                        if((i-1)%2)
                                end=start+(2*c);
                        else
                                end=start+(2*c)-1;
                }

                printf("%d %d:",n,c);

                for(i=start;i<end;i++)
                        printf(" %d",primes[i]);
                printf("\n\n");
        }

        return 0;
}
