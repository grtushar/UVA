/*using namespace std;

#include<iostream>
#include<algorithm>

#define max(a,b) ((a>b)?(a):(b))

int main()
{
    int T,ans,l,i,weight[1010],cost[1010],MAX,n,fans,j,arr[1010];

    cin>>T;

    while(T--)
    {
        fans=0;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>cost[i]>>weight[i];

        cin>>l;

        while(l--)
        {
            cin>>MAX;
            ans=0;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(i!=j)
                    {
                        if(cost[j]+ans<=MAX)
                            ans=ans+cost[j];
                    }
                }
                arr[i]=max(ans,(ans-cost[n]+cost[i]));
            }
            sort(arr,arr+n+1);
            fans=fans+arr[n];
        }

        /for(i=1;i<=n;i++)
            cout<<arr[i]<<" ";/
        cout<<fans<<endl;
    }
    return 0;
}*/





using namespace std;

#include<iostream>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int dp[1010][102],weight[1010],cost[1010],MAX,n;



int solve(int item,int CW)
{
    if(item>n)
        return 0;

    if(dp[item][CW]!=-1)
        return dp[item][CW];

    int temp=0;
    if(CW+weight[item]<=MAX)
    {
        temp=cost[item]+solve(item+1,CW+weight[item]);

    }
    else
        temp=0;
    return dp[item][CW]=max(temp,solve(item+1,CW));
}

int main()
{
    int T,ans,l,i;

    cin>>T;

    while(T--)
    {
        ans=0;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>cost[i]>>weight[i];

        cin>>l;

        while(l--)
        {
            memset(dp,-1,sizeof(dp));
            cin>>MAX;
            ans=ans+solve(1,0);
        }

        cout<<ans<<endl;
    }
    return 0;
}

