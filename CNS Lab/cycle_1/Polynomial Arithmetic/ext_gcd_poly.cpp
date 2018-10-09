#include<bits/stdc++.h>
using namespace std;

string trim( string str )
{
	int firstOne = str.find('1');
	if(firstOne==string::npos)
		str = "0";
	else
		str = str.substr( firstOne, str.length() );
	
	return str;
}

string stringXOR( string str1, string str2 )
{
	if( str1.length() < str2.length() )
		swap(str1, str2);
	
	str2 = string( str1.length()-str2.length(), '0' ) + str2;
	
	for( int i=0;i<str1.length();i++ )
		str1[i] = ( (str1[i]+str2[i]-'0'-'0')%2 )+'0';
	
	return str1;
}

string add( string str1, string str2 )
{
	return trim( stringXOR( str1, str2 ) );
}

string subtract( string str1, string str2 )
{
	return add( str1, str2 );
}

string lshift( string str, int pos=1 )
{
	return str + string(pos, '0');
}

string rshift( string str, int pos=1 )
{
	if( pos >= str.length() )
		return "0";
	return str.substr( 0, str.length()-pos );
}

string multiply( string str1, string str2 )
{
	string ans = "0";
	
	for( int i=str2.length()-1;i>=0;i-- )
	{
		if( str2[i]=='1' )
			ans  = add(ans, str1);
		
		str1 = lshift( str1 );
	}
	
	return trim( ans );
}

string quotient( string b, string a )
{
	a = trim(a);
	b = trim(b);
	
	if( b.length() < a.length() )
		return "0";
	
	int exLen = b.length()-a.length();
	a = lshift( a, exLen );
	string ans = "";
	
	for( int i=0;i<=exLen;i++ )
	{
		if( b[i]=='1' )
		{
			b = stringXOR(b, a);
			ans += '1';
		}
		else
			ans += '0';
		
		a = rshift( a );
	}
	
	return trim( ans );
}

string mod( string a, string m )
{
	string q = quotient( a, m );
	return subtract( a, multiply( q, m ) );
}

string inverse( string a, string m )
{
	a = mod( a, m );
	string b = m;
	
	string xold = "1", x = "0", xnew;
	
	while( b!="0" && b!="1" )
	{
		string q = quotient(a, b), r = mod(a, b);
		
		xnew = subtract( xold, multiply(q, x) );
		xold = x;
		x = xnew;
		
		a = b;
		b = r;
	}
	
	if( b=="0" )
		return "GCD(a, b) not equal to one";
	
	x = mod(x, m);
	
	return x;
}

int main()
{
	string a, m;
	cout<<"Enter poly1 (a) in binary : ";
	cin>>a;
	cout<<"Enter poly2 (m) in binary : ";
	cin>>m;
	
	string ainv = inverse(a, m);
	
	cout<<"a inv (mod m) = "<<ainv<<endl;
	
	return 0;
}
