#include<stdio.h>
#include<string.h>
unsigned long long int fb[55];
unsigned long long int fibonacci(unsigned long long int n)
{
    if(fb[n]!=-1)
    return fb[n];
    else
    return fb[n]=(fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
unsigned long long int x;
    memset(fb,-1,sizeof fb);
    fb[0]=0;
    fb[1]=1;fb[2]=2;
//printf("%lf",sizeof(double));
    while(scanf("%llu",&x)&&x)
    {
          printf("%llu\n",fibonacci(x));
    }
    return 0;
}



