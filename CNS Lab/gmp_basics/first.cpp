// Second comment to see how to commit to master branch
// Single comment change to check the working of github

#include<iostream>

#include<gmp.h>
#include<assert.h>
using namespace std;

int main()
{
	char input[100005];
	
	mpz_t n;
	int flag;
	
	cout<<"Enter a number: ";
	cin>>input;
	
	mpz_init( n );
	mpz_set_ui( n, 0 );
	
	flag = mpz_set_str( n, input, 10 );
	assert( flag==0 );
	cout<<"n = "<<n<<endl;
	
	mpz_add_ui( n, n, 1 );
	cout<<"n+1 = "<<n<<endl;
	
	mpz_mul( n, n, n );
	cout<<"(n+1)^2 = "<<n<<endl;
	
	mpz_clear(n);
	
	return 0;
}
