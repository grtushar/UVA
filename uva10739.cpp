using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define min(a,b) ((a<b)?(a):(b))


int dp[1010][1010];
string str;

int solve(int l1,int l2)
{
    if(l1>=l2)
        return 0;

    if(dp[l1][l2]!=-1)
        return dp[l1][l2];

    if(str[l1]==str[l2])
            return dp[l1][l2]=solve(l1+1,l2-1);

    else
    {
        return dp[l1][l2]=1+min(solve(l1+1,l2-1),min(solve(l1+1,l2),solve(l1,l2-1)));
    }

}

int main()
{
    int T,Case=1;
    cin>>T;
    getchar();

    while(T--)
    {
        memset(dp,-1,sizeof(dp));

        getline(cin,str);

        cout<<"Case "<<Case++<<": "<<solve(0,str.length()-1)<<endl;
    }
    return 0;
}
