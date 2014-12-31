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


#define inf 30000

int DIST[20010];

struct graph {
    int node,cost;
    graph(int a,int b)
    {
        node=a;
        cost=b;
    }
    bool operator < ( const graph& p ) const {
        return cost > p.cost;
    }
};

vector<graph>edge[20000+10];

void Dijkstra(long s)
{
    priority_queue<int>Q;
    int i,u,v,crntcost;
    DIST[s]=0;

    Q.push(s);

    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();

        for(i=0;i<edge[u].size();i++)
        {
            v=edge[u][i].node;
            crntcost=DIST[u]+edge[u][i].cost;

            if(DIST[v]>crntcost)
            {
                DIST[v]=crntcost;
                Q.push(v);
            }
        }
    }
}

int main()
{
    long t,u,v,w,s,d,Case=1,n;
    long m,i;
    scanf("%ld",&t);

    while(t--)
    {
        scanf("%ld%ld%ld%ld",&n,&m,&s,&d);

        for(i=0;i<n;i++)
        {
           DIST[i]=inf;
           edge[i].clear();
        }

        for(i=0;i<m;i++)
        {
            scanf("%ld%ld%ld",&u,&v,&w);

            edge[u].push_back(graph(v,w));
            edge[v].push_back(graph(u,w));
        }

        Dijkstra(s);

        if(DIST[d]==inf)
        {
            printf("Case #%ld: unreachable\n",Case++);
        }
        else
        {
            printf("Case #%ld: %d\n",Case++,DIST[d]);
        }

    }

    return 0;
}


























/*using namespace std;

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>

#define inf 11000

vector<int>graph[20010];
int DIST[20010],cost[20010][20010],n;

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void Dijkstra(int s,int d)
{
    priority_queue<data>Q;
    data u,v;  int i;
    for(i=0;i<n;i++)
    {
       DIST[i]=inf;
    }
    //cout<<DIST[s]<<endl;
    DIST[s]=0;
    u.city=s;
    u.dist=0;
    Q.push(u);

    while(!Q.empty())
    {
        u=Q.top();
        if(u.dist>DIST[u.city])
            continue;
        if(u.city==d)
            break;
        Q.pop();

        for(i=0;i<graph[u.city].size();i++)
        {
            v.city=graph[u.city][i];
            v.dist=DIST[u.city]+cost[u.city][v.city];

            if(DIST[v.city]>v.dist)
            {
                DIST[v.city]=v.dist;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int t,u,v,w,s,d,Case=1;
    long long int m,i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%lld%d%d",&n,&m,&s,&d);

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);

            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u][v]=cost[v][u]=w;
        }

        Dijkstra(s,d);
        if(DIST[d]==inf)
        {
            printf("Case #%d: unreachable\n",Case++);
        }
        else
        {
            printf("Case #%d: %d\n",Case++,DIST[d]);
        }

        for(i=0;i<=n;i++)
        {
            graph[i].clear();
        }
    }

    return 0;
}
*/
