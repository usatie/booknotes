# Chapter 15. Secret-Key Encryption
## 15.1 Introduction
## 15.2 Substitution Cipher
### 15.2.1 Monoalphabetic Substitution Cipher
```
tr "[:upper:]" "[:lower:]" < article.txt > lowercase
tr -cd 'a-z\n[:space:]' < lowercase > plaintext
cat <<EOF > keygen.py
#!/usr/bin/python3

import random
s = "abcdefghijklmnopqrstuvwxyz"
list = random.sample(s, len(s))
print(''.join(list))
EOF

# Generate Key
CEASAR_KEY=`python3 keygen.py`
# Encrypt
tr 'a-z' "$CEASAR_KEY" < plaintext > ciphertext
# Decrypt
tr "$CEASAR_KEY" 'a-z' < ciphertext > plaintext_new
```
### 15.2.2 Breaking Monoalphabetic Substitution Cipher
- Frequency analysis is useful
- frequency of letters, bigrams, trigrams
- `freq.py`
```
python3 freq.py
watch -n 1 cat result
tr yslogi THEAND < ciphertext.txt > result
tr yslogidtqnfbzmxkvujcarp THEANDIGOVFCWUSLBYRMPXK < ciphertext.txt > result
```
### 15.2.3 Polyalphabetic Substitution Cipher
- python3 poly_sub_cipher.py
### 15.2.4 The Enigma Machine
- The wiring of the entire machine is decided by three elements:
1. The position of the rootors
2. The internal wiring of each rotor
3. The wiring on the plugboard
- Secrets:
1. The initial positions of the rotors
2. The wiring on the plugboard
## 15.3 DES and AES Encryption Algorithms
### 15.3.1 DES: Data Encryption Standard
### 15.3.2 AES: Advanced Encryption Standard
- publicly defined
- symmetric block cipher
- adaptable to multiple key lengths
- executable in hardware and software
- freely available
## 15.4 Encryption Modes
### 15.4.1 Encryption Modes
### 15.4.2 Electronic Codebook (ECB) Mode
- The naive and unsafe method
```
openssl enc -aes-128-ecb -e -in plain.txt -out cipher.txt -K 00112233445566778899AABBCCDDEEFF
openssl enc -aes-128-ecb -d -in cipher.txt -out plain2.txt -K 00112233445566778899AABBCCDDEEFF
```
### 15.4.3 Cipher Block Chaining (CBC) Mode
- Each block of plaintext is XORed with the previous ciphertext block
- Initialization vector (IV) 
- We can decrypt each block in parallel,
- But we cannot encrypt in parallel
- encryption : encrypt(XOR(prevcipher, plain))
- decryption : XOR(prevcipher, decrypt(cipher))
```
$ openssl enc -aes-128-cbc -e -in plain.txt -out cipher1.txt \
   -K  00112233445566778899AABBCCDDEEFF \
   -iv 000102030405060708090a0b0c0d0e0f
$ openssl enc -aes-128-cbc -e -in plain.txt -out cipher2.txt \
   -K  00112233445566778899AABBCCDDEEFF \
   -iv 000102030405060708090a0b0c0d0e0e
$ xxd -p cipher1.txt
$ xxd -p cipher2.txt

# xxd is a 2-way (hex2bin and bin2hex) tool
$ xxd -p article.txt | xxd -p -r
```
### 15.4.4 Cipher Feedback (CFB) Mode
- Encryption and decryption use the same encryption direction of the block cipher
- encryption : XOR(encrypt(prevcipher), plain)
- decryption : XOR(encrypt(prevcipher), cipher)
- CFB mode turned a block cipher into a stream cipher: We can encrypt the plaintext bit by bit!
- With CBC, the size of ciphertext is a multiple of 16 bytes
- With CFB, the size of ciphertext is exactly the same size as that of the plaintext
- We can decrypt each block in parallel,
- But we cannot encrypt in parallel
```
openssl enc -aes-128-cbc -e -in plain.txt -out cipher1.txt \
   -K  00112233445566778899AABBCCDDEEFF \
   -iv 000102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cfb -e -in plain.txt -out cipher2.txt \
   -K  00112233445566778899AABBCCDDEEFF \
   -iv 000102030405060708090a0b0c0d0e0f
wc -c plain.txt cipher1.txt cipher2.txt
```
