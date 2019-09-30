
/*  
You are given an array of N distinct elements numbered from 1 to N. 
You need to draw some elements from this array such that no two consecutive elements are drawn.

Write a program to find the total number of distinct ways of drawing the elements from this array.

Since the number can be huge hence print answer modulo 10^9 + 7.

Input format : 

  First line: T (Number of test cases)
  Next T lines: N

Output format :

  For each test case, print the total number of distinct ways of drawing the elements from the array modulo 10^9 + 7.

Constraints :

  1 <= T <= 10^3
  1 <= N <= 10^9

Sample Input : 
  2
  1 
  4

Sample Output : 
  1
  7

Below is the solution for this problem statement in C++

*/


#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define TR(...)
#endif

typedef long long                LL;
typedef vector < int >           VI;
typedef pair < int,int >         II;
typedef vector < II >            VII;

#define EPS                      1e-12
#define N                        200100
#define PB                       push_back
#define MP                       make_pair
#define F                        first 
#define S                        second
#define ALL(v)                   v.begin(),v.end()
#define SZ(a)                    (int)a.size()
#define FILL(a,b)                memset(a,b,sizeof(a))
#define SI(n)                    scanf("%d",&n)
#define SLL(n)                   scanf("%lld",&n)
#define PLLN(n)                  printf("%lld\n",n)
#define PIN(n)                   printf("%d\n",n)
#define REP(i,j,n)               for(LL i=j;i<n;i++)
#define PER(i,j,n)               for(LL i=n-1;i>=j;i--)
#define endl                     '\n'
#define fast_io                  ios_base::sync_with_stdio(false);cin.tie(NULL)

#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
freopen(name".out", "w", stdout);

const long long MOD = 1000000007;
LL powmod(LL a,LL b) { if(b==0)return 1; LL x=powmod(a,b/2); LL y=(x*x)%MOD; if(b%2) return (a*y)%MOD; return y%MOD; }


#define MAX_SIZE 3

int size = MAX_SIZE;

inline int mult(int a , int b) {
  LL x = a;
  x *= LL(b);
  if(x >= MOD) x %= MOD;
  return x;
}

inline int add(int a , int b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}


struct Matrix{
  long long X[MAX_SIZE][MAX_SIZE];

  Matrix(){}

  inline void init(){
    memset(X,0,sizeof(X));
    for(int i = 0;i < size;++i) X[i][i] = 1;
  }

  inline void set(vector <vector <int> > v) {
    for(int i = 0 ; i < size ; i ++) 
      for(int j = 0 ; j < size ; j ++)
        X[i][j] = v[i][j];
  }

  inline Matrix operator *(const Matrix &y) const {
    Matrix m;
    memset(m.X,0,sizeof(m.X));
    for(int i = 0;i < size;++i)
      for(int j = 0;j < size;++j)
        for(int k = 0;k < size;++k)
          m.X[i][k] = add(m.X[i][k] , mult(X[i][j] , y.X[j][k]));
    return m;  
  }

  inline Matrix operator +(const Matrix &y) const {
    Matrix m;
    for(int i = 0;i < size;++i)
      for(int j = 0;j < size;++j)
        m.X[i][j] = add(X[i][j] , y.X[i][j]);
    return m;  
  }
}aux;

inline Matrix pow(Matrix M0, LL n){
  Matrix ret;
  ret.init();
  while(n) {
    if(n & 1LL) ret = ret * M0;
    M0 = M0 * M0;
    n >>= 1LL;
  }
  return ret;
}



int main() {
  int t; cin >> t;
  while(t --) {
    int n; cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n == 2) cout << 2 << endl;
    else {
      Matrix M;
      REP(i,0,3) REP(j,0,3) M.X[i][j] = 0;
      M.X[0][0] = M.X[0][1] = M.X[0][2] = M.X[1][0] = M.X[2][2] = 1;
      M = pow(M , n-2);
      Matrix res;
      REP(i,0,3) REP(j,0,3) res.X[i][j] = 0;
      res.X[0][0] = 2;
      res.X[0][1] = res.X[1][0] = res.X[2][0] = res.X[2][1] = res.X[0][2] = 1;
      res = M * res;
      int ans = res.X[0][0];
      cout << ans << endl;
    }
  }
  return 0;
}
