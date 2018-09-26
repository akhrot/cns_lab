from numpy import matrix
from numpy import linalg

def hillCipher(message, key, n, decipher, baseChar=ord('A'), alphaLen=26):
	if len(key) != n*n:
		raise Exception("Key length not equal to n(" + str(n) + ")")
	
	if alphaLen <= 0:
		raise Exception("Length of alphabet dictionary should be positive")
	
	if len(message)%n != 0:
		message += baseChar * (n - len(message))
	
	keynums = []
	for ch in key:
		keynums.append(ord(ch)-baseChar);
	
	keymatrix = []
	for i in range(n):
		keymatrix.append(keynums[i*n : i*n+n])
	
	keymatrix = matrix(keymatrix)
	
	if decipher:
		determinant = linalg.det(keymatrix).round()
		if determinant==0:
			raise Exception("Determinant is ZERO, change the key")
		if determinant%alphaLen==0:
			raise Exception("Determinant divisible by alphaLen, change the key")
		
		invdet = -1
		for i in range(alphaLen):
			if (determinant*i)%alphaLen == 1:
				invdet = i
				break
		
		if invdet==-1:
			raise Exception("Modulo inverse of determinant does not exist, change the key")
		
		keymatrix = ( ( ( keymatrix.getI()*determinant )*invdet ) ).round()
		keymatrix = keymatrix%alphaLen
		
		print "Deciphering\n"
	
	else:
		print "Enciphering\n"
	
	#print "Keymatrix = \n\n", keymatrix, "\n\n"
	
	result = ''
	for i in range(len(message)/n):
		left = matrix( [ [ord(a)-baseChar] for a in message[i*n : i*n+n] ] )
		right = ( (keymatrix*left) % alphaLen ).getA()
		for j in range(n):
			result += chr(int(right[j][0]+baseChar))
	
	return result;

key = raw_input("Enter the key : ")
n = input("Enter n : ")
message = raw_input("Enter the message : ")

ciphertext = hillCipher(message, key, n, False)
print "Ciphered text = ", ciphertext, "\n\n"

decipheredtext = hillCipher(ciphertext, key, n, True)
print "Deciphered text = ", decipheredtext, "\n\n"
