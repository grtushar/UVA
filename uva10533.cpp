using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<math.h>

#define N 1000000+10
#define ll_d long long int

vector<ll_d>primes;

bool prime[N];
bool iron[N];
int ans[N];

void sieve()
{
        ll_d sq=sqrt(N),i,k;

        iron[0]=iron[1]=prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                iron[i]=prime[i]=true;

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(k=i*i;k<N;k+=2*i)
                                iron[k]=prime[k]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false) primes.push_back(i);
                i+=2;
        }
}

void tushar()
{
        ll_d sz=primes.size(),i,temp,sum;
        for(i=0;i<sz;i++)
        {
                temp=primes[i];
                sum=0;
                while(temp)
                {
                        sum+=(temp%10);
                        temp/=10;
                }

                if(prime[sum]) iron[primes[i]]=true;
        }
}

int main()
{
        ll_d a,b,t,i;
        sieve(); tushar();

        ans[0]=0;
        for(i=1;i<N;i++)
        {
                //if(i<20) cout<<prime[i]<<endl;
                if(iron[i]) ans[i]=ans[i-1];
                else ans[i]=ans[i-1]+1;
        }

      /*  for(i=0;primes[i]<=100;i++)
                cout<<primes[i]<<" :  "<<prime[primes[i]]<<endl;
        cout<<ans[100]<<endl;*/

        scanf("%lld",&t);
        while(t--)
        {
                scanf("%lld%lld",&a,&b);
                printf("%d\n",ans[b]-ans[a-1]);
        }

        return 0;
}
