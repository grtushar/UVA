using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int x,t,i,max,n,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>max)
                max=x;
        }

        printf("Case %d: %d\n",Case++,max);
    }

    return 0;
}
