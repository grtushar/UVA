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

char grid[107][107];
bool vis[107][107];
int n, m;
int dx[10] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[10] = {-1, 0, 1, -1, 1, -1, 0, 1};

void go(int i, int j) {
    vis[i][j] = true;
    for(int k = 0;k<8;k++) {
        int rx = i+dx[k];
        int ry = j+dy[k];
        if(rx>=0&&rx<n&&ry>=0&&ry<m&&grid[rx][ry]=='@'&&!vis[rx][ry]) go(rx,ry);
    }
}

int main ()
{
    freopen("input.txt","r",stdin);
    int i, j;
    while(scanf("%d %d",&n,&m)==2) {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++) scanf("%s",grid[i]);

        memset(vis,false,sizeof(vis));
        int cnt = 0;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(grid[i][j]=='@'&&!vis[i][j]) { go(i, j); cnt++; }
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}
