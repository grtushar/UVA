using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

typedef long long int LLD;

LLD arr[25000+10];

LLD binary_less(LLD x,LLD high)
{
    LLD mid,low=0;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]<x&&(mid+1>high||arr[mid+1]>=x))
            return mid;
        else if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return -1;
}

LLD binary_bigger(LLD x,LLD high)
{
    LLD mid,low=0;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]>x&&(mid-1<low||arr[mid-1]<=x))
            return mid;
        else if(arr[mid]<=x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return -1;
}

int main()
{
    LLD n,i,q,temp,x;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    scanf("%lld",&q);

    while(q--)
    {
        scanf("%lld",&x);
        temp=binary_less(x,n-1);
        if(temp==-1)
            printf("X ");
        else
            printf("%lld ",arr[temp]);

        temp=binary_bigger(x,n-1);

        if(temp==-1)
            printf("X\n");
        else
            printf("%lld\n",arr[temp]);
    }

    return 0;
}
