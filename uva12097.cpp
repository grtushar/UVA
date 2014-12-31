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

int n, f;
double vol[10000+7];

bool check(double val) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        cnt+=(int)(vol[i]/val);
        if(cnt>=(f+1)) return true;
    }
    return false;
}

double BS(double low, double high) {
    while((high-low)>0.0005) {
        double mid = (low+high)/2.0;
        if(check(mid)) low = mid;
        else high = mid;
    }

    return low;
}
int main ()
{
    freopen("input.txt","r",stdin);
    int t; double x;
    scanf("%d",&t);

    while(t--) {
        double mx = 0.0;
        scanf("%d %d",&n, &f);
        for(int i = 0;i<n;i++) {
            scanf("%lf",&x);
            vol[i] = (double)(PI*x*x);
            mx = max(mx, vol[i]);
        }

        printf("%0.6lf\n",BS(0.0,mx));
    }
    return 0;
}

/*
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2

25.1327
3.1416
50.2655
*/
