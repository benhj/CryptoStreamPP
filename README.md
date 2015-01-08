Seekable encrypted file streams for c++
=======================================

CryptoStream++ provides a set of wrappers around the Crypto++ api  
for creating easy to use encrypted file streams 
that can be used in place of standard std::fstream(s).

Why?

From a programming standpoint, 
random file access over encrypted files seemed to me to be non-trivial.  
A set of easy to use
seekable C++ file streams supporting seekable access seemed to be lacking.
I therefore developed these wrappers to try and fill this void.

A real world application
------------------------
I developed these wrappers in concert with TeaSafe, an encrypted filesystem 
(in many ways similar to TrueCrypt). TeaSafe utilizes CryptoStream++ 
as the underlying cryptographic file API.

