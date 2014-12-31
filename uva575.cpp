using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

int main()
{
    string str;
    long long int i,ans,k,l;

    while(cin>>str&&str[0]!='0')
    {
        ans=0;
        l=str.length();
        k=l;

        for(i=0;i<l;i++)
        {
            ans+=((str[i]-48)*(pow(2,k)-1));
            k--;
        }

        printf("%d\n",ans);
    }

    return 0;
}
