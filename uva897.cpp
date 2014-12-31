using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define size 10000000+10

bool prime[size];
//long long primes[size];

void sieve()
{
        long long i,k,sq=sqrt(size);
        prime[0]=prime[1]=true;
        //primes[j++]=2;
        for(i=4;i<size;i+=2)
                prime[i]=true;

        for(i=3;i<=sq+1;i+=2)
        {
                if(prime[i]==false)
                {
                        //primes[j++]=i;
                        for(k=i*i;k<size;k+=2*i)
                                prime[k]=true;
                }
        }

        /*for(;i<size;i+=2)
                primes[j++]=i;*/
}

bool solve(long long x)
{
        char str[20];
        int i=0,j,k,num;

        while(x)
        {
                str[i++]=x%10+48;
                x/=10;
        }

        long temp=1;
        for(k=2;k<=i;k++)
                temp*=k;

        for(j=1;j<=temp;j++)
        {
                num=0;
                for(k=i-1;k>=0;k--)
                        num=(str[k]-48)+(num*10);
                //cout<<num<<endl;
                if(prime[num])
                        return false;
                next_permutation(str,str+i);
        }

        return true;
}

int main()
{
        sieve();
        long long n,power,i;
        while(scanf("%lld",&n)&&n)
        {
                power=1;
                while(power<=n)
                        power*=10;

                bool flag=false;
                for(i=n+1;i<=power;i++)
                {
                        if(prime[i]==false)
                                flag=solve(i);
                        if(flag)
                        {
                                printf("%lld\n",i);
                                break;
                        }
                }

                if(!flag)
                        printf("0\n");
        }

        return 0;
}
