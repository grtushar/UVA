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
#define ll unsigned long long

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

ll dp[62][62];

ll solve(int n, int back)
{
    if(n<=1) return 1;

    if(dp[n][back]!=-1) return dp[n][back];

    ll sum = 0, i;
    for(i=1;i<=back;i++) {
        sum+=solve(n-i,back);
    }

    return dp[n][back] = 1+sum;
}
int main ()
{

    int n, back, Case = 1;
    while(scanf("%d %d",&n,&back)&&n<=60) {
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %llu\n",Case++,solve(n,back));
    }
    return 0;
}


/*
ll dp[62], i, temp = 1, Case = 1;
    int n, back;
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for(i=3;i<=59;i++) {
        temp*=2;
        dp[i] = dp[i-1]+temp;
    }

    while(scanf("%d %d",&n,&back)&&n<=60) {
        if(n<=1) printf("Case %llu: 1\n",Case++);
        else printf("Case %llu: %llu\n",Case++,back+1+(dp[n-1])*back);
    }
*/
