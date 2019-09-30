

/*

You have an array of length N. You have to find the maximum length subarray that comprises of only prime numbers.

Input format :

  First line: T denoting the number of test cases.

  For each test case :

    First line: Integer N denoting the size of the array
    Second line: N space-separated integers denoting the value of array elements

Output format :

  For each test case, print the length of the maximum length subarray. If no such subarray exists, then print -1.

Input Constraints :

  1 <= T <= 10
  1 <= N <= 10^4
  1 <= A[i] <= 10^7

Note :  The input and output is handled by the code itself. You are supposed to correct the function(s).

Sample Input : 

  1
  4
  6 2 3 4

Sample Output : 

  2

The solution to this problem is solved in

*/

#include<stdio.h>
int solve(int,int []);
int isprime(int);
int max(int,int);

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        int A[10005];
        for(int i=0;i<N;i++)
            scanf("%d",&A[i]);
        int ans=solve(N,A);
        printf("%d\n",ans);
    }
    return 0;
}

int solve(int N, int A[]) 
{
    //compute the answer
    int ans=0;
    int cnt=0;
    for(int i=0;i<N;i++) {
        if(isprime(A[i])==1) cnt++;
        else {
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    ans=max(ans,cnt);
    if(!ans)ans=-1;
    return ans;
}

int isprime(int x) 
{
    //check if a given number is prime or not
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}

int max(int a,int b)
{
    //find maximum value between the given inputs
    if(a>b)return a;
    return b;
}
