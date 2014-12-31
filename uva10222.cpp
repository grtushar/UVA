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

bool ret(char c) {
    switch(c){
        case ']': printf("p"); break;
        case '[': printf("o"); break;
        case 'p':
        case 'P': printf("i"); break;
        case 'o':
        case 'O': printf("u"); break;
        case 'i':
        case 'I': printf("y"); break;
        case 'u':
        case 'U': printf("t"); break;
        case 'y':
        case 'Y': printf("r"); break;
        case 't':
        case 'T': printf("e"); break;
        case 'r':
        case 'R': printf("w"); break;
        case 'e':
        case 'E': printf("q"); break;
        case 'w':
        case 'W': printf("w"); break;
        case 'q':
        case 'Q': printf("q"); break;
        case '"': printf("l");break;
        case ';':
        case ':': printf("k"); break;
        case 'l':
        case 'L': printf("j"); break;
        case 'k':
        case 'K': printf("h");break;
        case 'j':
        case 'J': printf("g");break;
        case 'h':
        case 'H': printf("f");break;
        case 'g':
        case 'G': printf("d");break;
        case 'f':
        case 'F': printf("s");break;
        case 'd':
        case 'D': printf("a");break;
        case '/':
        case '?': printf(",");break;
        case '.':
        case '>': printf("m");break;
        case ',':
        case '<': printf("n");break;
        case 'm':
        case 'M': printf("b");break;
        case 'n':
        case 'N': printf("v");break;
        case 'b':
        case 'B': printf("c");break;
        case 'v':
        case 'V': printf("x");break;
        case 'c':
        case 'C': printf("z");break;
        case 'x':
        case 'X': printf("x");break;
        case 'z':
        case 'Z': printf("z");break;
        case '\'':printf("l");break;
        case '=':printf("0");break;
        case '-': printf("9");break;
        case '0': printf("8");break;
        case '9': printf("7");break;
        case '8': printf("6");break;
        case '7': printf("5");break;
        case '6': printf("4");break;
        case '5': printf("3");break;
        case '4': printf("2");break;
        case '3': printf("1");break;
        case '2': printf("`");break;
        default:printf("%c",c);
    }
}


int main() {
    //freopen("input.txt","r",stdin);
    string str;
    while(getline(cin, str)) {
        int i, l = str.size();
        for(i=0;i<l;i++) ret(str[i]);
        cout<<endl;
    }
    return 0;
}
