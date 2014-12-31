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
/*
int lans, dans, length[107];
bool vis[107];
vector<int>graph[107];

void bfs(int s)
{
        vis[s] = true;
        length[s] = 0;
        lans = -1, dans = 777;
        queue<int>q;
        q.push(s);

        while(!q.empty())
        {
                int temp = q.front();
                q.pop();

                for(int i=0;i<graph[temp].size();i++)
                {
                        int v = graph[temp][i];
                        if(!vis[v])
                        {
                                q.push(v);
                                vis[v] = true;
                                length[v] = max(length[temp]+1,length[v]);
                                if(length[v]>lans)
                                {
                                        lans = length[v];
                                        dans = v;
                                }
                                else if(length[v]==lans)
                                {
                                        if(dans>v) dans = v;
                                }
                        }
                        else if(length[v]<length[temp]+1) {

                                length[v] = length[temp] + 1;
                                if(length[v]>lans)
                                {
                                        lans = length[v];
                                        dans = v;
                                }
                                else if(length[v]==lans)
                                {
                                        if(dans>v) dans = v;
                                }
                        }
                }
        }
}
int main ()
{
        int n, Case = 1, s, a, b;

        while(scanf("%d",&n)==1&&n)
        {
                scanf("%d",&s);
                while(scanf("%d %d",&a,&b)&&a+b)
                        graph[a].push_back(b);
                bfs(s);
                printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",Case++,s,lans,dans);
                for(int i=0;i<=n;i++) {
                        graph[i].clear();
                        vis[i] = false;
                        length[i] = -1;
                }
        }
        return 0;
}
*/

int main()
{
         int n, Case = 1, s, a, b, graph[107][107], lans, dans, i, j, k;

        while(scanf("%d",&n)==1&&n)
        {
                for(i=1;i<=n;i++)
                        for(j=1;j<=n;j++)
                                graph[i][j] = -777;

                scanf("%d",&s);
                while(scanf("%d %d",&a,&b)&&a+b)
                        graph[a][b] = 1;
                for(i=1;i<=n;i++)
                        for(j=1;j<=n;j++)
                                for(k=1;k<=n;k++)
                                        graph[j][k] = max(graph[j][k], graph[j][i]+graph[i][k]);

                lans = -7;
                for(i=1;i<=n;i++)
                        if(graph[s][i]>lans) {
                                lans = graph[s][i];
                                dans = i;
                        }

                printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",Case++,s,lans,dans);
        }
        return 0;
}
