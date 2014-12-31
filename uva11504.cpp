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

vector<int>graph[100000+7], graph2[100000+7];
bool visited1[100000+7], visited2[100000+7];
stack<int>scc;

void dfs1(int s)
{
        visited1[s] = true;
        for(int i = 0;i<graph[s].size();i++)
        {
                if(!visited1[graph[s][i]]) dfs1(graph[s][i]);
        }
        scc.push(s);
}

void dfs2(int s)
{
        visited2[s] = true;
        for(int i = 0;i<graph2[s].size();i++)
        {
                //cout<<s<<"   "<<graph2[s][i]<<endl;
                if(!visited2[graph2[s][i]]) dfs2(graph2[s][i]);
        }
}

int main ()
{
        int t, n, m, u, v, i;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d",&n,&m);
                for(i=0;i<=n;i++) { visited1[i] = visited2[i] = false; graph[i].clear(); }
                for(i=0;i<m;i++)
                {
                        scanf("%d %d",&u, &v);
                        u--; v--;
                        graph[u].push_back(v);
                        graph2[v].push_back(u);
                }

                int cnt = 0;
                for(i=0;i<n;i++)
                        if(!visited1[i]) {
                                dfs1(i);
                        }

                while(!scc.empty())
                {
                        u = scc.top();
                        scc.pop();

                        if(!visited2[u]) { dfs2(u); cnt++; }
                }

                printf("%d\n",cnt);

                while(!scc.empty()) scc.pop();
        }
        return 0;
}

