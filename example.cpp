#include "cryptostreampp/Algorithms.hpp"
#include "cryptostreampp/CryptoStreamPP.hpp"
#include "cryptostreampp/RandomNumberGenerator.hpp"

#include "cryptopp/aes.h"
#include "cryptopp/camellia.h"
#include "cryptopp/mars.h"
#include "cryptopp/rc5.h"
#include "cryptopp/rc6.h"
#include "cryptopp/serpent.h"
#include "cryptopp/shacal2.h"
#include "cryptopp/twofish.h"
#include "cryptopp/cast.h"
#include "cryptopp/ccm.h"

#include <iosfwd>
#include <iostream>

int main()
{

    using namespace cryptostreampp;

    // Encryption properties store iv and password information
    EncryptionProperties props;

    // Generate a 256 bit random IV from 4 separate 64 bit numbers
    props.iv = crypto_random();
    props.iv2 = crypto_random();
    props.iv3 = crypto_random();
    props.iv4 = crypto_random();

    // What cipher function do we require?
    props.cipher = Algorithm::Serpent;

    // the password used for encryption / decryption
    props.password = std::string("password");

    /*==========  The main cryptostreampp usage  ==========*/
    
    // Create a stream in output mode to create a brand new file called test.txt
    CryptoStreamPP stream("test.txt", props, std::ios::out | std::ios::binary | std::ios::trunc);

    // ------------------------------------------------------
    // NOTE:
    // After creating the stream, there will be a short pause
    // as the key stream is initialized. This accounts for
    // one million iterations of PBKDF2
    // ------------------------------------------------------

    // write to the stream as you would a normal fstream. Normally
    // you would write a buffer of char data. In this example,
    // we write a string which is basically the same thing.
    // Stream operator support to be properly added in future.
    stream.write("Hello, world!", 13);

    // make sure stream is flushed before closing it
    stream.flush();
    stream.close();

    // Re-open in read / write mode. 
    stream.open("test.txt", std::ios::in | std::ios::out | std::ios::binary);

    // Read in a buffer of data
    {
        char buffer[14];
        stream.read(buffer, 13);
        buffer[13] = '\0';

        // Should print out "Hello, world!"
        std::cout<<buffer<<std::endl;
    }

    // move the stream to position 7 and overwrite world with universe
    stream.seekp(7);
    stream.write("Universe!", 9);

    // test stream output; how to add >> support?.
    //stream << "What!";

    stream.flush();

    // now seek to beginning and read in what we wrote
    {
        stream.seekg(0);
        char buffer[17];
        stream.read(buffer, 16);
        buffer[16] = '\0';

        // Should print out "Hello, Universe!""
        std::cout<<buffer<<std::endl;
    }

    stream.close();
    return 0;

}