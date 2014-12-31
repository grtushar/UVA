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
    int def, atk;
    string name;
}player[11];

bool cmp(info a, info b)
{
    if(a.atk==b.atk){
        if(a.def==b.def) {
            return a.name<b.name;
        }
        else return a.def<b.def;
    }
    else return a.atk>b.atk;
}

bool cmpp(info a, info b)
{
    return a.name<b.name;
}

int main ()
{
    freopen("input.txt","r",stdin);
    int t, i, Case = 1;
    scanf("%d",&t);
    while(t--) {
        for(i=0;i<10;i++) {
            cin>>player[i].name>>player[i].atk>>player[i].def;
        }

        sort(player,player+10,cmp);
        sort(player,player+5,cmpp);
        sort(player+5,player+10,cmpp);
        printf("Case %d:\n",Case++);
        cout<<"("<<player[0].name<<", "<<player[1].name<<", "<<player[2].name<<", "<<player[3].name<<", "<<player[4].name<<")"<<endl;
		cout<<"("<<player[5].name<<", "<<player[6].name<<", "<<player[7].name<<", "<<player[8].name<<", "<<player[9].name<<")"<<endl;
    }
    return 0;
}
