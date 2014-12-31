using namespace std;

#include<iostream>
#include<cstring>
#include<cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define N 200005

//int max(int a, int b) { return (a > b)? a : b; }

/*int iabs(int n)
{
    return (n > 0)? n : -n;
}*/

int dp[25][N],val[25],n,maxV,used[25];

int solve(int item,int W)
{
    if(item>n)
        return 0;
    if(dp[item][W]!=-1)
        return dp[item][W];

    if(used[item]&&maxV>=(W+val[item]))
    {
        int r1=val[item]+solve(item+1,W+val[item]);
        int r2=solve(item+1,W);

        int temp = max(r1,r2);

        if(temp==r1)
        {
            used[item]=0;
            return dp[item][W] = r1;
        }
        else
            return dp[item][W] = r2;
    }

    else
        return dp[item][W] = solve(item+1,W);
}

int main()
{
    int T,ans,flag;
    cin>>T;

    while(T--)
    {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        memset(used,1,sizeof(used));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>val[i];
            sum+=val[i];
        }

        if(sum%4)
            cout<<"no"<<endl;
        else
        {
            maxV = sum/4;
            for(flag=0;flag<4;flag++)
            {
                ans = solve(1,0);
                if(ans!=maxV)
                    break;
            }
            if(flag>3)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }


    }
    return 0;
}

