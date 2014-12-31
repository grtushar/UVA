using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int arr[110][110],n,i,j,k,sum,chR,chC,m;

    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        k=0;
        for(i=1;i<=n;i++)
        {
            sum=0;
            for(j=1;j<=n;j++)
            {
                scanf("%d",&arr[i][j]);
                sum+=arr[i][j];
            }

            if(sum%2)
            {
                chR=i;
                k++;
            }
        }

        m=0;
        for(j=1;j<=n;j++)
        {
            sum=0;
            for(i=1;i<=n;i++)
            {
                sum+=arr[i][j];
            }

            if(sum%2)
            {
                chC=j;
                m++;
            }
        }

        if(m==0 && k==0)
            printf("OK\n");
        else if(m==1 && k==1)
            printf("Change bit (%d,%d)\n",chR,chC);
        else
            printf("Corrupt\n");
    }

    return 0;
}
