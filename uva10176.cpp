using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>

#define mod 131071

int main()
{
        int temp;
        char ch;

        while(cin>>ch)
        {
                temp=0;
               temp=ch-48;

               while(cin>>ch)
               {
                       if(ch=='#') break;
                       temp=temp*2+ch-48;
                       temp%=mod;
               }

                if(temp) printf("NO\n");
                else printf("YES\n");
        }

        return 0;
}
