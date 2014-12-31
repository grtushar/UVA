using namespace std;

#include<iostream>
#include<cstdio>


int main()
{
    char c;
    int flag=0;

    while(scanf("%c",&c)==1)
    {
            if(c=='\"')
            {
                if(!flag)
                {
                    printf("``");
                    flag=1;
                }
                else
                {
                    printf("\'\'");
                    flag=0;
                }
            }

            else
                putchar(c);
    }


    return 0;
}
