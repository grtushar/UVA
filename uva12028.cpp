using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long int ll_d;

ll_d absolute(ll_d x)
{
        if(x<0)
                return -x;
        return x;
}
int main()
{
        ll_d t,n,k,c,Case=1,arr[100000+5],sum[100000+5],i,ans,temp;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld%lld%lld%lld",&k,&c,&n,&arr[0]);

                for(i=1;i<n;i++)
                {
                        arr[i] =  ((((k%1000007)*(arr[i - 1]%1000007))%1000007) + (c%1000007))%1000007;
                       //arr [i] = (k * arr [i - 1] + c) % 1000007;

                        //cout<<arr[i]<<endl;
                }

                sort(arr,arr+n);

               // ans=sum[n-1]=arr[n-1];
               temp=sum[0]=arr[0];

                for(i=1;i<n;i++)
                {
                        sum[i]=temp+arr[i];
                        temp=sum[i];

                       // cout<<sum[i]<<" ";
                }
                ans=0;

                for(i=0;i<n;i++)
                {
                        temp=(n-(i+1))*arr[i];
                        ans+=absolute((sum[n-1]-sum[i])-temp);
                }

                printf("Case %lld: %lld\n",Case++,ans);
        }

        return 0;
}
