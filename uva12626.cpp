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

bool check(char c) {
    if(c=='A'||c=='G'||c=='I'||c=='R'||c=='T'||c=='M') return true;
    return false;
}
int main ()
{
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--) {
        string str;
        cin>>str;
        int l = str.size();
        map<char,int>mp;

        for(int i=0;i<l;i++) if(check(str[i])) mp[str[i]]++;

        int ans = 999999;
        for(char c='A';c<='Z';c++) {
            if(check(c)) {
                //cout<<mp[c]<<endl;

                if(c=='A') ans = min(ans, (int)(mp[c]/3));
                else if(c=='R') ans = min(ans, (int)(mp[c]/2));
                else ans = min(ans, mp[c]);
            }
        }
        if(ans == 999999) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
