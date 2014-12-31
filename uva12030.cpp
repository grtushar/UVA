using namespace std;

#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>


#define maX(a,b) ((a>b)?(a):(b))


int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

long long int dp[32768 + 5][32];
int arr[17][17],n;
bool visited[32768 + 5][32];

long long int solve(int mask,int chk,int count)
{
    int k = __builtin_popcount(mask);

    if(k==n)
    {
        if(count==n||chk==1)
        {
            //cout<<count<<" "<<chk<<endl;
            return 1;
        }

        return 0;
    }

    if(visited[mask][count])
        return dp[mask][count];

    long long int i,ans=0;
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {

            int temp=chk;
            if(arr[k][i]==2)
                chk=1;
            ans=ans+solve(Set(mask,i),chk,count+arr[k][i]);
            chk=temp;
        }

    }

    visited[mask][count]=true;
    return dp[mask][count]=ans;
}

int main()
{
    int t,i,j,Case=1;

    scanf("%d",&t);

    while(t--)
    {
        memset(visited,false,sizeof(visited));
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        //N=0;
       // int ans=solve(0,0);

        printf("Case %d: %lld\n",Case++,solve(0,0,0));
    }

    return 0;
}
