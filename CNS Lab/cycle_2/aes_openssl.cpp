#include<bits/stdc++.h>
#include<openssl/aes.h>
using namespace std;

int main()
{
	char key[256/8] = {'\0'};
	strcpy( key, "Shared Secret key" );
	AES_KEY ekey, dkey;
	AES_set_encrypt_key( (unsigned char*)key, 256, &ekey );
	AES_set_decrypt_key( (unsigned char*)key, 256, &dkey );

	unsigned char msg[16] = "Input to AES, ";
	unsigned char ciphertext[16];

	AES_encrypt( msg, ciphertext, &ekey );

	char str[1000] = "\nEncrypted text : \n";
	fwrite( str, sizeof(char), strlen(str)+1, stdout );
	fwrite( ciphertext, sizeof(char), sizeof(ciphertext), stdout );

	char dmsg[16];
	AES_decrypt( ciphertext, (unsigned char*)dmsg, &dkey );
	strcpy( str, "\n\nDecrypted text : \n" );
	fwrite( str, sizeof(char), strlen(str)+1, stdout );
	fwrite( dmsg, sizeof(char), strlen(dmsg), stdout );
	fwrite( "\n", sizeof(char), strlen("\n"), stdout );

	return 0;
}