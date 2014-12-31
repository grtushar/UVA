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

int main ()
{
        int n, m, q, graph[107][107], Case = 1, j, i, u, v, w, k;
        bool first = true;
        while(scanf("%d %d %d",&n, &m, &q)==3&&(n+m+q))
        {
                if(first) first = false;
                else printf("\n");
                for(i=0;i<n;i++) for(j=0;j<n;j++) graph[i][j] = INF;
                for(i=0;i<m;i++)
                {
                        scanf("%d %d %d",&u, &v, &w);
                        u--; v--;
                        graph[u][v] = w;
                        graph[v][u] = w;
                }

                for(k=0;k<n;k++)
                        for(i=0;i<n;i++)
                                for(j=0;j<n;j++)
                                        graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));

                printf("Case #%d\n",Case++);
                while(q--)
                {
                        scanf("%d %d", &u, &v);
                        u--; v--;
                        if(graph[u][v]==INF) printf("no path\n");
                        else printf("%d\n",graph[u][v]);
                }
        }
        return 0;
}

