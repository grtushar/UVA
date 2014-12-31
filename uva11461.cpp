using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int main()
{
    long long int a,b,i,count,temp;

    while(scanf("%lld%lld",&a,&b)==2)
    {
        count=0;

        if(a==0&&b==0)
            break;

        for(i=a;i<=b;i++)
        {
            temp=sqrt(i);
            if(temp*temp==i)
                count++;
        }

        printf("%lld\n",count);
    }

    return 0;
}
