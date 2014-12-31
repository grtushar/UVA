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

int temp[200000+10];

int gcd(int a, int b)
{
        if(b==0) return a;
        return gcd(b,a%b);
}


int main () {

        int i,j,cc,n,siz,rem,ans;

        temp[1] = 1;
        for(i=2;i<=200001/2;i++)
        {
                cc=0;
                for(j=i+1;j<=i+i;j++)
                {
                        cc+=gcd(i,j);
                }
                //cout<<gcd(100000,100000+i-1)<<endl;
                cout<<i<<endl;

                temp[i] = cc;
        }

       while(scanf("%d",&n)&&n)
       {
                for(i=1;i<n;i++)
                {
                        siz = (n-1)/i;
                        ans=siz*temp[i];
                        rem = (n-1)%i;

                        for(j=i+1;j<=n&&j<=i+i;j++)
                        {
                                ans+=gcd(i,j);
                        }
                }

                cout<<ans<<endl;
       }

        return 0;
}
