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
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

/*................Code Starts Here................*/

struct info {
    int x, y;
}bob[107], dog[107];
double dist[107][107];
int cx[107], cy[107], n, m;
bool vis[107];
vector<int>graph[107];

double line(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool dfs(int u) {
    for(int i=0;i<graph[u].size();i++) {
        int v=graph[u][i];
        if(!vis[v]) {
            vis[v] = true;
            if(cy[v]==-1||dfs(cy[v])) {
                cy[v]=u;
                cx[u]=v;
                return true;
            }
        }
    }
    return false;
}
int BPM() {
    int ans=0;
    memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));

    for(int i=0;i<n;i++) {
        if(cx[i]==-1) {
            memset(vis, false, sizeof(vis));
            if(dfs(i))
                ans++;
        }
    }
    return ans;
}

int main() {
    //cout<<line(3, 9, 1, 4)<<" "<<line(3, 9, 5, 7)<<" "<<line(1, 4, 5, 7)<<endl;
    freopen("input.txt","r",stdin);
    int t, i, j;
    scanf("%d",&t);

    while(t--) {
        scanf("%d %d",&n, &m);
        for(i=0;i<n;i++) {
            scanf("%d %d",&bob[i].x,&bob[i].y);
            if(i==0) continue;
            dist[i][i-1] = dist[i-1][i] = line(bob[i].x, bob[i].y, bob[i-1].x, bob[i-1].y);
        }

        for(i=0;i<m;i++) {
            scanf("%d %d",&dog[i].x, &dog[i].y);
            int x = dog[i].x, y = dog[i].y;
            for(j=0;j<n-1;j++) {
                double dist1 = line(x, y, bob[j].x, bob[j].y);
                double dist2 = line(x, y, bob[j+1].x, bob[j+1].y);
                if((dist1+dist2) <= (2.0*dist[j][j+1])) graph[j].push_back(i);
            }
        }

        printf("%d\n",n+BPM());
        for(i=0;i<n;i++) {
            if(i) cout<<" ";
            printf("%d %d",bob[i].x, bob[i].y);
            if(cx[i]!=-1) printf(" %d %d",dog[cx[i]].x,dog[cx[i]].y);
        }
        cout<<endl;
        if(t) cout<<endl;
        for(i=0;i<=n;i++) graph[i].clear();
    }
    return 0;
}
