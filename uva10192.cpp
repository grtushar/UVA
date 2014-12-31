using namespace std;

#include<iostream>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int dp[1010][1010],sl1,sl2;
string str1,str2;


int LCS(int l1,int l2)
{
    if(l1<0||l2<0)
        return 0;

    if(dp[l1][l2]!=-1)
        return dp[l1][l2];

    if(str1[l1]==str2[l2])
    {
        return dp[l1][l2]=1+LCS(l1-1,l2-1);
    }

    else
        return dp[l1][l2]=max(LCS(l1,l2-1),LCS(l1-1,l2));
}


int main()
{
    int Case=1;
    while(getline(cin,str1)&&str1[0]!='#')
    {
        memset(dp,-1,sizeof(dp));
        getline(cin,str2);
        sl1=str1.length();
        sl2=str2.length();
        cout<<"Case #"<<Case++<<": you can visit at most "<<LCS(sl1-1,sl2-1)<<" cities."<<endl;
    }

    return 0;
}
