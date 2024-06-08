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
