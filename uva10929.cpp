using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int i,l,temp;
    char str[1010];

    while(scanf("%s",str))
    {
        if(str[0]=='0'&&strlen(str)==1)
            break;

        l=strlen(str);
        temp=0;

        for(i=0;i<l;i++)
        {
            temp=(temp*10)+(str[i]-48);
            if(temp>=11)
                temp=temp%11;
        }

        if(temp)
            printf("%s is not a multiple of 11.\n",str);
        else
            printf("%s is a multiple of 11.\n",str);
    }

    return 0;
}
