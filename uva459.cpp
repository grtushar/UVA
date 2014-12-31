using namespace std;

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>

int par[1000];

int FindParent(int u)
{
    if(u!=par[u])
        return FindParent(par[u]);
    return par[u];
}


int main()
{
    int T,i,temp,count,node;
    char c;
    string str;
    cin>>T;

    while(T--)
    {
        count=0;
        memset(par,0,sizeof par);
        cin>>c;
        getchar();

        node=c-'A'+1;
        for(i=1;i<=node;i++)
        {
            par[i]=i;
        }

       while(getline(cin,str)&&str.length()>0)
       {
            par[FindParent(str[0]-'A'+1)] = FindParent(str[1]-'A'+1);
       }


        for(i=1;i<=node;i++)
        {
            if(par[i]==i)
                count++;
        }

        cout<<count<<endl;
        if(T)
            cout<<endl;
    }

    return 0;
}
