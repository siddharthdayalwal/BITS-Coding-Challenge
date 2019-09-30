 
/*
You are given an array A of N integers and Q tasks and in each task, there are two indices l and r (0-based indexing).
For each task, you have to find the greatest common divisor of two numbers present at index l and r and 
print the cumulative sum of GCDs of the Q tasks.

Note: You have to debug the code that is provided.

Input format : 

  First line: Two space-separated integers N and Q
  Second line: N space-separated integers
  Next Q lines: Two space-separated integers l and r

Output format : 

  Print a single integer that is the sum of GCDs of all the Q tasks.

Constraints :

  1 <= N , Q <= 10^5
  10^-9 <= A[i] <= 10^9
  0 <= l , r <= N-1
  l <= r

Sample Input : 

  3 2
  2 4 7
  0 2
  1 2

Sample output : 

  2

Solution to this problem is mentioned down in C++


*/


#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b%a==0)
	{
		return a;
	}
	else
	{
		return gcd(b%a,a);
	}
}
int main()
{
	int n,q;
	cin>>n>>q;;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ans+=(gcd(max(a[l],-a[l]),max(a[r],-a[r])));
	}
	cout<<ans<<endl;
return 0;	
} 



 

