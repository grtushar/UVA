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

#define sz 207
bool wpoint[sz][sz], dpoint[sz][sz];
int mx, my, cnt;

void construct_graph(int x, int y)
{
    if(x>=mx||my>=y) return;
    if(wpoint[x][y]) {
        if(wpoint[x+1][y]&&wpoint[x+1][y+1]&&wpoint[x][y+1]) {

        }
    }

}

int main ()
{
    int wall, door, i, x, y, d, t;

    while(scanf("%d %d",&wall, &door)) {
        if(wall==-1&&door==-1) break;

        mx = my = -1; cnt = 0;
        for(i=0;i<wall;i++) {
            scanf("%d %d %d %d",&x,&y,&d,&t);
            mx = max(mx,x);
            my = max(my,y);
            if(d==0) {
                while(x<=t) {
                    wpoint[x][y] = true;
                    x++;
                }
            }
            else {
                while(y<=t) {
                    wpoint[x][y] = true;
                    y++;
                }
            }
        }

        for(i=0;i<door;i++) {
            scanf("%d %d %d",&x,&y,&d);
            dpoint[x][y] = true;
            if(d==0) dpoint[x+1][y] = true;
            else dpoint[x][y+1] = true;
        }

        construct_graph(1,1);
    }
    return 0;
}
