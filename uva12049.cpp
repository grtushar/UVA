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

int cnt1[20000+7];

int main ()
{
        int t, n, m, i, cnt, x;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d",&n,&m);
                map<int,int>mp; cnt = 1;
                for(i=0;i<n;i++) {
                        scanf("%d",&x);

                        if(mp[x]) cnt1[mp[x]]++;
                        else {
                                mp[x] = cnt++;
                                cnt1[mp[x]]++;
                        }
                }

                for(i=0;i<m;i++) {
                        scanf("%d",&x);

                        if(mp[x]) {
                                cnt1[mp[x]]--;
                                //if(cnt1[])
                        }
                        else {
                                mp[x] = cnt++;
                                cnt1[mp[x]]--;
                        }
                }

                int ans = 0;
                for(i=0;i<cnt;i++) {
                        if(cnt1[i]>0) ans+=cnt1[i];
                        else if(cnt1[i]<0) {
                                ans+=(abs(cnt1[i]));
                        }
                        cnt1[i] = 0;
                }

                cout<<ans<<endl;
        }
        return 0;
}

