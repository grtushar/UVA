using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>


int main()
{
        int Case=1,r,c,n,i,x,y,ar,ac;
        bool row[10005],col[10005];

        while(scanf("%d%d%d",&r,&c,&n))
        {
                //cout<<"enter"<<endl;
                if(r==0&&c==0&&n==0)
                        break;

                for(i=0;i<=10005;i++)
                {
                        row[i]=col[i]=false;
                }

                for(i=0;i<n;i++)
                {
                        scanf("%d%d",&x,&y);
                        row[x]=true;
                        col[y]=true;
                }

                scanf("%d%d",&ar,&ac);

                bool escape=false;

                 int dx[] = { 0, 0, 0, -1, 1 };
                int dy[] = { 0, -1, 1, 0, 0 };

                for(i=0;i<5;i++)
                {
                        if(ar+dx[i]<r&&ar+dx[i]>=0&&ac+dy[i]>=0&&ac+dy[i]<c&&row[ar+dx[i]]==false&&col[ac+dy[i]]==false)
                                escape=true;
                }


                if(escape)
                        printf("Case %d: Escaped again! More 2D grid problems!\n",Case++);
                else
                        printf("Case %d: Party time! Let's find a restaurant!\n",Case++);
        }

        return 0;
}
