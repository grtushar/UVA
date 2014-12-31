using namespace std;

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<ctype.h>

struct structure
{
    char c;
    int ocr;
}alpha[30];


bool cmp(structure a,structure b)
{
    if(a.ocr>b.ocr)
        return true;
    if(a.ocr==b.ocr)
        return a.c<b.c;
    return false;
}

int main()
{
    char str[500];
    int l,i,t,count[100],k;

    for(i=60;i<100;i++)
        count[i]=0;

    cin>>t;
    getchar();

    while(t--)
    {
        gets(str);
        l=strlen(str);

        for(i=0;i<l;i++)
        {
            if(isalpha(str[i]))
                count[toupper(str[i])]++;
        }
    }

    k=0;

    for(i=60;i<100;i++)
    {
        if(count[i]>0)
        {
            alpha[k].c=i;
            alpha[k].ocr=count[i];
            k++;
        }
    }

    sort(alpha,alpha+k,cmp);

    for(i=0;i<k;i++)
    {
        cout<<alpha[i].c<<" "<<alpha[i].ocr<<endl;
    }

    return 0;
}
