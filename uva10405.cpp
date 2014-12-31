using namespace std;

#include<iostream>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int dp[1010][1010];
string str1,str2;

int lcs(int l1,int l2)
{
    if(l1<0||l2<0)
        return 0;

    if(dp[l1][l2]!=-1)
        return dp[l1][l2];

    if(str1[l1]==str2[l2])
    {
        return dp[l1][l2]=lcs(l1-1,l2-1)+1;
    }

    else
    {
        return dp[l1][l2]=max(lcs(l1,l2-1),lcs(l1-1,l2));
    }
}

int main()
{
    int sl1,sl2;
    while(getline(cin,str1)&&getline(cin,str2))
    {
        memset(dp,-1,sizeof(dp));
        sl1=str1.length()-1;
        sl2=str2.length()-1;
        cout<<lcs(sl1,sl2)<<endl;
    }

    return 0;
}

/*using namespace std;

#include<iostream>
#include<cstring>
#include<algorithm>

#define max(a,b) ((a)>(b))?(a):(b)

int dp[1010][1010],sl1,sl2,temp;
string str1,str2;

int LCS(int l1,int l2)
{
    if(dp[l1][l2]!=-1)
        return dp[l1][l2];

    if(l1>=sl1)
        return 0;


    if(str1[l1]==str2[l2])
    {
        temp=l2;
        return dp[l1][l2]=LCS(l1+1,l2+1)+1;
    }
    else
    {
        //r1=LCS(l1,l2+1);
        if(l2>=sl2)
        return LCS(l1+1,temp+1);

        return dp[l1][l2]=LCS(l1,l2+1);
        //r2=LCS(l1+1,l2);

        //return dp[l1][l2]=max(r1,r2);
       // return dp[l1][l2]=max(LCS(l1,l2+1),LCS(l1+1,l2));
    }
}

int main()
{
    int arr[1010],i;
    while(cin>>str1>>str2)
    {
        memset(dp,-1,sizeof(dp));
        sl1=str1.length()-1;
        sl2=str2.length()-1;

        /*for(i=0;i<sl1;i++)
        {
            arr[i]=LCS(i,0);
            //cout<<arr[i]<<endl;
        }
        sort(arr,arr+sl1);

        cout<<arr[sl1-1]<<endl;
        cout<<LCS(0,0)<<endl;
    }

    return 0;
}*/
