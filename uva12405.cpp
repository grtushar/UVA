using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
    char c[101];
    int T,n,count=0,i,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);
        scanf(" %s",&c);

        count=0;
        i=0;

        for(i=0;i<n;i++)
        {
            if(c[i]=='.')
            {
                count++;
                i+=2;
            }
        }

        printf("Case %d: %d\n",Case++,count);
    }

    return 0;
}
