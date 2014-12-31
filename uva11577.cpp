using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

int main()
{
    char str[210];
    int t,count[200],i;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        for(i=95;i<130;i++)
            count[i]=0;
        gets(str);
        int l=strlen(str),maX=0;

        for(i=0;i<l;i++)
        {
            if(!isalpha(str[i]))
                continue;
            str[i]=tolower(str[i]);
            count[str[i]]++;
            if(count[str[i]]>maX)
                maX=count[str[i]];
        }

        for(i=97;i<124;i++)
        {
            if(count[i]==maX)
                printf("%c",i);
        }

        cout<<endl;
    }

    return 0;
}
