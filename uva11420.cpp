using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define ll_d long long int

ll_d dp[100][100][2],n,k;

ll_d solve(int pos, int num,int flag)
{
        if(dp[pos][num][flag]!=-1) return dp[pos][num][flag];

        if(pos==n) {
                if(num==k&&flag==0) return dp[pos][num][flag] = 1;
                else if(num==k-1&&flag==1) return dp[pos][num][flag] = 1;
                return dp[pos][num][flag] = 0;
        }

        if(num>k) return 0;


        ll_d r1=0,r2=0;

        if(flag==1){
                r1+=solve(pos+1,num+1,1);
                r2+=solve(pos+1,num,0);
        }
        else{
                r1+=solve(pos+1,num,1);
                r2+=solve(pos+1,num,0);
        }

        return dp[pos][num][flag] = r1+r2;
}

int main()
{
        while(scanf("%lld %lld",&n,&k)==2)
        {
                if(n<0&&k<0) break;

                memset(dp,-1,sizeof(dp));

                printf("%lld\n",solve(0,0,0));
        }

        return 0;
}
