from Crypto.Util import number

def hashFn( msg ):
	return msg

def find_coprime_k( p, start=2 ):
	for k in range( start, p-1 ):
		if number.GCD( k, p-1 )==1:
			return k
	return -1

def getSign( m, g, p, x ):
	k = find_coprime_k(p)
	kinv = number.inverse(k, p-1)

	r = pow(g, k, p)
	ks = ( hashFn(m) - x*r )%(p-1)
	s = (ks * kinv)%(p-1)

	return (r, s)

def main():
	p, g = map(int, ( raw_input( "Enter the prime number(p) and the generator(g) : " ).split() ) );
	x = int( input( "Enter the secret key(x) : " ) )

	y = pow(g, x, p)
	print "\nPublic key(y) :", y 

	m = int( input( "\nEnter the input to be signed by sender : " ) )

	(r, s) = getSign( m, g, p, x )

	print "\nSignature generated : (", r, ",", s, ")"

	lhs = pow(g, hashFn(m), p)
	rhs = ( pow(y, r, p)*pow(r, s, p) )%p

	print "\nLHS =", lhs
	print "RHS =", rhs

	if lhs==rhs:
		print "\n\nSignature VALID"
	else:
		print "\n\nSignature INVALID"

main()