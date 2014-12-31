using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
    int i,l,ocr;
    char str[140];

    while(gets(str))
    {
        l=strlen(str);

        for(i=0;i<l;i++)
        {
            ocr=0;
            while(str[i]>='0'&&str[i]<='9')
                ocr+=str[i++]-48;

            if(str[i]=='!')
                cout<<endl;
            while(ocr--)
            {
                if(str[i]=='b')
                    cout<<" ";
                else
                    cout<<str[i];
            }
        }

        cout<<endl;
    }

    return 0;
}
