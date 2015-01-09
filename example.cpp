#include "cryptostreampp/CryptoStreamPP.hpp"
#include "cryptostreampp/RandomNumberGenerator.hpp"

#include <iosfwd>
#include <iostream>
#include <vector>

int main()
{

    // create a file to write to
    using namespace cryptostreampp;

    EncryptionProperties props;

    // Generate 4 x 64bit numbers to make a 256 bit random IV
    props.iv = crypto_random();
    props.iv2 = crypto_random();
    props.iv3 = crypto_random();
    props.iv4 = crypto_random();
    props.cipher = 3; // Serpent cipher

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
    std::vector<char> buffer;
    buffer.resize(14); 
    stream.read(&buffer.front(), 13);
    buffer[14] = '\0';

    // Should print out "Hello, world!"
    std::cout<<&buffer.front()<<std::endl;

    // move the stream to position 7 and overwrite world with universe
    stream.seekp(7);
    stream.write("Universe!", 9);
    stream.flush();

    // seek to beginning and read in whole thing
    stream.seekg(0);

    // now seek to beginning and read in what we wrote
    std::vector<char>().swap(buffer);
    buffer.resize(17); // Room for "Hello, Universe!", i.e. 16 chars
    stream.read(&buffer.front(), 16);
    buffer[16] = '\0';

    // Should print out "Hello, Universe!""
    std::cout<<&buffer.front()<<std::endl;

}