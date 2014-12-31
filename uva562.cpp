using namespace std;

#include<iostream>
#include<cstring>
#include<cmath>

#define max(a,b) (((a)>(b))?(a):(b))
#define N 50000

//int max(int a, int b) { return (a > b)? a : b; }

/*int iabs(int n)
{
    return (n > 0)? n : -n;
}*/

int dp[105][N],val[N],n,maxV;

int solve(int item,int W)
{
    if(item>n)
        return 0;
    if(dp[item][W]!=-1)
        return dp[item][W];

    if(maxV>=(W+val[item]))
        return dp[item][W] = max(val[item]+solve(item+1,W+val[item]),solve(item+1,W));
    else
        return dp[item][W] = solve(item+1,W);
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>val[i];
            sum+=val[i];
        }
       /* if(sum%2)
            maxV = (sum/2)+1;
        else*/
            maxV = sum/2;
        int ans = solve(1,0);
        cout<<(sum-ans)-ans<<endl;
    }
    return 0;
}
