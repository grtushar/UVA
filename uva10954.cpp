using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    long long int n,arr[5010],sum,i;

    while(scanf("%lld",&n)&&n)
    {
        sum=0;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        sort(arr,arr+n);

        for(i=0;i<n-1;i++)
        {
            arr[i+1]=arr[i]+arr[i+1];
            sum+=arr[i+1];
        }

        printf("%lld\n",sum);
    }

    return 0;
}
