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
template <class T> T squ(T a) { return a*a; }

struct info {
       double x, y;
}graph[777];

struct edge {
        int u, v; double w;
        bool operator < (const edge& c) const
        {
                return w<c.w;
        }
};

vector<edge>v;

int pre[777];

int find(int x)
{
        return (pre[x]==x ? x: find(pre[x]));
}
int n, tr;// mp[1507][1507], tr;
double cost;
bool visited[777];

void mst(int m)
{
        int sz = v.size(), cnt = m, i;
        sort(v.begin(), v.end());

        for(i=0;i<sz;i++)
        {
                if(tr>=n&&cnt>=n-1) break;
                int u = find(v[i].u);
                int vv = find(v[i].v);

                if(u!=vv)
                {
                        //cout<<v[i].u<<"      "<<v[i].v<<"      "<<tr<<endl;
                        if(!visited[v[i].u]) { tr++; visited[v[i].u] = true; }
                        if(!visited[v[i].v]) {tr++; visited[v[i].v] = true; }
                        //cout<<tr<<endl;
                        cnt++;
                        pre[u] = vv;
                        cost+=v[i].w;
                }
        }
        //cout<<"i : "<<i<<endl;
}

int main ()
{
        int i, j, u, vv;

        while(scanf("%d",&n)==1)
        {
                int cnt = 0;

                for(i=0;i<n;i++)
                {
                        visited[i] = 0;
                        scanf("%lf %lf",&graph[i].x, &graph[i].y);

                        for(j=0;j<i;j++)
                        {
                                edge ed;
                                ed.u = i;
                                ed.v = j;
                                ed.w = sqrt(squ(graph[i].x-graph[j].x)+squ(graph[i].y-graph[j].y));

                                v.push_back(ed);
                        }
                }

                tr = 0;
                int m; scanf("%d",&m);
                for(i=0;i<n;i++) pre[i] = i;
                for(i=0;i<m;i++)
                {
                        scanf("%d %d", &u, &vv);
                        u--; vv--;
                        if(visited[u]==0) { tr++; visited[u] = true; }
                        if(visited[vv] == 0 ) {tr++; visited[vv] = true; }
                        int up = find(u), vp=find(vv);
                        if(up!=vp) pre[up] = vp;
                }

                cost = 0.0;
                mst(m);
                printf("%.2lf\n",cost);
                v.clear();
        }
        return 0;
}



