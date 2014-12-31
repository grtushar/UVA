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

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

ll power(ll n,ll m)
{
    ll ans=1,p=n;
    while(m)
    {
        if(m&1) ans*=p;
        p*=p;
        m=m>>1;
    }
    return ans;
}


int main ()
{
        char c;

        while(scanf("%c",&c)==1)
        {
                if(c=='1') printf("`");
                if(c=='2') printf("1");
                if(c=='3') printf("2");
                if(c=='4')                printf("3");
                if(c=='5')                printf("4");
                if(c=='6')                printf("5");
                if(c=='7')                printf("6");
                if(c=='8')                printf("7");
                if(c=='9')                printf("8");
                if(c=='0')                printf("9");
                if(c=='-')                printf("0");
                if(c=='=')                printf("-");
                if(c=='W')                printf("Q");
                if(c=='E')                printf("W");
                if(c=='R')                printf("E");
                if(c=='T')                printf("R");
                if(c=='Y')                printf("T");
                if(c=='U')                printf("Y");
                if(c=='I')                printf("U");
                if(c=='O')                printf("I");
                if(c=='P')                printf("O");
                if(c=='[')                printf("P");
                if(c==']')              printf("[");
                if(c=='\\')  printf("]");
                if (c=='S')  printf("A");
                if (c=='D') printf("S");
                if (c=='F') printf("D");
                if (c=='G')printf("F");
                if (c=='H') printf("G");
                if (c=='J')  printf("H");
                if (c=='K') printf("J");
                if (c=='L') printf("K");
                if (c==';') printf("L");
                if (c=='\'') printf(";");
                if (c=='X') printf("Z");
                if (c=='C') printf("X");
                if (c=='V') printf("C");
                if (c=='B') printf("V");
                if (c=='N') printf("B");
                if (c=='M') printf("N");
                if (c==',') printf("M");
                if (c=='.') printf(",");
                if (c=='/') printf(".");
                if (c==' ') printf(" ");
                if (c=='\n') printf("\n");
        }
        return 0;
}
