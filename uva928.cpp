using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

struct info
{
        int x,y,run;
};

bool visited[301][301][5];
char place[301][301];
int R,C;

bool valid(int x,int y,int z)
{
        if(x>=0&&x<R&&y>=0&&y<C&&place[x][y]!='#'&&visited[x][y][z]==false)
                return true;
        return false;
}

bool valid2(int x,int y)
{
        if(x>=0&&x<R&&y>=0&&y<C&&place[x][y]!='#')
                return true;
        return false;
}

int check(int x)
{
       return (x+1)%3;
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main()
{
        int t,i,j,sr,sc;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&R,&C);

                for(i=0;i<R;i++)
                        scanf("%s",place[i]);

                for(i=0;i<R;i++)
                {
                        for(j=0;j<C;j++)
                        {
                                if(place[i][j]=='S')
                                {
                                        sr=i;
                                        sc=j;
                                }
                        }
                }

                memset(visited,false,sizeof(visited));

                info crnt,now;

                crnt.x=sr;
                crnt.y=sc;
                //crnt.cost=0;
                crnt.run=0;

                queue<info>Q;
                //Q.empty();
                Q.push(crnt);
                visited[sr][sc][0]=true;
                bool flag=true;

                while(!Q.empty())
                {
                        now=Q.front();
                        Q.pop();

                        if(place[now.x][now.y]=='E')
                        {
                                flag=false;
                                break;
                        }

                        for(i=0;i<4;i++)
                        {
                                int r1=now.x;
                                int r2=now.y;
                                bool val=true;


                                for(int k=0;k<=now.run%3;k++)
                                {
                                        r1+=dx[i];
                                        r2+=dy[i];
                                        if(!valid2(r1,r2))
                                            val=false;
                                }


                                if(val&&valid(r1,r2,((now.run+1)%3)))
                                {
                                        visited[r1][r2][check(now.run)]=true;
                                        crnt.x=r1;
                                        crnt.y=r2;

                                        crnt.run=now.run+1;
                                        Q.push(crnt);
                                }

                        }
                }

                if(flag)
                        printf("NO\n");
                else
                        printf("%d\n",now.run);
        }

        return 0;
}


  /* crnt.cost=now.run+1;
                                        crnt.run=check(now.run);*/


  /*for(i=0;i<4;i++)
                                        {
                                                r1+=dx[i];
                                                r2+=dy[i];
                                                if(r1==dr&&r2==dc)
                                                {
                                                        flag=false;
                                                        break;
                                                }
                                        }*/
