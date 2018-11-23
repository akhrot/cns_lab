#include<bits/stdc++.h>
#include<openssl/rsa.h>
using namespace std;

int main()
{
	cout<<"Here 1\n";
	RSA *keypair = NULL;
	keypair = RSA_new();
	BIGNUM *e = NULL;
	BN_dec2bn( &e, "3" );

	cout<<"Here 2\n";

	if( RSA_generate_key_ex( keypair, 256*8, e, NULL )==0 )
	{
		cout<<"RSA key generation failed\n";
		return -1;
	}

	cout<<"Here 2\n";

	int len = RSA_size(keypair);

	char msg[] = "Text to be encrypted using RSA";
	unsigned char ciphertext[len];
	char dmsg[len];

	RSA_private_encrypt( strlen(msg), (unsigned char*)msg, ciphertext, keypair, RSA_PKCS1_PADDING );
	char str[1000] = "\n\nEncrypted text : \n";
	fwrite( str, sizeof(char), strlen(str)+1, stdout );
	fwrite( ciphertext, sizeof(*ciphertext), len, stdout );

	int newlen = RSA_public_decrypt( sizeof(ciphertext), ciphertext, (unsigned char*)dmsg, keypair, RSA_PKCS1_PADDING );
	dmsg[newlen] = '\0';

	strcpy( str, "\n\nDecrypted text : \n" );
	fwrite( str, sizeof(char), strlen(str)+1, stdout );
	fwrite( dmsg, sizeof(char), newlen, stdout );
	fwrite( "\n", sizeof(char), 1, stdout );

	return 0;
}