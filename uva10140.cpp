/* WA */

using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<math.h>

typedef long long int ll_d;
#define N 1000000+10

struct info{
        ll_d a,b,value;
}diff[80000];

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

ll_d low(ll_d x)
{
        ll_d i=0;
        while(diff[i].a<x)
                i++;
        return i;
}

ll_d high(ll_d x)
{
        ll_d i=primes.size()-2;
        while(diff[i].b>x)
                i--;
          //      cout<<i<<"     "<<diff[i].b<<"      "<<x<<endl;
        return i;
}

int main()
{
        sieve();
      /*  for(int i=0;i<7;i++)
                cout<<primes[i]<<endl;*/
        //cout<<primes[5]<<endl;
        ll_d sz=primes.size(),i,a,b,l,h,mini,maxi,x1,x2,y1,y2;
        cout<<sz<<" "<<primes[sz-1]<<endl;
        for(i=0;i<sz-1;i++)
        {
                diff[i].value=primes[i+1]-primes[i];
                diff[i].a=primes[i];
                diff[i].b=primes[i+1];
        }

        while(scanf("%lld%lld",&a,&b)==2)
        {
                l=low(a);
                h=high(b);
             //  cout<<l<<"     "<<h<<endl;
                mini=9999999;
                maxi=0;

                for(i=h;i>=l;i--)
                {
                        if(mini>=diff[i].value)
                        {
                                mini=diff[i].value;
                                x1=diff[i].a;
                                x2=diff[i].b;
                        }

                        if(maxi<=diff[i].value)
                        {
                                maxi=diff[i].value;
                                y1=diff[i].a;
                                y2=diff[i].b;
                        }
                }

                if(mini==9999999&&maxi==0)
                        printf("There are no adjacent primes.\n");
                else
                        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",x1,x2,y1,y2);
        }

        return 0;
}
