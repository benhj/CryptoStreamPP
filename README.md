Encrypted, seekable, file streams for c++
=========================================

CryptoStream++ provides a set of wrappers around the 
[Crypto++ API](http://www.cryptopp.com) that can be
used to create encrypted file streams in place of standard std::fstream(s).
Uses CTR mode. 

Note: there is nothing special about the file format. The user will need 
to take care of remembering the initialization values as well as the password.

Supports

* AES [Rijndael], Serpent, CAST-256, RC6, Twofish, MARS, Camellia, RC5, SHACAL2.
* PBKDF2 for key derivation

Developed in concert with [TeaSafe](https://github.com/benhj/teasafe), an encrypted filesystem.

See example.cpp

Building
--------

For example:

`clang++ -std=c++11 example.cpp -lcryptopp -o example`

Note: Requires libcrypto++ to be installed