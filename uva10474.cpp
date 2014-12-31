using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

int arr[10010];

int binary_search(int x,int high)
{
    int low=0,mid;

    while(high>=low)
    {
         mid=(low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return -1;
}

int main()
{
    int i,x,Case=1,q,n,temp;
    while(scanf("%d%d",&n,&q))
    {
        if(n==0&&q==0)
            break;

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        sort(arr,arr+n);

        printf("CASE# %d:\n",Case++);

        while(q--)
        {
            scanf("%d",&x);
            temp=binary_search(x,n-1);

            if(temp==-1)
                printf("%d not found\n",x);
            else
            {
                while((temp-1)>=0&&arr[temp-1]==x)
                {
                    temp--;
                }

                printf("%d found at %d\n",x,temp+1);
            }
        }
    }

    return 0;
}
