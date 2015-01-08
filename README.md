Encrypted, seekable, file streams for c++
=========================================

CryptoStream++ provides a set of wrappers around the Crypto++ API that can be
used to create encrypted file streams that can be used in place of standard std::fstream(s).

Algorithm support
-----------------

* All the AES candidate ciphers (AES, serpent, etc.).
* PBKDF2 for key derivation

Why?
----

From a programming standpoint, 
random file access over encrypted files seemed to me to be non-trivial.  
A set of easy to use seekable C++ file streams supporting seekable 
access seemed to be lacking; although APIs like Crypto++, Botan, etc.
exist, they require a bit of a learning curve to properly integrate.

Perhaps you might be interested in this too
-------------------------------------------

I developed these wrappers in concert with TeaSafe, an encrypted filesystem 
(in many ways similar to TrueCrypt). TeaSafe utilizes CryptoStream++ 
as the underlying cryptographic file API.

