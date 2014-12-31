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

#define INF (1<<29)
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

#define mx 507

struct info {
    int u, w;
    info(int a, int b) {
        u = a;
        w = b;
    }

    bool operator < (const info &p) const {
        return w>p.w;
    }
};

struct distance {
    bool odd, even;
    int cost_o, cost_e;
}dist[mx];

vector<info>graph[mx];
int n;

int djkstra()
{
    priority_queue<info>q;
    q.push(info(0,0));
    for(int i=0;i<n;i++) { dist[i].cost_e = dist[i].cost_o = 99999; dist[i].even = dist[i].odd = 0; }
    dist[0].cost_e = 0;
    dist[0].odd = 0;
    dist[0].even = 1;

    //cout<<dist[3].cost_e<<"  "<<dist[3].cost_o<<"  "<<dist[3].odd<<endl;

    while(!q.empty())
    {
        info temp = q.top();
        q.pop();

        int u = temp.u;  //cout<<" U : "<<u<<endl;
        for(int i = 0;i<graph[u].size();i++) {
            int v = graph[u][i].u;

            if(dist[u].odd) {
                //cout<<"even u : "<<u<<" v : "<<v<<"  "<<dist[v].cost_o<<"  "<<dist[u].cost_e<<"  "<<graph[u][i].w<<endl;
                if(dist[v].cost_e>(dist[u].cost_o+graph[u][i].w)) {
                    dist[v].cost_e = dist[u].cost_o+graph[u][i].w;
                    dist[v].even = 1;
                    q.push(info(v,dist[v].cost_e));
                }
            }
            if(dist[u].even) {
                //cout<<"odd u : "<<u<<" v : "<<v<<"  "<<dist[v].cost_e<<"  "<<dist[u].cost_o<<"  "<<graph[u][i].w<<endl;
                if(dist[v].cost_o>(dist[u].cost_e+graph[u][i].w)) {
                    dist[v].cost_o = dist[u].cost_e+graph[u][i].w;
                    dist[v].odd = 1;
                    q.push(info(v,dist[v].cost_o));
                }

            }
        }
    }

    return dist[n-1].cost_e;
}

int main ()
{
    int m, u, v, w, Set = 1;
    while(scanf("%d %d",&n,&m)==2)
    {
        while(m--) {
            scanf("%d %d %d",&u, &v, &w);
            graph[u].push_back(info(v,w));
            graph[v].push_back(info(u,w));
        }

        int ans = djkstra();

        printf("Set #%d\n",Set++);
        if(ans==99999) printf("?\n");
        else printf("%d\n",ans);

        for(int i = 0;i<n;i++) graph[i].clear();
    }
    return 0;
}
