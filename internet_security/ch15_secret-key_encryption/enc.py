from Crypto.Cipher import AES
from Crypto.Util import Padding

key_hex_string = '00112233445566778899AABBCCDDEEFF'
iv_hex_string =  '000102030405060708090A0B0C0D0E0F'
key = bytes.fromhex(key_hex_string)
iv = bytes.fromhex(iv_hex_string)
data = b'The quick brown fox jumps over the lazy dog'
print("Length of data: {0:d}".format(len(data)))

# Encrypt the piece by piece
cipher = AES.new(key, AES.MODE_CBC, iv)
ciphertext = cipher.encrypt(data[0:32])
ciphertext += cipher.encrypt(Padding.pad(data[32:], 16))
print("Ciphertext: {0}".format(ciphertext.hex()))

# Encrypt the entire data
cipher = AES.new(key, AES.MODE_CBC, iv)
ciphertext = cipher.encrypt(Padding.pad(data, 16))
print("Ciphertext: {0}".format(ciphertext.hex()))

# Decrypt the ciphertext
cipher = AES.new(key, AES.MODE_CBC, iv)
plaintext = cipher.decrypt(ciphertext)
print("Plaintext: {0}".format(Padding.unpad(plaintext, 16)))
print("Plaintext: {0}".format(plaintext))

# CFB, OFB, and CTR doesn't need padding
cipher = AES.new(key, AES.MODE_CFB, iv)
ciphertext = cipher.encrypt(data)
print("Ciphertext: {0}".format(ciphertext.hex()))

cipher = AES.new(key, AES.MODE_OFB, iv)
ciphertext = cipher.encrypt(data)
print("Ciphertext: {0}".format(ciphertext.hex()))

cipher = AES.new(key, AES.MODE_CTR)
ciphertext = cipher.encrypt(data)
print("Ciphertext: {0}".format(ciphertext.hex()))

# Unauthenticated Encryption
print("Unauthenticated Encryption")
cipher = AES.new(key, AES.MODE_OFB, iv)
ciphertext = bytearray(cipher.encrypt(data))
## Change the 10th byte of the cypher text
ciphertext[10] = 0xE9
## Decrypt the edited ciphertext
cipher = AES.new(key, AES.MODE_OFB, iv)
plaintext = cipher.decrypt(ciphertext)
print("Plaintext: {0}".format(plaintext))
