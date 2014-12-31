using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>

#define N 100000000+5

typedef unsigned long long int ll_d;

bool prime[N];

void sieve()
{
        ll_d sq=sqrt(N),i,k;
        prime[0]=prime[1]=true;

        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        for(k=i*i;k<N;k+=2*i)
                                prime[k]=true;
                }
        }
}


int main()
{
        sieve();
        ll_d n,i,sz,temp,half,m;
        bool flag;

        while(scanf("%llu",&n)==1)
        {
                flag=false;
                half=n/2;
                bool done=true;
                 if(n&1 && n>3)//n%2==1)
                {
                      if(prime[n-2]) printf("%llu is not the sum of two primes!\n",n);
                      else printf("%llu is the sum of 2 and %llu.\n",n,n-2);
                      done=false;
                }
                else
                {
                        m=0;
                        for(i=half;i<n;i++)
                        {
                                if(prime[half-m]==false && prime[i]==false && (half-m)!=i)
                                {
                                        temp=i;
                                         flag=1;
                                         break;
                                }
                                m++;
                        }
                }

               if(done)
                        if(flag) printf("%llu is the sum of %llu and %llu.\n",n,n-temp,temp);
                        else printf("%llu is not the sum of two primes!\n",n);
        }

        return 0;
}


//sqrt(n);
              /*  if(prime_check(n-2))
                {
                        flag=true;
                        temp=2;
                }*/


                         /*       for(i=half;i>=2;i--)
                                {
                                        if(prime[i]==false&&prime[n-i]==false)
                                        {
                                                temp=i; flag=true; break;
                                        }
                                }*/

  /*  for(i=3;i<half&&!flag;i+=2)
                {
                        if(i!=n-i&&prime_check(i)&&prime_check(n-i))
                        {
                                temp=i; flag=true; break;
                        }
                }*/
