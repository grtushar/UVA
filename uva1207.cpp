using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define min(a,b) ((a<b)?(a):(b))
#define max(a,b)((a>b)?(a):(b))

//typedef long long int ll_d;

int dp[1010][1010];
char str1[1010],str2[1010];

int solve(int l1,int l2)
{
        if(l1<0)
                return l2+1;
        if(l2<0)
                return l1+1;

        if(dp[l1][l2]!=-1)
                return dp[l1][l2];

        if(str1[l1]==str2[l2])
                return dp[l1][l2]=solve(l1-1,l2-1);
        else
                return dp[l1][l2]=1+min(solve(l1-1,l2-1),min(solve(l1-1,l2),solve(l1,l2-1)));//min(solve(l1-1,l2-1),min(solve(l1-1,l2),solve(l1,l2-1)));
}

int main()
{
        int l1,l2;

        while(scanf("%d %s %d %s",&l1,str1,&l2,str2)==4)
        {
                memset(dp,-1,sizeof(dp));
                int ans=solve(l1-1,l2-1);
                printf("%d\n",ans);
        }

        return 0;
}
