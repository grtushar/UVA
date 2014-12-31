using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>

#define max(a,b) ((a>b)?(a):(b))

int temp,idx,a[25], dp[24][210];

int solve(int i,int sum)
{
        if(i>=idx||sum>temp)
                return 0;

        if(dp[i][sum]!=-1)
                return dp[i][sum];
        int r1=0,r2;

        if(sum+a[i]<=temp)
                r1=a[i]+solve(i+1,sum+a[i]);
        r2=solve(i+1,sum);

        return dp[i][sum]=max(r1,r2);
}

int main()
{
        int t;
        scanf("%d",&t);
        getchar();

        while(t--)
        {
                   string str;
                   stringstream ss;
                   getline(cin,str);
                   ss<<str;
                   int sum=0;
                   idx=0;
                   while(ss>>a[idx])
                   {      sum+=a[idx];
                          idx++;
                   }

                   if(sum%2)
                        printf("NO\n");
                   else
                   {
                           temp=sum/2;
                           memset(dp,-1,sizeof(dp));

                           if(solve(0,0)==temp)
                           {
                                   printf("YES\n");
                           }
                           else
                                printf("NO\n");
                   }
        }
}
