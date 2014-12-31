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
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()
//}


int main () {

        ll t,x1,x2,y1,y2,i,Case=1,index1,index2;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
                index1=y1+x1;
                index1=((1+index1)*index1)/2+x1;
                index2=y2+x2;
                index2=((1+index2)*index2)/2+x2;
                printf("Case %lld: %lld\n",Case++,index2-index1);
        }

        return 0;
}
