using namespace std;

#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>

bool taken[10][10];

/*int dx[]={2,1,-1,-2,2,1,-1,-2};
int dy[]={-1,-2,-2,-1,1,2,2,1};*/


int dx[8] = {2,2,-2,-2,1,-1,-1,1};
int dy[8] = {1,-1,-1,1,2,2,-2,-2};


struct info
{
    int x,y,cost;
};

bool valid(int x,int y)
{
    if(x>=0&&x<8&&y>=0&&y<8&&taken[x][y]==false)
        return true;
    return false;
}

int main()
{
    int i,j,sx,sy,desx,desy;
    char str1[3],str2[3];

    while(scanf("%s%s",str1,str2)!=EOF)
    {

        sx=str1[1]-48;
        sy=str1[0]-96;
        desx=str2[1]-48;
        desy=str2[0]-96;

        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                taken[i][j]=false;

        info start,recent;

        start.x=sx-1;
        start.y=sy-1;
        start.cost=0;
        taken[sx-1][sy-1]=true;

        queue<info>Q;

        Q.push(start);

        //int flag=1;
        int ans=-1;

        while(!Q.empty()&&ans==-1)
        {
            recent=Q.front();
            Q.pop();

            if(recent.x==desx-1&&recent.y==desy-1)
            {
                ans=recent.cost;
                break;
            }

            for(i=0;i<8;i++)
            {
                int r1=recent.x+dx[i];
                int r2=recent.y+dy[i];

                if(valid(r1,r2))
                {
                    taken[r1][r2]=true;
                    start.x=r1;
                    start.y=r2;
                    start.cost=1+recent.cost;

                    if(r1==desx-1&&r2==desy-1)
                    {
                        ans=start.cost;
                        break;
                    }

                    Q.push(start);
                }
            }
        }

            printf("To get from %s to %s takes %d knight moves.\n",str1,str2,ans);

    }

    return 0;
}
