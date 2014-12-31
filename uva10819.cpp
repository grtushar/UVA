using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int dp[105][10000+10],n,m,price[105],favoure[105];

int solve(int pos, int value)
{
        if(pos>=n)
                return 0;

        if(dp[pos][value]!=-1)
                return dp[pos][value];

        int r1=0,r2;

        if(value+price[pos]<=m)
                r1=favoure[pos]+solve(pos+1,price[pos]+value);
        r2=solve(pos+1,value);

        return dp[pos][value]=max(r1,r2);
}

int main()
{
        int i;

        while(scanf("%d%d",&m,&n)==2)
        {
                if(m>2000)
                        m+=200;
                for(i=0;i<n;i++)
                {
                        scanf("%d%d",&price[i],&favoure[i]);
                }
                memset(dp,-1,sizeof(dp));

                printf("%d\n",solve(0,0));
        }

        return 0;
}
