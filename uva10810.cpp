// TLE ( have to solve by merge sort)

using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

long long int arr[500000+10],brr[500000+10];

int main()
{
        long long int n,i,temp,cnt,j;

        while(scanf("%lld",&n)==1&&n)
        {
                for(i=0;i<n;i++){
                        scanf("%lld",&arr[i]);
                        brr[i]=arr[i];
                }

                sort(brr,brr+n);

                cnt=0;
                for(i=0;i<n-1;i++)
                {
                        if(arr[i]==brr[i]) continue;
                        for(j=i+1;j<n;j++)
                        {
                                if(arr[j]<arr[i])
                                {
                                        temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
                                        cnt++;
                                }
                        }
                }

                printf("%lld\n",cnt);
        }

        return 0;
}
