#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define siz 10000+10

vector<int>graph[siz];
bool visited[siz];
int cnt;

void dfs(int s)
{
        if(visited[s])
                return;

         visited[s]=true;
        int i;

        for(i=0;i<graph[s].size();i++)
        {
                if(visited[graph[s][i]]==false)
                        dfs(graph[s][i]);
        }
        cnt++;
}

int main()
{
        int t,n,m,l,i,u,v;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d%d",&n,&m,&l);

                for(i=0;i<=n;i++)
                {
                        graph[i].clear();
                        visited[i]=false;
                }

                for(i=0;i<m;i++)
                {
                        scanf("%d%d",&u,&v);
                        graph[u].push_back(v);
                        //graph[v].push_back(u);
                }

                cnt=0;

                while(l--)
                {
                        int z;
                        scanf("%d",&z);
                        dfs(z);
                }

                printf("%d\n",cnt);
        }

        return 0;
}
