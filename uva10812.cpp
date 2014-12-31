using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    int t,sum,dif,temp;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&sum,&dif);

        if(sum>=dif&&(sum+dif)%2==0)
        {
            printf("%d %d\n",(sum+dif)/2,(sum-dif)/2);
        }
        else
        {
            printf("impossible\n");
        }
    }

    return 0;
}
