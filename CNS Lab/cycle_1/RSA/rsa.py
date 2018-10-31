import math

def gcdExt( a, m ):
	a = int(a%m)
	b = int(m)

	xold = 1
	x = 0
	xnew = -1
	while( b>1 ):
		q = a//b
		r = a%b

		xnew = xold - q*x
		xold = x
		x = xnew

		a = b
		b = r

	x = x%m

	return x

def find_coprime_e( totient, start = 2 ):
	for e in range(start, totient-1):
		if math.gcd(e, totient)==1:
			return e
	return -1

def main():
	p, q = map(int, ( input( "Enter the 2 prime numbers : " ).split() ) );

	n = p*q
	totient = (p-1)*(q-1)
	print("n = p*q =", n)
	print("totient(n) =", totient)

	e = find_coprime_e( totient )
	print("e =", e)

	d = gcdExt(e, totient)
	print("d =", d)

	msg = int( input("Enter the number to be encrypted between " + str(1) + " and " + str(totient-1) + " : ") )

	cipherText = pow( msg, e, n )
	decipheredText = pow(cipherText, d, n)

	print("Ciphertext :", cipherText)
	print( "Deciphered Text :", decipheredText )


main()