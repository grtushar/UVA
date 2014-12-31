#include<stdio.h>

int main()
{
    long long int c,s,i,k,j;
    while(scanf("%lld %lld",&i,&j)!=EOF)
    {
        printf("%lld %lld",i,j);
        k=0;
        if(i>j)
        {
            s=i;
            i=j;
            j=s;
        }
        while(i<=j)
        {
            s=i++;
            c=1;
            while(s!=1)
            {
                c++;
                if(s%2)
                s=3*s+1;
                else
                s=s/2;
            }
            if(k<c)
                k=c;
        }
        printf(" %lld\n",k);
    }
    return 0;
}
