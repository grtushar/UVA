using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

int main()
{
        int t,n;
        char str[25];
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",str);
                int l=strlen(str);
                scanf("%d",&n);

                //int fac=factorial(n);
                sort(str,str+l);
                for(int i=1;i<=n;i++)
                        next_permutation(str,str+l);

                printf("%s\n",str);
        }

        return 0;
}
