using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int dp[6][7500],Mtaka;
int coin[]={1,5,10,25,50};

int solve(int i,int taka)
{
    if(i>=5)
    {
        if(taka==0)
            return 1;
        return 0;
    }

    if(dp[i][taka]!=-1)
        return dp[i][taka];

    int r1=0,r2=0;
    if(taka-coin[i]>=0)
        r1=solve(i,taka-coin[i]);
    r2=solve(i+1,taka);

    return dp[i][taka]=r1+r2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&Mtaka)==1)
    {
        printf("%d\n",solve(0,Mtaka));
    }
    return 0;
}
