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
        string str[107];
        int i, j, k, n;

        while(scanf("%d",&n)==1)
        {
                int mx=0;
                for(i=0;i<n;i++) {
                        cin>>str[i];
                        if(mx<str[i].size()) mx = str[i].size();
                 }
                sort(str,str+n);
                int col = 62/(mx+2);
                int row = ceil(((double)n/(double)col));

                //cout<<row<<"      "<<col<<endl;
                cout<<"------------------------------------------------------------"<<endl;
                for(i=0;i<row;i++)
                {
                        for(j=i;j<n;j+=row)
                        {
                                cout<<str[j];
                                if(j+row<n) for(k=str[j].size();k<=mx+1;k++) cout<<" ";
                        }
                        cout<<endl;
                }
        }
        return 0;
}

