#include<bits/stdc++.h>
using namespace std;

string clshift(string str, int pos=1)
{
	return str.substr(pos) + str.substr(0, pos);
}

string crshift(string str, int pos=1)
{
	return clshift(str, str.length()-pos);
}

int toInt(string);

string toBinary(int x, int len=8)
{
	int x1 = x;
	string str = "";
	for( int i=0;i<len;i++ )
	{
		if(x%2==1)
			str += '1';
		else
			str += '0';
		x /= 2;
	}
	if(x!=0)
		throw "Character not completely converted into binary";
	
	reverse(str.begin(), str.end());
	
	if(toInt(str)!=x1)
	{
		ostringstream errMsg;
		errMsg<<"Binary representation not consistent:\nOriginal Character : ";
		errMsg<<x1;
		errMsg<<"\nConverted from binary representation : ";
		errMsg<<toInt(str)<<endl;
		
		string errStr = errMsg.str();
		
		char *cerrMsg = new char[errStr.length()+5];
		strcpy(cerrMsg, errStr.c_str());
		
		return cerrMsg;
	}
	
	return str;
}

string toBinary(string str)
{
	string ans = "";
	
	for(int i=0;i<str.length();i++)
		ans += toBinary((unsigned char)str[i]);
	
	return ans;
}

int toInt(string binText)
{
	int p = 1;
	int ans = 0;
	for( int i=binText.length()-1;i>=0;i-- )
	{
		if(binText[i]=='1')
			ans+=p;
		p = p*2;
	}
	
	return ans;
}

string toText(string str)
{
	string ans = "";
	
	for( int i=0;i<str.length();i+=8 )
		ans += (unsigned char)toInt( str.substr(i, 8) );
	return ans;
}

string permutedChoice1( string key )
{
	string newKey = "";
	int permPos[] = {
						57, 49, 41, 33, 25, 17, 9, 
						1, 58, 50, 42, 34, 26, 18, 
						10, 2, 59, 51, 43, 35, 27, 
						19, 11, 3, 60, 52, 44, 36,
						63, 55, 47, 39, 31, 23, 15, 
						7, 62, 54, 46, 38, 30, 22, 
						14, 6, 61, 53, 45, 37, 29, 
						21, 13, 5, 28, 20, 12, 4
					};
	
	for( int i=0;i<56;i++ )
		newKey += key[ permPos[i]-1 ];
	
	return newKey;
}

string permutedChoice2( string key )
{
	string newKey = "";
	int permPos[] = {
						14, 17, 11, 24, 1, 5, 3, 28, 
						15, 6, 21, 10, 23, 19, 12, 4, 
						26, 8, 16, 7, 27, 20, 13, 2, 
						41, 52, 31, 37, 47, 55, 30, 40, 
						51, 45, 33, 48, 44, 49, 39, 56, 
						34, 53, 46, 42, 50, 36, 29, 32
					};
	
	for( int i=0;i<48;i++ )
		newKey += key[ permPos[i]-1 ];
	
	return newKey;
}

string expansionPermutation( string text )
{
	string ans = "";
	int permPos[] = {
						32, 1, 2, 3, 4, 5, 
						4, 5, 6, 7, 8, 9, 
						8, 9, 10, 11, 12, 13, 
						12, 13, 14, 15, 16, 17, 
						16, 17, 18, 19, 20, 21, 
						20, 21, 22, 23, 24, 25, 
						24, 25, 26, 27, 28, 29, 
						28, 29, 30, 31, 32, 1
					};
	
	for( int i=0;i<48;i++ )
		ans += text[ permPos[i]-1 ];
	return ans;
}

string stringXOR(string str1, string str2)
{
	for( int i=0;i<str1.length();i++ )
		str1[i] = (str1[i]+str2[i]-'0'-'0')%2 + '0';
	
	return str1;
}

string initialPermutation( string text )
{
	int permPos[] = {
						58, 50, 42, 34, 26, 18, 10, 2, 
						60, 52, 44, 36, 28, 20, 12, 4, 
						62, 54, 46, 38, 30, 22, 14, 6, 
						64, 56, 48, 40, 32, 24, 16, 8, 
						57, 49, 41, 33, 25, 17, 9, 1, 
						59, 51, 43, 35, 27, 19, 11, 3, 
						61, 53, 45, 37, 29, 21, 13, 5, 
						63, 55, 47, 39, 31, 23, 15, 7
					};
	
	string ans = "";
	for( int i=0;i<64;i++ )
		ans += text[ permPos[i]-1 ];
	return ans;
}

string inversePermutation( string text )
{
	int permPos[] = {
						40, 8, 48, 16, 56, 24, 64, 32, 
						39, 7, 47, 15, 55, 23, 63, 31, 
						38, 6, 46, 14, 54, 22, 62, 30, 
						37, 5, 45, 13, 53, 21, 61, 29, 
						36, 4, 44, 12, 52, 20, 60, 28, 
						35, 3, 43, 11, 51, 19, 59, 27, 
						34, 2, 42, 10, 50, 18, 58, 26, 
						33, 1, 41, 9, 49, 17, 57, 25, 
					};
	
	string ans = "";
	for( int i=0;i<64;i++ )
		ans += text[ permPos[i]-1 ];
	return ans;
}

string substitute(string text)
{
	int sbox[][64] = 	{
							{
								14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 
								0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 
								4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 
								15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
							},
							{
								15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 
								3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 
								0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 
								13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
							},
							{
								10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 
								13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 
								13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 
								1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
							},
							{
								7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 
								13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 
								10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 
								3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
							},
							{
								2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
								14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
								4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
								11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
							},
							{
								12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 
								10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
								9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
								4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
							},
							{
								4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 
								13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 
								1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
								6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
							},
							{
								13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 
								1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
								7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
								2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
							}
						};
	
	string ans = "";
	
	for( int i=0;i<text.length();i+=6 )
	{
		int x = toInt( text.substr(i, 1)+text.substr(i+5, 1) );
		int y = toInt( text.substr(i+1, 4) );
		
		int newVal = sbox[i/8][x*16+y];
		ans += toBinary(newVal, 4);
	}
	
	return ans;
}

string permute(string text)
{
	int permPos[] = {
						16, 7, 20, 21, 29, 12, 28, 17, 
						1, 15, 23, 26, 5, 18, 31, 10, 
						2, 8, 24, 14, 32, 27, 3, 9, 
						19, 13, 30, 6, 22, 11, 4, 25
					};
	
	string ans = "";
	for( int i=0;i<32;i++ )
		ans += text[ permPos[i]-1 ];
	
	return ans;
}

string des64bit( string plaintext, string key, bool decipher )
{
	plaintext = initialPermutation( plaintext );
	key = permutedChoice1(key);
	
	string lkey = key.substr(0, 28);
	string rkey = key.substr(28);
	string ltext = plaintext.substr(0, 32);
	string rtext = plaintext.substr(32);
	
	int shiftArray[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 0 };
	int totalRounds = 16;
	
	for( int i=0;i<totalRounds;i++ )
	{
		if(decipher)
		{
			lkey = crshift( lkey, shiftArray[totalRounds-i] );
			rkey = crshift( rkey, shiftArray[totalRounds-i] );
		}
		else
		{
			lkey = clshift( lkey, shiftArray[i] );
			rkey = clshift( rkey, shiftArray[i] );
		}
		
		string roundKey = permutedChoice2(lkey+rkey);
		
		string nrtext = expansionPermutation(rtext);
		nrtext = stringXOR(nrtext, roundKey);
		nrtext = substitute(nrtext);
		nrtext = permute(nrtext);
		nrtext = stringXOR(nrtext, ltext);
		
		ltext = rtext;
		rtext = nrtext;
	}
	
	return inversePermutation( rtext+ltext );
}

string des( string plaintext, string key, bool decipher=false )
{
	while(plaintext.length()%8!=0)
		plaintext += ' ';
	
	if(key.length()!=8)
	{
		cout<<"\nKeylength should be 8 chars\n";
		return "";
	}
	
	plaintext = toBinary(plaintext);
	cout<<"Binary plaintext = "<<plaintext<<endl;
	
	key = toBinary(key);
	cout<<"Binary key = "<<key<<endl;
	
	string ans = "";
	for( int i=0;i<plaintext.length();i+=64 )
		ans += des64bit( plaintext.substr(i, 64), key, decipher );
	
	cout<<"Binary ciphertext = "<<ans<<endl;
	ans = toText(ans);
	
	return ans;
}

int main()
{
	string plaintext, key;
	cout<<"Enter the key (8-char) : ";
	cin>>key;
	
	cout<<"Enter the plaintext : ";
	cin>>plaintext;
	
	cout<<"\nEnciphering...\n";
	string ciphertext;
	
	ciphertext = des( plaintext, key );
	cout<<"Ciphertext : "<<ciphertext<<endl;
	
	cout<<"\nDeciphering---\n";
	string decipheredtext = des( ciphertext, key, true );
	cout<<"Deciphered text : "<<decipheredtext<<endl;
	
	return 0;
}
