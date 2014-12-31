using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define min(a,b) ((a<b)?(a):(b))

int dp[4][1010],n,first[1010],second[1010],time1[1010],time2[1010];

int solve(int no, int pos)
{
        if(pos>=n)
                return 0;

        if(dp[no][pos]!=-1)
                return dp[no][pos];

        int value,trans;
        if(no==0) value=first[pos];
        else value=second[pos];


         if(pos==n-1)
        {
                return value;
        }

         if(no==0) trans=time1[pos];
        else trans=time2[pos];

        int r1=value+solve(no,pos+1);
        int r2=value+trans+solve((no+1)%2,pos+1);

        return dp[no][pos]=min(r1,r2);
}

int main()
{
        int t,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                memset(dp,-1,sizeof(dp));

                for(i=0;i<n;i++)
                        scanf("%d",&first[i]);
                for(i=0;i<n;i++)
                        scanf("%d",&second[i]);

                for(i=0;i<n-1;i++)
                        scanf("%d",&time1[i]);
                for(i=0;i<n-1;i++)
                        scanf("%d",&time2[i]);

                printf("Case %d: %d\n",Case++,min(solve(0,0),solve(1,0)));
        }

        return 0;
}
