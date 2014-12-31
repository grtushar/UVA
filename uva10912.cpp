using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max 10010

int dp[30][30][30],L,S;;

/*int dp(char a,char b,char c)
{
    if(value(a)+value(b)+value(c)==S)
        return dp[value(a)][value(b)][value(c)] = 1;
    if(if(value(a)+value(b)+value(c)>S))
        return dp[value(a)][value(b)][value(c)] = 0;
    if(dp[value(a)][value(b)][value(c)]!=-1)
        return dp[value(a)][value(b)][value(c)];


}*/

int solve(int a,int b,int c)
{

    if(dp[a][b][c]!=-1)
        return dp[a][b][c]=0;

    if((a+b+c>S)||(a>=b||a>=c||b>=c))
        return dp[a][b][c] = 0;
    if((a+b+c)==S)
    {
        cout<<a<<" "<<b<<" "<<c<<endl;
        return dp[a][b][c] = 1;
    }



        //cout<<"enter"<<endl;

    return solve(a+1,b,c)+solve(a,b+1,c)+solve(a,b,c+1);

}

int main()
{
    while(cin>>L>>S)
    {
        if(L==0&&S==0)
            break;



        memset(dp,-1,sizeof(dp));
        cout<<solve(1,2,3)<<endl;
    }
    return 0;
}
