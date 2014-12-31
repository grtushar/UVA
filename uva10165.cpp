
using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
        unsigned long long int x,XOR,n,i;

        while(scanf("%llu",&n)==1&&n)
        {
                XOR=0;
                for(i=0;i<n;i++){
                        scanf("%llu",&x);
                        XOR^=x;
                }

                if(XOR) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}
