using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define N 65000+10

bool prime[N];
//int primes[N];

void sieve()
{
        //memset(prime,false,sizeof(false));
        long long i,j=0,k;
        prime[0]=prime[1]=true;

        for(i=4;i<N;i+=2)
                prime[i]=true;
        //primes[j++]=2;
        //cout<<"done"<<endl;

        for(i=3;i<N;i+=2)
        {
                //cout<<"done"<<endl;
                if(prime[i]==false)
                {
                        //primes[j++]=i;
                        for(k=i*i;k<N;k+=2*i)
                                prime[k]=true;
                }
        }
}

long long big_mod(long long n,long long p,long long m)
{
        if(p==1) return n%m;
        if(p%2==0)
        {
                long long temp=big_mod(n,p/2,m);
                return ((temp%m)*(temp%m))%m;
        }
        long long temp=big_mod(n,p-1,m);
        return ((temp%m)*(n%m))%m;
}

int main()
{
        long long n,i;
        sieve();
       // cout<<"done"<<endl;

        while(scanf("%lld",&n)==1&&n)
        {
                if(prime[n]==false)
                {
                        printf("%lld is normal.\n",n);
                        //cout<<n<<endl;
                }

                else
                {
                        bool flag=true;
                        for(i=2;i<n;i++)
                        {
                                if(big_mod(i,n,n)!=i)
                                {
                                        flag=false;
                                        break;
                                }
                        }

                        if(flag)
                                printf("The number %lld is a Carmichael number.\n",n);
                        else
                                printf("%lld is normal.\n",n);
                }
        }

        return 0;
}


/*bool carmichael_number(int i,int n)
{
        long long j,temp=1;
        for(j=0;j<n;j++)
        {
                temp=((temp%n)*(i%n))%n;
        }
        if(temp==i)
                return true;
        return false;
}*/
