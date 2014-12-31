//{ Template

//{ C-headers
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
//{ C++-headers
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

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()
//}

char place[102][102];
int n,m;

int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};

bool valid(int x, int y)
{
        if(x<0||x>=n||y<0||y>=m) return true;
        if(x>=0&&x<n&&y>=0&&y<m&&place[x][y]=='.') return true;
        return false;
}

bool check(int x, int y)
{
        for(int i=0;i<8;i++)  if(!valid(x+dx[i],y+dy[i]))  return false;
        return true;
}
int main () {

        int cnt,i,j;
        while(scanf("%d%d",&n,&m)==2)
        {
                if(n==0&&m==0) break;
                for(i=0;i<n;i++) scanf("%s",place[i]);

                cnt=0;
                for(i=0;i<n;i++)
                {
                        for(j=0;j<m;j++)
                        {
                                if(place[i][j]=='*') if(check(i,j)) cnt++;
                        }
                }

                cout<<cnt<<endl;
        }
        return 0;
}
