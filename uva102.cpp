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

int main ()
{
    freopen("input.txt","r",stdin);
    int ans, ag, bg, cg, ab, bb, cb, ac, bc, cc, temp;
    while(scanf("%d %d %d %d %d %d %d %d %d",&ab,&ag,&ac,&bb,&bg,&bc,&cb,&cg,&cc)==9) {
        string str;
        str = "BCG";
        temp = (bb+cb)+(ac+cc)+(ag+bg); //BCG
        ans = temp;

        temp = (bb+cb)+(ag+cg)+(ac+bc); //BGC
        if(ans>temp) {
            ans = temp;
            str = "BGC";
        }

        temp = (bc+cc)+(ab+cb)+(ag+bg); //CBG
        if(ans>temp) {
            ans = temp;
            str = "CBG";
        }
        //cout<<"CBG "<<temp<<endl;

        temp = (bc+cc)+(ag+cg)+(ab+bb); //CGB
        if(ans>temp) {
            ans = temp;
            str = "CGB";
        }
        //cout<<"CGB "<<temp<<endl;

        temp = (bg+cg)+(ab+cb)+(ac+bc); //GBC
        if(ans>temp) {
            ans = temp;
            str = "GBC";
        }

        temp = (bg+cg)+(ac+cc)+(ab+bb); //GCB
        if(ans>temp) {
            ans = temp;
            str = "GCB";
        }

        cout<<str<<" "<<ans<<endl;
    }
    return 0;
}
