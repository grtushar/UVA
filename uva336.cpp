using namespace std;

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<map>


int m,n,dist[33],ttl,count;
bool taken[33];
vector<int>graph[33];


void bfs(int s)
{
    memset(taken,false,sizeof(taken));
    //memset(dist,-1,sizeof(dist));
    queue<int>Q;
    Q.push(s);
    taken[s]=true;
    dist[s]=0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            if(!taken[graph[u][i]])
            {
                dist[graph[u][i]]=dist[u]+1;
                if(dist[graph[u][i]]<=ttl)
                    count++;
                taken[graph[u][i]]=true;
                Q.push(graph[u][i]);
            }
        }
    }
}

int main()
{
    int edges,Case=1,u,v,i,s,nnn;

    while(scanf("%d",&edges)&&edges)
    {
        map<int,int>m;
        nnn=1;
        for(i=0;i<edges;i++)
        {
            scanf("%d%d",&u,&v);
            if(!m[u])
                m[u]=nnn++;
            if(!m[v])
                m[v]=nnn++;
            graph[m[u]].push_back(m[v]);
            graph[m[v]].push_back(m[u]);
        }

        while(scanf("%d%d",&s,&ttl))
        {
            if(s==0&&ttl==0)
                break;
            count=0;
            bfs(m[s]);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case++,(nnn-2)-count,s,ttl);
        }

        for(i=1;i<33;i++)
        {
            graph[i].clear();
        }
    }

    return 0;
}
