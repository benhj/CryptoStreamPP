Encrypted, seekable, file streams for c++
=========================================

CryptoStream++ provides a set of wrappers around the 
[Crypto++ API](http://www.cryptopp.com) that can be
used to create encrypted file streams in place of standard std::fstream(s).
Uses CTR mode. 

Note: there is nothing special about the file format. The user will need 
to take care of remembering the initialization values as well as the password.

Supports all of the block ciphers currently supported by Crypto++:

* AES and AES candidates: AES (Rijndael), RC6, MARS, Twofish, Serpent, CAST-256
* Other block ciphers: IDEA, Triple-DES (DES-EDE2 and DES-EDE3), Camellia, SEED, RC5, Blowfish, TEA, XTEA,
Skipjack, SHACAL-2

Uses Crypto++'s implementation of PBKDF2 for key derivation (a million rounds).

Developed in concert with [KnoxCrypt](https://github.com/benhj/knoxcrypt), an encrypted filesystem.

See example.cpp

Building
--------

For example:

`clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib example.cpp -lcryptopp -o example`

Note: Requires libcrypto++ to be installed
