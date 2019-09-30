
//  
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

//

 Dashboard
 Tests
 My library
 Settings
BITS EDU CAMPUS|
Tests
BITS - Coding Challenge !!Completed | Invite-only Test (Make public) | Preview Test 
CANDIDATESTest taken 107Review pending 102Invited 146ANALYTICSOverviewQuestions reportCandidates feedbackTEST DETAILSBasic detailsQuestionsTest settingsEmail templatesDeleteClone
Multiple Choice Questions+Add a section
1
What is the output of the following C code:

    #include<stdio.h>
    #define CUBE(x) (x*x*x)
    int main()
    {
        int a, b=4;
        a = ...
Operator C Hard
6
7/10
2
What is the output of the following C code snippet:

    int main()
    {
        extern int a;
        printf("%d\n", a);
        return 0;
    }

   ...
C Medium Keyword
4
7/10
+Add multiple-choice question|Choose from Library
Subjective Questions+Add a section
+Add subjective question
Programming Questions+Add a section
3
Number selection
Mathematics Basic Math Hard Modular arithmetic
100
10/10
4
Special box
Hard Algorithms
100
10/10
5
A problem on GCD
Math Basic Greatest common divisor Basic Math Easy Mathematics Math
20
7/10
6
Subarray of prime numbers<Debugging - C,C++,C++14,Java,Java8>
Arrays Debugging Easy Data Structures
20
7/10
+Add programming question|Choose from Library
Frontend Questions+Add a section
+Add frontend question
File Upload Questions+Add a section
+Add file upload question
SQL Questions
You currently do not have access to this assessment type.Learn More
Machine Learning Questions+Add a section
+Add machine-learning question
Diagram Questions
You currently do not have access to this assessment type.Learn More
Java Project Questions
You currently do not have access to this assessment type.Learn More
Total Score250
Problem Name
Number selection
Problem Statement

Difficulty level

Problem Editorial (Visible only after contest is moved to practice area)

Sample Input(.txt)View File
Sample Output(.txt)View File
Correct Answer View File
Sample Explanation

Allowed Languages
 Select all
 Bash  C  C++  C++14  Clojure  C#  D  Erlang  F#  Go  Groovy  Haskell  Java  Java 8  JavaScript(Rhino)  JavaScript(Node.js)  Julia  Kotlin  Lisp  Lisp (SBCL)  Lua  Objective-C  OCaml  Octave  Pascal  Perl  PHP  Python  Python 3  R(RScript)  Racket  Ruby  Rust  Scala  Swift  Swift-4.1  TypeScript  Visual Basic
Edit Code checker limits
Time Limit:
1.0
seconds
(Time limit is for each input file. Max 10 seconds)
+Show Advanced Code-checker Settings
Max. Marks
100.0
Input/Output Files
Input & Output Files are used to evaluate the code submissions. Set marks for each of the input/output file uploaded here. Read how code submissions are evaluated .
Input	Output	
input-1.txt	output-1.txt
input-2.txt	output-2.txt
input-3.txt	output-3.txt
input-4.txt	output-4.txt
input-5.txt	output-5.txt
input-6.txt	output-6.txt
input-7.txt	output-7.txt
input-8.txt	output-8.txt
input-9.txt	output-9.txt
input-10.txt	output-10.txt
+Add input file
+Add output file
Upload Multiple Test Cases
Please upload zip/tar files containing input files named as in00.txt|bin, in01.txt|bin etc and output files named as out00.txt|bin, out01.txt|bin etc.
Upload
Tags
Grammar-Verified×Modular arithmetic×Hard×Basic Math×Grammar-Verified×Mathematics×
 Show this problem in the test
 Lock submission to this problem
Code Snippets
Show all code Snippets 
Embed problem on your page
Embed problem on your custom page using this embeddable code
Upgrade your subscription plan to access this feature.Upgrade
Try Question 




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
