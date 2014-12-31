using namespace std;

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>


int flag,n;
vector<int>graph[210];
int color[210];

void bfs(int s)
{
    //memset(color,2,sizeof(color));
    for(int i=0;i<n;i++)
        color[i]=2;
    queue<int>Q;
    Q.push(s);
    color[s]=0;

    while(!Q.empty()&&flag)
    {
        int u = Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {

               if(color[graph[u][i]]==2)
               {
                  // cout<<graph[u][i]<<endl;
                   Q.push(graph[u][i]);
                   color[graph[u][i]]=(color[u]+1)%2;

               }
               else
               {
                   if(color[graph[u][i]]==color[u])
                   {
                        flag=0;
                        break;
                   }

               }

        }
    }
}

int main()
{
    int i,e,u,v;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        scanf("%d",&e);
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        flag=1;
        bfs(n-1);
        if(flag)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");

        for(i=0;i<n;i++)
            graph[i].clear();
    }
    return 0;
}

