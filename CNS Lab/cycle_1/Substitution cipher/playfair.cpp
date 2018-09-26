#include<bits/stdc++.h>
using namespace std;

void dispMatrix( vector< vector<char> > &mat)
{
	cout<<"Size of keymatrix = "<<mat.size()<<", "<<mat[0].size()<<endl;
	for( int i=0;i<mat.size();i++ )
	{
		for( int j=0;j<mat[i].size();j++ )
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}

vector< vector<char> > getKeyMatrix(string key)
{
	vector< vector<char> > keymatrix( 5, vector<char>(5) );
	map<char, bool> present;
	for( char i='A'; i<='Z'; i++ )
		present[i] = false;
	
	int ptr = 0;
	for( int i=0;i<key.length();i++ )
		if( !present[key[i]] )
		{
			keymatrix[ptr/5][ptr%5] = key[i];
			ptr++;
			
			present[key[i]] = true;
		}
	
	for( char ch='A';ch<='Z';ch++ )
		if( ch!='J' && !present[ch] )
		{
			keymatrix[ptr/5][ptr%5] = ch;
			ptr++;
			
			present[ch] = true;
		}
	
	return keymatrix;
}

string convert(string charPair, vector< vector<char> > &keymatrix, bool decipher)
{
	int i1 = -1, i2 = -1, j1 = -1, j2 = -1;
	for( int i=0;i<5;i++ )
		for( int j=0;j<5;j++ )
		{
			if(keymatrix[i][j]==charPair[0])
			{
				i1 = i;
				j1 = j;
			}
			
			if(keymatrix[i][j]==charPair[1])
			{
				i2 = i;
				j2 = j;
			}
		}
	
	string str = "";
	
	if(i1==i2)
	{
		if(decipher)
		{
			str += keymatrix[i1][(j1-1+5)%5];
			str += keymatrix[i2][(j2-1+5)%5];
		}
		else
		{
			str += keymatrix[i1][(j1+1)%5];
			str += keymatrix[i2][(j2+1)%5];
		}
	}
	else if(j1==j2)
	{
		if(decipher)
		{
			str += keymatrix[(i1-1+5)%5][j1];
			str += keymatrix[(i2-1+5)%5][j2];
		}
		else
		{
			str += keymatrix[(i1+1)%5][j1];
			str += keymatrix[(i2+1)%5][j2];
		}
	}
	else
	{
		str += keymatrix[i1][j2];
		str += keymatrix[i2][j1];
	}
	
	return str;
}

string playfairCipher(string message, string key, bool decipher = false)
{
	vector< vector<char> > keymatrix = getKeyMatrix(key);
	
	cout<<"Generated key matrix : \n\n";
	dispMatrix(keymatrix);
	
	int ptr = 0;
	
	string ans = "";
	
	while(ptr < message.length())
	{
		if( ptr==message.length()-1 || message[ptr]==message[ptr+1] )
		{
			string input = "";
			input += message[ptr];
			input += 'X';
			ptr += 2;
			
			string output = convert(input, keymatrix, decipher);
			ans += output;
		}
		else
		{
			string input = "";
			input += message[ptr++];
			input += message[ptr++];
			
			string output = convert(input, keymatrix, decipher);
			ans += output;
		}
	}
	
	return ans;
}

int main()
{
	string key, message;
	cout<<"Enter the key : ";
	cin>>key;
	cout<<"Enter the message : ";
	cin>>message;
	
	transform( message.begin(), message.end(), message.begin(), ::toupper );
	transform( key.begin(), key.end(), key.begin(), ::toupper );
	replace( message.begin(), message.end(), 'J', 'I' );
	replace( key.begin(), key.end(), 'J', 'I' );
	
	cout<<"\nEnciphering...\n";
	string ciphertext = playfairCipher(message, key);
	cout<<"Ciphertext = "<<ciphertext<<endl;
	
	cout<<"\nDeciphering...\n";
	string decipheredtext = playfairCipher(ciphertext, key, true);
	cout<<"Deciphered text = "<<decipheredtext<<endl;
	
	return 0;
}
