using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int titanic(char c)
{
    if(c=='a'||c=='d'||c=='g'||c=='j'||c=='m'||c=='p'||c=='t'||c=='w'||c==' ')
        return 1;
    else if(c=='b'||c=='e'||c=='h'||c=='k'||c=='n'||c=='q'||c=='u'||c=='x')
        return 2;
    else if(c=='z'||c=='s')
        return 4;
    else
        return 3;
}

int main()
{
    int t,i,l,Case=1,ans;
    string str;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        ans=0;
        getline(cin,str);
        l=str.length();

        for(i=0;i<l;i++)
        {
            ans+=titanic(str[i]);
        }

        printf("Case #%d: %d\n",Case++,ans);
    }

    return 0;
}
