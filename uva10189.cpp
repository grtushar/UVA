//{
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{
using namespace std;

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define INF 1<<29

#define pf printf
#define sc scanf


typedef long long int ll_d;

int row,col;
char place[110][110];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y)
{
        if(x>=0&&x<row&&y>=0&&y<col&&place[x][y]!='*')
                return true;
        return false;
}

int main()
{
        int i,j,m,Case=1;
        char c,arr[110][110];
        while(sc("%d%d",&row,&col))
        {
                if(row==0&&col==0)
                        break;

                 if(Case>1)
                        pf("\n");

                for(i=0;i<row;i++)
                {
                        for(j=0;j<col;j++)
                                place[i][j]='0';
                }
                for(i=0;i<row;i++)
                {
                        scanf("%s",arr[i]);
                }

                for(i=0;i<row;i++)
                {
                        for(j=0;j<col;j++)
                        {
                                c=arr[i][j];
                                if(c=='*')
                                {
                                        place[i][j]='*';
                                        for(m=0;m<8;m++)
                                        {
                                                int r1 = i+dx[m];
                                                int r2 = j+dy[m];

                                                if(valid(r1,r2))
                                                {
                                                        place[r1][r2]++;
                                                }
                                        }
                                }
                        }
                }

                pf("Field #%d:\n",Case++);

                for(i=0;i<row;i++)
                        pf("%s\n",place[i]);
        }

        return 0;
}
