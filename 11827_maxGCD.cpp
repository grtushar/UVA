using namespace std;

#include<iostream>
#include<cstring>
#include<stdio.h>

#define max(a,b) (a>b)?a:b


int FindGcd(int a , int b)
{
    if(b==0)
        return a;
    else
        return FindGcd (b , a%b);
}


int main()
{
    string str;
    int T,arr[110],i,m,k,temp,ans;
    char c;

    cin>>T;
    getchar();

    while(T--)
    {
        memset(arr , 0 ,sizeof arr);
        getline(cin,str);

        m=i=k=0;
        while(i<str.length())
        {
            temp=0;
            while(i<str.length()&&str[i]!=' ')
            {
                i++;
            }

            while(k<i)
            {
                temp=(str[k]-48)+(temp*10);
                k++;
            }
            arr[m++]=temp;
            i++;
            k++;

        }
        ans=1;
        for(i=0;i<m;i++)
            for(k=i+1;k<m;k++)
                ans=max(ans,FindGcd(arr[i],arr[k]));

        cout<<ans<<endl;
    }
    return 0;
}
