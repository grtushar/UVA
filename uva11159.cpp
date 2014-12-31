
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
#define N 107

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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

/*................Code Starts Here................*/

int Left[N], Right[N], n, m;
bool seen[N];
vector<int>graph[N];

bool kuhn(int u) {
    for(int i = 0;i<graph[u].size();i++) {
        int v = graph[u][i];
        if(seen[v]) continue;
        seen[v] = 1;
        if(Right[v] == -1 || kuhn(Right[v])) {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }

    return false;
}

int BM() {
    int i, cnt = 0;
    for(i=0;i<=100;i++) Left[i] = Right[i] = -1;
    for(i=0;i<n;i++) {
        if(Left[i]==-1) {
            memset(seen, 0, sizeof(seen));
            if(kuhn(i)) cnt++;
        }
    }

    return cnt;
}

int main() {
    //freopen("input.txt","r",stdin);
    int t, x, arr[N], i, Case = 1, j;
    scanf("%d",&t);

    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);

        scanf("%d",&m);
        for(i=0;i<m;i++) {
            scanf("%d",&x);
            for(j=0;j<n;j++) {
                if(x%arr[j]==0) graph[j].push_back(i);
            }
        }

        printf("Case %d: %d\n",Case++, BM());
        for(i=0;i<=n;i++) graph[i].clear();
    }
    return 0;
}

