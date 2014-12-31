#include<stdio.h>

int main()
{
   long long int big,fe=100;
   scanf("%lld",&big);
   while(big)
   {
       printf("%lld ",big%fe);
       big=big/fe;
       printf("%lld\n",big);
       //fe=fe/10;
   }
    return 0;
}
