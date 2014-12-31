using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

int parent[200000+10],ans[200000+10];


int parent_find(int u)
{
        if(parent[u]==u)
                return u;
        return parent[u]=parent_find(parent[u]);
}

int main()
{
        int t,n,i;
        string f1,f2;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);
                map<string,int>m;
                int cnt=1;

                for(i=1;i<=2*n;i++)
                {
                        parent[i] = i;
                        ans[i] = 1;
                }

                while(n--)
                {
                        cin>>f1>>f2;

                        if(m[f1]==0) m[f1]=cnt++;
                        if(m[f2]==0) m[f2]=cnt++;

                        int p1 = parent_find(m[f1]);
                        int p2 = parent_find(m[f2]);

                        if(p1!=p2)
                        {
                                ans[p1] += ans[p2];
                                parent[p2] = p1;
                        }

                        printf("%d\n",ans[p1]);

                }
        }

        return 0;
}
