using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

int absolute(int x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int i,arr[3010],n,flag,cheaque[3010];

    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i)
                cheaque[i]=absolute(arr[i]-arr[i-1]);
        }
        flag=1;
        sort(cheaque,cheaque+i);

        for(i=1;i<=n-1;i++)
        {
            if(cheaque[i]!=i)
            {
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }

    return 0;
}
