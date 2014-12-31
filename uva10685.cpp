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

#define N 5000+7
vector<int>graph[N];
bool visited[N];
int cnt;

void dfs(int s)
{
        cnt++;
        visited[s] = true;
        for(int i=0;i<graph[s].size();i++)
                if(!visited[graph[s][i]]) dfs(graph[s][i]);
}

int main ()
{
        int c, n, i;

        while(scanf("%d %d",&c, &n)==2&&(c+n))
        {
                cnt=0;
                map<string, int>m;
                string str, str1;
                for(i=0;i<c;i++)
                {
                        cin>>str;
                        if(!m[str]) m[str] = cnt++;
                        graph[i].clear();
                }

                for(i=0;i<n;i++)
                {
                        cin>>str>>str1;
                        graph[m[str]].push_back(m[str1]);
                        graph[m[str1]].push_back(m[str]);
                }

                int ans = -1;
                memset(visited, false, sizeof(visited));
                for(i=0;i<c;i++)
                {
                        if(!visited[i]) {
                                cnt = 0;
                                dfs(i);
                                ans = max(ans,cnt);
                        }
                }

                printf("%d\n",ans);
        }
        return 0;
}

