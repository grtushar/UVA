using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        int n,m,i,j,arr[20];
        bool dp[1000000+10];

        while(scanf("%d%d",&n,&m)==2)
        {
                for(i=0;i<m;i++)
                        scanf("%d",&arr[i]);

                for(i=0;i<=n;i++)
                        dp[i]=false;

                for(i=1;i<=n;i++)
                {
                        for(j=0;j<m;j++)
                        {
                                if(i-arr[j]>=0&&dp[i-arr[j]]==false)
                                {
                                        dp[i]=true;
                                        break;
                                }
                        }
                }

                if(dp[n])
                        printf("Stan wins\n");
                else
                        printf("Ollie wins\n");
        }

        return 0;
}
