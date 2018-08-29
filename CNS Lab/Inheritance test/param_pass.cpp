#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	void disp()
	{
		cout<<"Disp A called\n";
	}
};

class B : public A
{
public:
	void disp()
	{
		cout<<"Disp B called\n";
	}
};

void decideDisp( A &obj )
{
	obj.disp();
}

int main()
{
	B obj;
	
	cout<<"Passing a class B object as a type of class A's reference\n";
	
	decideDisp( obj );
	
	return 0;
}
