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
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

int cnt[1000000+7], fst[1000000+7], n;
struct info {
    int val, idx;
}in[100000+7];

bool cmp(info a, info b) {
    if(a.val == b.val) return a.idx<b.idx;
    return a.val<b.val;
}

int BS(int x) {
    int l = 0, h = n;
    int mid = (l+h)/2;
    while(l<h) {
        if(in[mid].val>x) h = mid-1;
        else if(in[mid].val<x) l = mid+1;
        else break;
        mid = (l+h)/2;
    }

    while(in[mid].val == x) mid--;
    return mid;
}

int main() {
    //freopen("input.txt","r",stdin);
    int i, m, u, v, x;
    while(scanf("%d %d",&n,&m)!=EOF) {
        memset(cnt, 0, sizeof(cnt));
        for(i=0;i<n;i++) {
            scanf("%d",&x);
            in[i].val = x;
            in[i].idx = i+1;
            //if(cnt[x] == 0) fst[x] = i;
            cnt[x]++;
        }

        sort(in, in+n, cmp);
        //for(i=0;i<n;i++) cout<<in[i].val<<" ::: "<<in[i].idx<<endl;

        for(i=0;i<m;i++) {
            scanf("%d %d",&u, &v);
            if(u>cnt[v]) puts("0");
            else {
                int id = BS(v); //cout<<" id :: "<<id<<endl;
                printf("%d\n",in[id+u].idx);
            }
        }
    }
    return 0;
}
