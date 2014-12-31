/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

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

#define INF 1<<29
#define ll long long

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

struct info {
    int x, y, dis;
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n;
string graph[1007];
bool vis[1007][1007];

bool valid(int x, int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&!vis[x][y]) return true;
    return false;
}

int bfs(int x, int y)
{
    int i, j;
    for(i=0;i<n;i++) for(j=0;j<n;j++) vis[i][j] = false;
    queue<info>q;
    info start, temp;
    start.x = x;
    start.y = y;
    start.dis = 0;
    vis[x][y] = true;
    q.push(start);

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        int sx = temp.x, sy = temp.y, sdis = temp.dis;
        if(graph[sx][sy]=='3') return sdis;

        for(i=0;i<4;i++) {
            int rx = sx+dx[i];
            int ry = sy+dy[i];

            if(valid(rx,ry)) {
                vis[rx][ry] = true;
                start.x = rx;
                start.y = ry;
                start.dis = sdis+1;
                q.push(start);
            }
        }
    }
}

int main ()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d",&n)==1) {
        for(int i=0;i<n;i++) {
            cin>>graph[i];
        }

        int ans = -1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(graph[i][j]=='1')
                    ans = max(ans,bfs(i,j));
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
