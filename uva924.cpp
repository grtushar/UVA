using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define sz 2500+10

vector<int>graph[sz];
bool visited[sz];
int day[sz];

void bfs(int s)
{
        queue<int>Q;
        visited[s]=true;
        Q.push(s);
        day[s]=0;

        while(!Q.empty())
        {
                int u=Q.front();
                Q.pop();

                for(int i=0;i<graph[u].size();i++)
                {
                        int v=graph[u][i];

                        if(visited[v]==false)
                        {
                                visited[v]=true;
                                day[v]=day[u]+1;
                                Q.push(v);
                        }
                }
        }
}

int main()
{
        int emp,frequency[sz],x,n,i,q,s;
        scanf("%d",&emp);

        for(i=0;i<emp;i++)
        {
                scanf("%d",&n);
                while(n--)
                {
                        scanf("%d",&x);
                        graph[i].push_back(x);
                }
        }

        scanf("%d",&q);

        while(q--)
        {
                scanf("%d",&s);
                for(i=0;i<=emp;i++)
                {
                        visited[i]=false;
                        frequency[i]=0;
                }

                bfs(s);

                for(i=0;i<emp;i++)
                {
                        if(visited[i])
                                frequency[day[i]]++;
                }

                int max=-1,index;

                for(i=1;i<emp;i++)
                {
                        if(frequency[i]>max)
                        {
                                max=frequency[i];
                                index=i;
                        }
                }

                if(graph[s].size()==0)
                        printf("0\n");
                else
                        printf("%d %d\n",frequency[index],index);

               /* for(i=0;i<emp;i++)
                        graph[i].clear();*/

        }


        return 0;
}
