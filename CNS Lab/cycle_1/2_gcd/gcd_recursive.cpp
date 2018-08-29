#include<iostream>
#include<string>

#include<gmp.h>
#include<assert.h>
using namespace std;

void gcd( mpz_t &a, mpz_t &b, mpz_t &res )
{
	if( mpz_cmp_ui( a, 0 )==0 )
	{
		mpz_set( res, b );
		return;
	}
	
	mpz_t r;
	mpz_init( r );
	mpz_mod( r, b, a );
	
	gcd( r, a, res );
	
	mpz_clear( r );
}

int main()
{
	string a_str, b_str;
	mpz_t a, b, res;
	
	cout<<"Enter the numbers a and b : ";
	cin>>a_str>>b_str;
	
	mpz_init( a );
	mpz_init( b );
	mpz_init( res );
	mpz_set_ui( a, 0 );
	mpz_set_ui( b, 0 );
	
	assert( mpz_set_str( a, a_str.c_str(), 10 )==0 );
	assert( mpz_set_str( b, b_str.c_str(), 10 )==0 );
	
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	
	clock_t start_time = clock();
	
	gcd( a, b, res );
	
	clock_t end_time = clock();
	
	cout<<"\ngcd(a, b) = "<<res<<" Time taken = "<<(double)(end_time-start_time)/(CLOCKS_PER_SEC)*1000<<"ms\n";
	
	mpz_clear(a);
	mpz_clear(b);
	
	return 0;
}
