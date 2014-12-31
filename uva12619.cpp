using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<math.h>

#define N 40000

typedef long long int ll_d;
bool prime[N];
vector<int>primes;
int factor[200];

void sieve()
{
        int sq=sqrt(N),i,k;
        prime[0]=prime[1]=true;
        primes.push_back(2);

        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<sq;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(k=i*i;k<N;k+=2*i)
                                prime[i]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false) primes.push_back(i);
                i+=2;
        }
}

int  prime_factor(ll_d n, ll_d i)
{
        ll_d sq=sqrt(n),sz=primes.size();
        for(;i<sz&&primes[i]<=sq;i++)
        {
                if(n%primes[i]==0)//&&n!=primes[i])
                {
                        if(factor[n/primes[i]]==-1)
                                factor[n/primes[i]]=prime_factor(n/primes[i],i);
                        if(sq*sq==n)
                                temp=1;
                        return factor[n]=factor[n/primes[i]]+4-temp;

                       //sreturn;
                }
        }
        return factor[n]=2;
}

int main()
{
        ll_d n;
        sieve();
        memset(factor,-1,sizeof(factor));

        while(cin>>n)
        {
                cout<<prime_factor(n,0)<<endl;;
                //cout<<factor[n]<<endl;
        }
        return 0;
}
