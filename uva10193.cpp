using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>

#define ll long long int

ll gcd(ll a, ll b)
{
        if(b==0) return a;
        return gcd(b,a%b);
}

int main()
{
        char str1[35],str2[35];
        int t,i,l1,l2,pr=1;
        ll a,b;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s%s",str1,str2);

                l1=strlen(str1);
                l2=strlen(str2);
                a=b=0;

                for(i=0;i<l1;i++)
                {
                        a+=((str1[i]-48)*pow(2,(l1-i-1)));
                }

                 for(i=0;i<l2;i++)
                {
                        b+=((str2[i]-48)*pow(2,(l2-i-1)));
                }

                if(gcd(a,b)==1) printf("Pair #%d: Love is not all you need!\n",pr++);
                else printf("Pair #%d: All you need is love!\n",pr++);
        }

        return 0;
}
