// not completed (segment tree/histogram_

using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

char ch[2010][2010];
int arr[2010][2010];

int main()
{
    int m,n,i,j,x,k,maX,ans,temp,sum,T,Case=1,index;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&m,&n);
        temp=0;
        for(i=0;i<m;i++)
        {
            sum=0;
            scanf("%s",ch[i]);
            for(j=0;j<n;j++)
            {
                if(i==0)
                {
                    if(ch[i][j]=='0')
                        arr[i][j]=1;
                    else
                        arr[i][j]=0;
                    sum+=arr[i][j];
                }
                else
                {
                    if(ch[i][j]=='0')
                        arr[i][j]=1+arr[i-1][j];
                    else
                        arr[i][j]=0;
                    sum+=arr[i][j];
                }
            }
            if(sum>=temp)
            {
                index=i;
                temp=sum;
            }
            //cout<<sum<<endl;
        }

       /* for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }*/


        ans=0;
        i=index;
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
            ans=maX;

        /*for(i=0;i<m;i++)
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
        }*/

        printf("Case %d: %d\n",Case++,ans);
    }

    return 0;
}
