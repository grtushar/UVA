using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int n,w,stop,arr[110],dp[45005][55][105],sum;
bool vis[45005][55][105];

int solve(int sum, int cnt, int i)
{
        if(cnt==stop&&sum<=w)
                return sum;

        if(i>=n) return 0;

        if(vis[sum][cnt][i]) return dp[sum][cnt][i];

        int r1=0,r2;

        if(cnt+1<=stop&&sum+arr[i]<=w)
        {
                r1=solve(sum+arr[i],cnt+1,i+1);
        }

        r2=solve(sum,cnt,i+1);

        vis[sum][cnt][i]=true;

        return dp[sum][cnt][i]=max(r1,r2);
}

int main()
{
        int t,ans,i,sum;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                sum=0;

                for(i=0;i<n;i++){
                        scanf("%d",&arr[i]);
                        sum+=arr[i];
                }

                w=sum;
                memset(vis,false,sizeof(vis));

                if(n%2)
                {
                        stop=n/2;
                        int r1=solve(0,0,0);
                        stop=(n/2)+1;
                        memset(vis,false,sizeof(vis));
                        int r2=solve(0,0,0);
                       if(sum-r1>sum-r2) ans=r2;
                       else ans=r1;
                }
                else
                {
                        stop=n/2;
                        ans=solve(0,0,0);
                }

                printf("%d %d\n",min(ans,sum-ans),max(ans,ans-sum));
        }

        return 0;
}

