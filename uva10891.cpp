using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int absolute(int x)
{
        if(x<0)
                return -x;
        return x;
}

int dp[110][110][3],arr[110];

int solve(int p_no, int item1, int item2)
{
        if(item1>item2)
                return 0;

        if(dp[item1][item2][p_no]!=-1)
                return dp[item1][item2][p_no];

        int r1=max(arr[item1]+solve((p_no+1)%2,item1+1,item2), arr[item1]+solve(p_no,item1+1,item2));
        int r2=max(arr[item2]+solve((p_no+1)%2,item1,item2-1),arr[item2]+solve(p_no,item1, item2-1));

        return dp[item1][item2][p_no]=absolute(r1-r2);
}

int main()
{
        int n,t,i;

        while(scanf("%d",&n)&&n)
        {
                memset(dp,-1,sizeof(dp));
                for(i=0;i<n;i++)
                {
                        scanf("%d",&arr[i]);
                }

                printf("%d\n",solve(1,0,n-1));
        }

        return 0;
}
