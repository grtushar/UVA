using namespace std;

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))

int dp[1010][22],arr[20+5],n,L;

int solve(int l,int i)
{
        if(i>=n)
                return 0;

        if(dp[l][i]!=-1)
                return dp[l][i];

        int r1=0;

        if(l+arr[i]<=L)
        {
                r1=arr[i]+solve(l+arr[i],i+1);
        }
        int r2=solve(l,i+1);

        return dp[l][i]=max(r1,r2);

}

int main()
{
        int t,i;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&L,&n);

                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

               // sort(arr,arr+n);

                memset(dp,-1,sizeof(dp));

                int ans = solve(0,0);

                if(ans==L)
                        cout<<"YES"<<endl;
                else
                        cout<<"NO"<<endl;
        }

        return 0;
}
