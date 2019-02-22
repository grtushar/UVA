/*
Author: Md Golam Rahman Tushar
*/

//{ Template

#include <bits/stdc++.h>

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
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a; a = b; b = tmp; }

//bool isVowel(char ch){ch=tolower(ch);if(ch=='a'  ch=='e'  ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

struct elephant {
    int weight, iq, index;
} elephants[1000 + 7];

bool compare(elephant e1, elephant e2) {
    if(e1.weight == e2.weight) return e1.iq > e2.iq;
    return e1.weight < e2.weight;
}

void printElephants(int n) {
    for(int i = 0; i < n; i++) {
        cout<<elephants[i].index<<" "<<elephants[i].weight<<" "<<elephants[i].iq<<endl;
    }
}

void printPath(int i, int *path) {
    if(path[i] != -1) printPath(path[i], path);
    printf("%d\n", elephants[i].index);
}

void init() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #else
    // online submission
    #endif
}

int main() {
    init();

    int idx = 0;

    while(scanf("%d %d", &elephants[idx].weight, &elephants[idx].iq) == 2) {
        elephants[idx].index = idx + 1;
        idx++;
    }
    sort(elephants, elephants + idx, compare);

    int dp[idx], path[idx], mx = 1, endAt = 0;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < idx; i++) {
        dp[i] = 1;
        path[i] = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(elephants[i].weight > elephants[j].weight
               && elephants[i].iq < elephants[j].iq
               && (dp[j] + 1) > dp[i]) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
               }
        }
//        for(int o = 0; o < idx; o++) cout<<dp[o]<<" ";
//        cout<<endl;

        if(dp[i] > mx) {
            mx = dp[i];
            endAt = i;
        }
    }

    printf("%d\n", mx);
    printPath(endAt, path);
    return 0;
}
