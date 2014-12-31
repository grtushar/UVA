using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

struct name
{
    string sn;
    int count;
}sarr[2010];

bool cmp(name a,name b)
{
    if(a.sn<b.sn)
        return true;
    return false;
}

int main()
{
    int n,i,k;


    map<string,int>m;
    map<string,int>::iterator it;
    scanf("%d",&n);
    getchar();

    for(i=0;i<n;i++)
    {
        char str[80],ch[80];
        gets(str);

        sscanf(str,"%s",ch);
       // getchar();
        m[ch]++;
    }
    i=0;

    for(it=m.begin();it!=m.end();it++)
    {
        sarr[i].count=(*it).second;
        sarr[i].sn=(*it).first;
        i++;
    }

    sort(sarr,sarr+i,cmp);

    for(k=0;k<i;k++)
    {
        cout<<sarr[k].sn<<" "<<sarr[k].count<<endl;
    }

    return 0;
}
