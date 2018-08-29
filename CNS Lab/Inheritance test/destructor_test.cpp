#include<bits/stdc++.h>

#include<gmp.h>
#include<assert.h>
using namespace std;

struct my_mpz_t : struct mpz_t
{
public:
	int extra_var;
};

int main()
{
	string a_str, b_str;
	my_mpz_t a, b;
	
	cout<<"Enter the numbers a and b : ";
	cin>>a_str>>b_str;
	
	mpz_init( (mpz_t)a );
	mpz_init( (mpz_t)b );
	mpz_set_ui( (mpz_t)a, 0 );
	mpz_set_ui( (mpz_t)b, 0 );
	
	assert( mpz_set_str( (mpz_t)a, a_str.c_str(), 10 )==0 );
	assert( mpz_set_str( (mpz_t)b, b_str.c_str(), 10 )==0 );
	
	cout<<"a = "<<(mpz_t)a<<endl;
	cout<<"b = "<<(mpz_t)b<<endl;
	
	mpz_clear((mpz_t)a);
	mpz_clear((mpz_t)b);
}
