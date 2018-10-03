#include<bits/stdc++.h>
using namespace std;

// Finds inverse of a (mod b)
int find_inv( int a, int m )
{
	int b = m;
	a = a%b;
	
	int xold = 1, x = 0, xnew;
	
	while( b>1 )
	{
		int q = (a/b), r = (a%b);
		
		xnew = xold - (q*x);
		xold = x;
		x = xnew;
		
		a = b;
		b = r;
	}
	
	x = x%m;
	
	if(x<0)
		x += m;
	
	return x;
}

int gcd(int x, int y)
{
	if( x==0 )
		return y;
	if( y==0 )
		return x;
	int r = x%y;
	while(r!=0)
	{
		x = y;
		y = r;
		r = x%y;
	}
	
	return y;
}

int findX(vector<int> p, vector<int> r)
{
	int n = p.size();
	
	for( int i=0;i<n;i++ )
		for( int j=i+1;j<n;j++ )
			if( gcd( p[i], p[j] ) != 1 )
				return -1;
	
	int prod = 1;
	for(int i=0;i<n;i++)
		prod *= p[i];
	
	int ans = 0;
	for( int i=0;i<n;i++ )
	{
		int pp = prod/p[i];
		ans += r[i] * find_inv(pp, p[i]) * pp;
	}
	
	return ans%prod;
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	
	vector<int> p(n), r(n);
	
	cout<<"Enter the coprime numbers and their residues (pi and ri) : \n";
	
	for( int i=0;i<n;i++ )
		cin>>p[i]>>r[i];
	
	cout<<"";
	
	int ans = findX(p, r);
	
	if( ans == -1 )
		cout<<"\nThe numbers given are not coprime\n";
	else
		cout<<"\nAnswer = "<<ans<<endl;
	
	return 0;
}
