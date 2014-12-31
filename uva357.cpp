using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int ll_d;

ll_d arr[5]={1,5,10,25,50},n,dp[30000+10][6];

ll_d solve(ll_d value, ll_d i)
{
        if(i>=5||value<=0)
        {
                if(value==0)
                {
                        return 1;
                }
                return 0;
        }

        if(dp[value][i]!=-1)
                return dp[value][i];

        ll_d r1=0;

        for(ll_d m=0;arr[i]*m<=value;m++)
                r1+=solve(value-arr[i]*m,i+1);

        return dp[value][i]=r1;
}

int main()
{
        memset(dp,-1,sizeof(dp));
        /*for(int i=1;i<=30000;i++)
                dp[i]=solve(i,0);*/
        while(scanf("%lld",&n)==1)
        {
                // memset(dp,-1,sizeof(dp));
                ll_d ans=solve(n,0);
                if(ans==1)
                        printf("There is only 1 way to produce %lld cents change.\n",n);
                else
                        printf("There are %lld ways to produce %lld cents change.\n",ans,n);
        }

        return 0;
}
