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

bool flag[40000+7];

void PreCalKaprekarNum()
{
        int i, sq, t, a, b;
        for(i=2;i<=40000;i++) {
                sq = i*i;
                t = 10;
                for(a=sq%t,b=sq/t;a<sq;a=sq%t,b=sq/t)
                {
                        //cout<<a<<"    "<<b<<endl;
                        if(a>0&&b>0&&a+b==i)
                        {
                                flag[i] = true;
                                break;
                        }
                        t*=10;
                }

        }
}
int main ()
{
        PreCalKaprekarNum();
        int t, a, b, i, Case = 1;
        scanf("%d",&t);

        while(t--)
        {
                printf("case #%d\n",Case++);
                scanf("%d %d",&a,&b);
                bool fg = true;
                for(i=a;i<=b;i++) if(flag[i]) fg = false,printf("%d\n",i);
                if(fg) printf("no kaprekar numbers\n");
                if(t) printf("\n");
        }
        return 0;
}

