def generateKeyMatrix(key):
	key.replace('j', 'i')
	
	print key
	
	present = [False]*26
	keymatrix = [ ['A' for i in range(5)] for i in range(5) ]
	
	ptr = 0
	
	for ch in key:
		if not present[ord(ch)-ord('A')]:
			keymatrix[ ptr/5 ][ ptr%5 ] = ch
			print ch
			present[ord(ch)-ord('A')] = True
			ptr += 1
	
	print keymatrix
	
	for i in range(26):
		if not(i==ord('j') or present[i]):
			keymatrix[ ptr/5 ][ ptr%5 ] = chr(i)
			ptr += 1

def playfairCipher(message, key):
	keymatrix = generateKeyMatrix(key)
	
	print keymatrix

skey = raw_input("Enter the key : ")
plaintext = raw_input("Enter the message : ")

ciphertext = playfairCipher(plaintext, skey)
