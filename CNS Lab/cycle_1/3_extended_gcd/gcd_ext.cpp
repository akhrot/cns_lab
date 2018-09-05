#include<iostream>
#include<string>

#include<gmp.h>
#include<assert.h>
using namespace std;

void gcdExt( mpz_t &a, mpz_t &b, mpz_t &res, mpz_t &x, mpz_t &y )
{
	if( mpz_cmp_ui( a, 0 )==0 )
	{
		mpz_set( res, b );
		mpz_set_ui( x, 0 );
		mpz_set_ui( y, 1 );
		
		return;
	}
	
	mpz_t r, x1, y1;
	mpz_init(r);
	mpz_init(x1);
	mpz_init(y1);
	
	mpz_mod( r, b, a );
	
	gcdExt( r, a, res, x1, y1 );
	
	mpz_t temp;
	mpz_init(temp);
	
	mpz_div( temp, b, a );
	mpz_mul( temp, temp, x1 );				// x = y1 - (b/a)*x1
	mpz_sub( x, y1, temp );
	
	mpz_set( y, x1 );						// y = x1
	
	return;
}

int main()
{
	string a_str, b_str;
	mpz_t a, b, res, x, y;
	
	cout<<"Enter the numbers a and b\n";
	cin>>a_str>>b_str;
	
	mpz_init(a);
	mpz_init(b);
	mpz_init(res);
	mpz_init(x);
	mpz_init(y);
	
	assert( mpz_set_str( a, a_str.c_str(), 10 )==0 );
	assert( mpz_set_str( b, b_str.c_str(), 10 )==0 );
	
//	cout<<"a = "<<a<<endl;
//	cout<<"b = "<<b<<endl;
	
	clock_t start_time = clock();
	
	gcdExt( a, b, res, x, y );
	
	clock_t end_time = clock();
	
	cout<<"\ngcd(a, b) = "<<res<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"Time taken = "<<(double)(end_time-start_time)/(CLOCKS_PER_SEC)*1000<<"ms\n";
	
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(res);
	mpz_clear(x);
	mpz_clear(y);
}
