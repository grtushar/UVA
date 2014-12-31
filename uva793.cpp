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

int pre[777+77];

int find(int x)
{
        return (pre[x]==x?x:find(pre[x]));
}

int main ()
{
        int t, n, i, c1, c2, u, v; char c, line[77];
        scanf("%d\n",&t);

        while(t--)
        {
                scanf("%d\n\n",&n);
                for(i=0;i<n;i++) pre[i] = i;

                int scs=0, uscs=0;
                while(1)
                {
                        gets(line);
                        if(!strcmp(line,"")||feof(stdin)) break;
                        sscanf(line,"%c %d %d",&c, &c1, &c2);
                        c1--; c2--;

                        if(c=='c')
                        {
                                u = find(c1);
                                v = find(c2);
                                if(u!=v) pre[u] = v;
                        }
                        else
                        {
                                u = find(c1);
                                v = find(c2);
                                if(u!=v) uscs++;
                                else scs++;
                        }
                }

                printf("%d,%d\n",scs,uscs);
                if(t) printf("\n");
        }
        return 0;
}

