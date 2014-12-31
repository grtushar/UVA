using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int main()
{
    int m,n,i,j,x,arr[110][110],k,maX,ans,temp,sum;

    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>x;
                x=x?0:1;
                arr[i][j]=x;
            }
        }

        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]==1)
                    arr[i][j]=arr[i][j]+arr[i-1][j];
            }
        }

        ans=0;

        for(i=0;i<m;i++)
        {
            maX=0;
            for(k=0;k<n;k++)
            {
                temp=arr[i][k];
                sum=0;
                for(j=k;j<n;j++)
                {
                   if(temp>arr[i][j])
                    break;
                   else
                    sum+=temp;
                }
                for(x=k-1;x>=0;x--)
                {
                    if(temp>arr[i][x])
                        break;
                    else
                        sum+=temp;
                }
                maX=max(maX,sum);
            }

            ans=max(maX,ans);
        }

        cout<<ans<<endl;
    }

    return 0;
}
