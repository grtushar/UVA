using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

#define N 10000000+10
#define sq 3162+10
typedef long long int ull_d;

bool prime[N];
long long int primes[1000000+10];

void sieve()
{
        ull_d i,j=0,k;
        prime[0]=prime[1]=true;
        primes[j++]=2;
        for(k=4;k<=N;k+=2*2)
                        prime[k]=true;
        for(i=3;i<=1000000;i+=2)
        {
                if(prime[i]==false)
                {
                        primes[j++]=i;
                        for(k=i*i;k<=N;k+=2*i)
                                prime[k]=true;
                }
        }
}

long long int factorization(ull_d n)
{
        long long int ans=1,cnt,i,ssqn=(ull_d)sqrt(n);
        for(i=0;primes[i]<=ssqn+1;i++)
        {
                cnt=0;
                while(n%primes[i]==0)
                {
                        cnt++;
                        n/=primes[i];
                }
                ans*=(cnt+1);
                if(n==1)
                        break;
        }
       // cout<<ans<<endl;

        if(n>1)
                ans=ans*2;

      //  cout<<n<<"))"<<ans<<endl;

        return ans;
}


int main()
{
        int t;
        sieve();
       /* for(int i=0;i<=40;i++)
                cout<<primes[i]<<endl;*/
        //factorization();
        ull_d l,u,num,mx,i,temp;
        //cout<<factorization(1000)<<endl;
        scanf("%d",&t);


        while(t--)
        {
                scanf("%lld%lld",&l,&u);
                mx=factorization(l);
                num=l;

                for(i=l+1;i<=u;i++)
                {
                        temp=factorization(i);
                        if(temp>mx)
                        {
                                mx=temp;
                                num=i;
                        }
                }

                printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,num,mx);
        }

        return 0;
}

/*
void prime_factorization()
{
        ull_d i,j,temp,fac,cnt;
        for(i=1;i<=N;i++)
        {
                if(prime[i]==false)
                        factor[i]=2;
                else
                {
                        temp=i;
                        j=0;
                        fac=1;
                        while(temp)
                        {
                                cnt=0;
                                if(temp%primes[j]==0)
                                {
                                        while(temp%primes[j]==0)
                                        {
                                                temp/=primes[j];
                                                cnt++;
                                        }
                                }
                                j++;
                                fac*=(cnt+1);
                        }
                        factor[i]=fac;
                }

        }
}

*/
