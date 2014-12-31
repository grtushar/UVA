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
    int t;
    string str;
}city[107];

struct ginfo {
    int v, cost, t;
    ginfo(int a, int b) {
        v = a;
        cost = b;
    }
    bool operator < ( const ginfo& p ) const {
        return cost > p.cost;
    }
};

vector<int>graph[107];
bool vis[107][107];

bool cmp(info a, info b)
{
    return a.t<b.t;
}

int DIST[107], w[107][107];

int djkstra(int s, int d)
{
    priority_queue<ginfo>Q;
    int i,u,v,crntcost;
    memset(DIST,9999,sizeof(DIST));
    DIST[s]=0;

    Q.push(ginfo(s,0));

    while(!Q.empty())
    {
        ginfo temp = Q.top();

        Q.pop();
        u = temp.v;
        //cout<<u<<"  poped "<<endl;
        if(u==d) return DIST[u];

        for(i=0;i<graph[u].size();i++)
        {
            v=graph[u][i];
            crntcost=DIST[u]+w[u][v];
            //cout<<DIST[v]<<"   "<<crntcost<<" cost "<<endl;

            if(DIST[v]>crntcost)
            {
                DIST[v]=crntcost;
                Q.push(ginfo(v,DIST[v]));
            }
        }
    }

    return -1;
}

int main ()
{
    int n, i, mn, t, st;
    string str, start, endd;
    while(scanf("%d",&n)==1&&n)
    {
        map<string,int>m, mplace;
        memset(vis,false,sizeof(vis));
        int cnt = 0;
        for(i=0;i<n;i++) {
            cin>>str;
            m[str] = cnt++;
        }

        scanf("%d",&mn);
        while(mn--) {
            scanf("%d",&t);
            for(i=0;i<t;i++) {
                cin>>city[i].t>>city[i].str;
                mplace[city[i].str] = max(city[i].t,mplace[city[i].str]);
            }

            sort(city,city+t,cmp);
            for(i=0;i<t-1;i++) {
                if(vis[m[city[i].str]][m[city[i+1].str]]) {
                    if(w[m[city[i].str]][m[city[i+1].str]]>(city[i+1].t-city[i].t))
                        w[m[city[i].str]][m[city[i+1].str]] = city[i+1].t-city[i].t;
                }
                else {
                    graph[m[city[i].str]].push_back(m[city[i+1].str]);
                    w[m[city[i].str]][m[city[i+1].str]] = city[i+1].t-city[i].t;
                    vis[m[city[i].str]][m[city[i+1].str]] = true;
                }

            }
        }

//        for(i=0;i<3;i++) {
//            cout<<"source : "<<i<<endl;
//            for(int j=0;j<graph[i].size();j++)
//                cout<<graph[i][j].v<<endl;
//        }

        cin>>st>>start>>endd;
        //cout<<m[start]<<"    "<<m[endd]<<" iiiiiii "<<endl;
        int ans = djkstra(m[start],m[endd]);

        if(ans == -1) printf("No connection\n");
        else {
            if(st>mplace[start]) printf("No connection\n");
            else printf("%04d %d\n",mplace[start],mplace[start]+ans);
        }

        for(i=0;i<=cnt;i++) graph[i].clear();
    }
//    int x = 2;
//    printf("%04d",x);
    return 0;
}
