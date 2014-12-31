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
}graph[107];

struct edge {
        int u, v; double w;
        bool operator < (const edge& c) const
        {
                return w<c.w;
        }
};

vector<edge>v;

int pre[107];

int find(int x)
{
        return (pre[x]==x ? x: find(pre[x]));
}
int n, mp[200][200], cnt2;
double cost;

void mst()
{
        int sz = v.size(), cnt = 0, i;
        sort(v.begin(), v.end());

        for(i=0;i<cnt2;i++) pre[i] = i;

        for(i=0;cnt<cnt2-1&&i<sz;i++)
        {
                int u = find(v[i].u);
                int vv = find(v[i].v);

                if(u!=vv)
                {
                        pre[u] = vv;
                        cost+=v[i].w;
                        cnt++;
                }
        }
        //cout<<"i : "<<i<<endl;
}

int main ()
{
        int i, j, Case = 1, t;

        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                int cnt1 = 1;
                cnt2 = 0;

                map<double, int>m;
                for(i=0;i<n;i++)
                {
                        scanf("%lf %lf",&graph[i].x, &graph[i].y);
                        if(m[graph[i].x]==0) m[graph[i].x] = cnt1++;
                        if(m[graph[i].y]==0) m[graph[i].y] = cnt1++;

                        mp[m[graph[i].x]][m[graph[i].y]] = cnt2++;


                        for(j=0;j<i;j++)
                        {
                                edge ed;
                                ed.u = mp[m[graph[j].x]][m[graph[j].y]];
                                ed.v = mp[m[graph[i].x]][m[graph[i].y]];
                                ed.w = sqrt(squ(graph[i].x-graph[j].x)+squ(graph[i].y-graph[j].y));

                                v.push_back(ed);
                        }
                }

                cost = 0.0;
                mst();
                printf("%.2lf\n",cost);
                v.clear();
                if(t) printf("\n");
        }
        return 0;
}


