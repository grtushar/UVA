/*
Author: Md Golam Rahman Tushar
*/
//{ Template

#include <bits/stdc++.h>

using namespace std;
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
//}
//{ Utils
template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a; a = b; b = tmp; }

//bool isVowel(char ch){ch=tolower(ch);if(ch=='a'  ch=='e'  ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
//}
/*................Code Starts Here................*/

void init() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #else
    // online submission
    #endif
}

struct point {
    int x, y;
};

bool valid(int x, int y, int w, int s) {
    if(x > w || x < 1 || y > s || y < 1) return false;
    return true;
}

int main() {
    init();
    int n;
    scanf("%d", &n);

    while(n--) {
        int w, s;
        scanf("%d %d", &w, &s);
        bool obstacle[w + 7][s + 7];
        memset(obstacle, false, sizeof(obstacle));

        for(int i = 0; i < w; i++) {
            int x;
            scanf("%d", &x);
            string line;
            getline(cin, line);
            istringstream iss(line);
            int y;
            while(iss >> y) {
                obstacle[x][y] = true;
            }
        }

        queue<point>Q;
        point temp;
        int dp[w][s];
        memset(dp, 0, sizeof(dp));
        dp[w-1][s-1] = 1;

        temp.x = w;
        temp.y = s;
        Q.push(temp);

        while(!Q.empty()) {
            temp = Q.front();
            Q.pop();

            if(valid(temp.x - 1, temp.y, w, s) && !obstacle[temp.x - 1][temp.y]) {
                dp[temp.x - 2][temp.y - 1] += 1;
                point temp2;
                temp2.x = temp.x - 1;
                temp2.y = temp.y;
                Q.push(temp2);
            }
            if(valid(temp.x, temp.y - 1, w, s) && !obstacle[temp.x][temp.y - 1]) {
                dp[temp.x - 1][temp.y - 2] += 1;
                point temp2;
                temp2.x = temp.x;
                temp2.y = temp.y - 1;
                Q.push(temp2);
            }
        }

        printf("%d\n", dp[0][0]);
        if(n > 0) printf("\n");
    }

    return 0;
}
