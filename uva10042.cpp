using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<math.h>

typedef long long int ll_d;
#define N 10000000+10

bool prime[N];
vector<ll_d>primes;

void sieve()
{
        ll_d i,j,sq=sqrt(N);
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

ll_d calculate(ll_d n)
{
        ll_d ans=0,sq=sqrt(n),j,temp,sz=primes.size();

        for(j=0;j<sz&&primes[j]<=sq;j++)
        {
                while(n%primes[j]==0)
                {
                        temp=primes[j];
                        while(temp)
                        {
                                ans+=temp%10;
                                temp/=10;
                        }
                        n/=primes[j];
                }
                if(n==1)
                        break;
        }
        if(n>1)
        {
             temp=n;
             while(temp)
             {
                     ans+=(temp%10);
                     temp/=10;
             }
        }

        return ans;
}

bool isPrime(ll_d n)
{
        ll_d sz=primes.size(),i,sq=sqrt(n);
        for(i=0;i<sz&&prime[i]<=sq;i++)
        {
                if(n%primes[i]==0)
                        return false;
        }
        return true;
}

int main()
{
        int t;
        sieve();
        //cout<<prime[4937775]<<endl;
        ll_d n,i,temp,sum;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lld",&n);
                for(i=n+1;;i++)
                {
                        if(i<=10000000&&!prime[i])
                                continue;
                        else if(isPrime(i))
                                continue;
                        temp=i;sum=0;
                        while(temp)
                        {
                                sum+=(temp%10);
                                temp/=10;
                        }
                       temp = calculate(i);

                       //cout<<i<<"  "<<sum<<"  "<<temp<<endl;
                       if(temp==sum)
                       {
                               printf("%lld\n",i);
                               break;
                       }

                }

        }

        return 0;
}
