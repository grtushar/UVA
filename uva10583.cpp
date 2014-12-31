using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

vector<int>graph[50000+10];
bool visited[50000+10];

void dfs(int s)
{
        visited[s]=true;

        for(int i=0;i<graph[s].size();i++)
        {
                if(visited[graph[s][i]]==false)
                        dfs(graph[s][i]);
        }
}
int main()
{
        int n,m,i,u,v,cnt,Case=1;
        while(scanf("%d%d",&n,&m))
        {
                 if(n==0&&m==0)
                        break;

                for(i=0;i<=n;i++)
                {
                        graph[i].clear();
                        visited[i]=false;
                }

                while(m--)
                {
                        scanf("%d%d",&u,&v);
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                }

                cnt=0;

                for(i=1;i<=n;i++)
                {
                        if(visited[i]==false)
                        {
                                dfs(i);
                                cnt++;
                        }
                }

                printf("Case %d: %d\n",Case++,cnt);

        }

        return 0;
}
