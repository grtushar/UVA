using namespace std;

#include<iostream>
#include<cstdio>
#include<list>
#include<cstring>

int main()
{
       char str[100000+10];
        int l,i;

        while(scanf("%s",str)!=EOF)
        {
                l = strlen(str);

                list<char>v;
                list<char>::iterator it=v.begin();

                for(i=0;i<l;i++)
                {
                        if(str[i]=='[')
                                it = v.begin();
                        else if(str[i]==']')
                                it = v.end();
                        else
                                v.insert(it,str[i]);
                }

                for(it = v.begin();it!=v.end();it++)
                        printf("%c",*it);
                printf("\n");
        }

        return 0;
}
