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

struct info {
        char c;
        int n;
}cnt[150], cnt2[150];

bool cmp(info a, info b) {
        return a.n>b.n;
}

int main ()
{
        int t, i, l1, l2;
        scanf("%d",&t);

        while(t--)
        {
                string str1, str2;
                cin>>str1>>str2;
                l1 = str1.size(); l2 = str2.size();

                for(i=0;i<150;i++) cnt[i].n = cnt2[i].n = 0;

                for(i=0;i<l1;i++) { cnt[str1[i]].c = str1[i]; cnt[str1[i]].n++; }

                for(i=0;i<l2;i++) { cnt2[str2[i]].c = str2[i]; cnt2[str2[i]].n++; }

                sort(cnt, cnt+150, cmp);
                sort(cnt2, cnt2+150, cmp);

                i=0;
                map<char,char>m;
                while(cnt[i].n>0) { m[cnt2[i].c] = cnt[i].c; i++; }
                for(i = 0;i<l2;i++) cout<<m[str2[i]];
                cout<<endl;
                if(t) cout<<endl;
        }
        return 0;
}

