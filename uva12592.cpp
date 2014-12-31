using namespace std;

#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>

int main()
{
        int t,q;
        scanf("%d\n",&t);

        map<string,string>m;
        string str1,str2;

        while(t--)
        {
                getline(cin,str1);
                getline(cin,str2);

                m[str1]=str2;
        }

        scanf("%d\n",&q);

        while(q--)
        {
                getline(cin,str1);
                cout<<m[str1]<<endl;
        }

        return 0;
}
