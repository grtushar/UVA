using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

#define N 10000+10

bool prime[N];
//int prime_number[N];
vector<int>prime_number;

void sieve()
{
        int j=0,i,sq = (int)sqrt(N);
        //prime_number[j++]=2;
        prime_number.push_back(2);
        prime[0]=prime[1]=true;

        for(i=3;i<=sq;i+=2)
        {
                if(prime[i]==false)
                {
                        //prime_number[j++]=i;
                        prime_number.push_back(i);
                        for(j=i*i;j<=N;j+=2*i)
                        {
                                prime[j]=true;
                        }
                }
        }

        for(;i<=N;i+=2)
        {
                if(prime[i]==false)
                        prime_number.push_back(i);
                       // prime_number[j++]=i;
        }
}

int main()
{
        sieve();
        int t,n;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                int sq = (int)sqrt(n);
                vector<int>::iterator low;
                low = upper_bound(prime_number.begin(), prime_number.end(), n/2);
               /* if(prime_number[low-prime_number.begin()]*2==n)
                        low++;*/
                printf("%d\n",prime_number[low-prime_number.begin()]);
        }

        return 0;
}
