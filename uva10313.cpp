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

#define INF (1<<29)
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

int dp[307][307], cnt[307][307];

int main ()
{
    freopen("input.txt","r",stdin);
    int n, L1, L2, i, j, k; char c;
    bool flag1, flag2, flag3;
    for(i=0;i<=300;i++) {
        for(j=0;j<=300;j++) {
            if(i==1||j>=i) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }//cout<<"done"<<endl;

    for(i=2;i<=300;i++) {
        for(j=1;j<=300;j++) {
            for(k=j;k<=300;k++) {
                if(j+k<=300) dp[i][j+k] += dp[i-1][j];
            }
        }
    }

    for(i=0;i<=10;i++) {
        cout<<i<<" : ";
        for(j=0;j<=10;j++) {
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }

    while(scanf("%d%c",&n,&c)==2) {
        flag2 = flag3 = false;
        flag1 = true;
        if(c==' ') { scanf("%d%c",&L1,&c); flag2 = true; }
        if(c==' ') { scanf("%d",&L2); flag3 = true; }

        int ans = 0;
        if(flag3) {
            for(i=L1;i<=L2;i++) {
                ans+=dp[i][n];
            }
            //cout<<"two"<<endl;
        }
        else if(flag2) {
            ans = dp[L1][n];
            //cout<<"one"<<endl;
        }
        else {
            for(i=1;i<=300;i++) {
                ans += dp[i][n];
            }
            //cout<<"nothing"<<endl;
        }

        printf("%d\n",ans);
    }
    return 0;
}
