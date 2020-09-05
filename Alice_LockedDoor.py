import hashlib
hash=""
i=-1
while(hash[:4]!="0000"):
	i+=1
	text="Mallory Rules CryptoLand"+str(i)
	hash=hashlib.sha256(text.encode()).hexdigest()
print('Value of n: ',i, '\nHash value: ',hash)

	
"""
OUTPUT

Value of n:  74164 
Hash value:  0000611c6faf461fe5e32657fd14560036829133ac09b0275cd2c97dda38381d
"""
