using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

struct info
{
       long long  int brief,exe;
}arr[1010];

bool cmp(info a,info b)
{
       /* if(a.exe==b.exe)
                return a.brief>b.brief;
        return (a.exe>b.exe);*/

        if(a.exe>b.exe)
                return true;
        return false;
}

int main()
{
        long long int n,sum,i,ans,Case=1;
        while(scanf("%lld",&n)&&n)
        {
                ans=sum=0;
                for(i=0;i<n;i++)
                {
                        scanf("%lld%lld",&arr[i].brief,&arr[i].exe);
                        sum+=arr[i].brief;
                }

               // sum+=arr[n-1].exe;

                sort(arr,arr+n,cmp);

                for(i=0;i<n;i++)
                {
                        //cout<<arr[i].brief<<"   "<<arr[i].exe<<endl;

                        ans+=arr[i].brief;
                        sum-=arr[i].brief;

                        if(arr[i].exe>sum)
                        {
                                ans+=(arr[i].exe-sum);
                                sum+=arr[i].exe-sum;
                        }
                }

                //ans+=arr[n-1].exe;

                printf("Case %lld: %lld\n",Case++,ans);

        }

        return 0;
}
