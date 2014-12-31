using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a)>(b))?(a):(b)

int dp[1000][1000];

string str;

int longest_palindrome(int low,int high)
{
    if(dp[low][high]!=-1)
        return dp[low][high];

    if(low<high)
    {
        if(str[low]==str[high])
            return dp[low][high]=longest_palindrome(low+1,high-1)+2;
        else
            return dp[low][high]=max(longest_palindrome(low+1,high),longest_palindrome(low,high-1));
    }
    if(low==high)
        return dp[low][high]=1;
    return 0;
}

int main()
{
    int T;
    cin>>T;
    getchar();

    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        getline(cin,str);
        cout<<(longest_palindrome(0,str.length()-1))<<endl;
    }

    return 0;
}
