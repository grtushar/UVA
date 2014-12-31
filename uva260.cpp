using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

char place[205][205];
int n;
bool visited[205][205];

struct info
{
        int x,y;
};

int dx[]={-1,0,1,-1,0,1};
int dy[]={-1,-1,0,0,1,1};

bool check1(int x, int y)
{
        if(x>=0&&x<n&&y>=0&&y<n&&place[x][y]=='b'&&visited[x][y]==false)
                return true;
        return false;
}

bool bfs(int x,int y)
{
        info start,run;
        start.x=x;
        start.y=y;
        queue<info>Q;
        Q.push(start);
        visited[x][y]=true;

        while(!Q.empty())
        {
                run=Q.front();
                Q.pop();

                for(int i=0;i<6;i++)
                {
                        int r1=run.x+dx[i];
                        int r2=run.y+dy[i];


                        if(check1(r1,r2))
                        {
                                visited[r1][r2]=true;
                                start.x=r1; start.y=r2;
                                if(r1==n-1)
                                        return true;
                                Q.push(start);
                        }

                }
        }

        return false;
}

int main()
{
        int Case=1,i;
        while(scanf("%d",&n)&&n)
        {
                for(i=0;i<n;i++)
                        scanf("%s",place[i]);

                info start,run;
                memset(visited,false,sizeof(visited));
                bool flag=false;

                for(i=0;i<n;i++)
                {
                        if(place[0][i]=='b'&&visited[0][i]==false&&flag==false)
                        {
                                flag=bfs(0,i);
                        }
                }

                if(flag)
                {
                        printf("%d B\n",Case++);
                }
                else
                {
                        printf("%d W\n",Case++);
                }

        }

        return 0;
}
