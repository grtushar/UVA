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
template <class T> T lcm(T a,T b){rgraphturn (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

struct edge
{
        int u,v,w;
        bool operator < ( const edge& p ) const
        {
                return w < p.w;
        }
};

#define N 1000+7
int par[N];
vector<edge>graph;
bool visited[N][N];
int find(int r)
{
        return (par[r]==r) ? r:  find(par[r]);
}

void mst(int n)
{
        sort(graph.begin(),graph.end());
        for(int i=0;i<n;i++) par[i]=i;

        int cnt=0, l=graph.size();
        for(int i=0;i<l;i++)
        {
                int u=find(graph[i].u);
                int v=find(graph[i].v);
                if(u!=v)
                {
                        //cout<<" U V   "<<graph[i].u<<"      "<<graph[i].v<<endl;
                        par[u]=v;
                        cnt++;
                        visited[graph[i].u][graph[i].v] = true;
                        if(cnt==n-1) break;
                }
        }
}

int main()
{
        int n,m, i;
        while(scanf("%d %d",&n,&m)==2&&(n+m))
        {
                for(i=0;i<m;i++) {
                        int u,v,w;
                        scanf("%d %d %d",&u, &v, &w);
                        edge temp;
                        temp.u=u; temp.v=v; temp.w=w;
                        graph.push_back(temp);
                }
                memset(visited,false,sizeof(visited));
                mst(n);
                vector<int>ans;
                for(i=0;i<graph.size();i++) if(!visited[graph[i].u][graph[i].v]) ans.push_back(graph[i].w);
                sort(ans.begin(), ans.end());

                int l = ans.size();
                if(l==0) {
                        printf("forest\n");
                        graph.clear();
                        continue;
                }
                for(i=0;i<l;i++) {
                        printf("%d",ans[i]);
                        if(i+1<l) printf(" ");
                }

                printf("\n");
                graph.clear();
        }
        return 0;
}
