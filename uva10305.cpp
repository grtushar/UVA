using namespace std;

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<stack>

stack<int>ans;
vector<int>graph[110];
bool taken[110];

void dfs(int p)
{
    int i;
    if(taken[p]==false)
    {
        for(i=0;i<graph[p].size();i++)
        {
            dfs(graph[p][i]);

        }
        ans.push(p);
        taken[p]=true;
        graph[p].clear();
    }
}

int main()
{
    int t,m,n,i,u,v;

    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }

        memset(taken,false,sizeof(taken));
        for(i=1;i<=m;i++)
            dfs(i);
        for(i=0;i<m;i++)
        {
            int x=ans.top();
            ans.pop();
            if(i>0)
                printf(" ");
            printf("%d",x);
        }

        printf("\n");

    }

    return 0;
}
