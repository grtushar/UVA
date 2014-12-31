using namespace std;

#include<iostream>
#include<cstdio>

#define ll_d long long

int main()
{
        ll_d n,ans;

        while(scanf("%lld",&n)==1&&n>=0)
        {
                if(n&1) ans = n*((n+1)>>1);
                else ans = (n>>1)*(n+1);

                printf("%lld\n",ans+1);
        }

        return 0;
}
