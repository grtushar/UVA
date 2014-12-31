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

ll dp[22][22], n, an1;

ll solve(ll i, ll j)
{
    if(i==n&&j==1) {
        return dp[i][j] = an1;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    ll k;
    if(i>=j) {
        ll r1, r2;
        if(i<n) {
            r1 = 0;
            for(k=i+1;k<=n;k++) {
                r1 = max(r1,solve(k,1)+solve(k,j));
            }
        }
        else if(i==n) r1 = 0;

        if(j>0) {
            r2 = 0;
            for(k=1;k<j;k++) {
                r2 = max(r2,solve(i,k)+solve(n,k));
            }
        }
        else if(j==0) r2 = 0;

        return dp[i][j] = r1+r2;
    }
    else {
        ll ret = 0;
        for(k=i;k<j;k++) {
            ret = max(ret,solve(i,k)+solve(k+1,j));
        }
        return dp[i][j] = ret;
    }
}
int main ()
{
    while(scanf("%lld %lld",&n,&an1)==2) {
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(1,n));
    }
    return 0;
}
