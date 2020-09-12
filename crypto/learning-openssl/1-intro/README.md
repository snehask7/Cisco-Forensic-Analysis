# Table of Contents
-   [Introduction to Openssl](#introduction-to-openssl)
    -   [Different cli options](#different-cli-options)
        -   [openssl version -a](#openssl-version--a)
        -   [openssl help](#openssl-help)
        -   [openssl rsa -help](#openssl-rsa--help)
        -   [openssl x509 -help](#openssl-x509--help)
        -   [openssl aes128](#openssl-aes128)
        -   [openssl dgst -help](#openssl-dgst--help)
        -   [openssl dgst file](#openssl-dgst-file)
        -   [openssl sha512 file](#openssl-sha512-file)
        -   [openssl sha512 -out file.hash
            file](#openssl-sha512--out-filehash-file)
        -   [openssl rand 100](#openssl-rand-100)
        -   [openssl rand -base64 100](#openssl-rand--base64--100)
        -   [openssl genrsa -help](#openssl-genrsa--help)
        -   [openssl gendsa -help](#openssl-gendsa--help)

#	Introduction to Openssl
This section provides an introduction to OpenSSL, a key software for performing cryptographic operations.

##	Different cli options

### openssl version -a

	    OpenSSL 1.1.1b  26 Feb 2019
	    built on: Wed Apr  3 10:50:23 2019 UTC
	    platform: debian-amd64
	    options:  bn(64,64) rc4(16x,int) des(int) blowfish(ptr)
	    compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -Wa,--noexecstack -g -O2 -fdebug-prefix-map=/build/openssl-uEA50R/openssl-1.1.1b=. -fstack-protector-strong -Wformat -Werror=format-security -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DAES_ASM -DVPAES_ASM -DBSAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPADLOCK_ASM -DPOLY1305_ASM -DNDEBUG -Wdate-time -D_FORTIFY_SOURCE=2
	    OPENSSLDIR: "/usr/lib/ssl"
	    ENGINESDIR: "/usr/lib/x86_64-linux-gnu/engines-1.1"
	    Seeding source: os-specific

### openssl help

	    Standard commands
	    asn1parse         ca                ciphers           cms               
	    crl               crl2pkcs7         dgst              dhparam           
	    dsa               dsaparam          ec                ecparam           
	    enc               engine            errstr            gendsa            
	    genpkey           genrsa            help              list              
	    nseq              ocsp              passwd            pkcs12            
	    pkcs7             pkcs8             pkey              pkeyparam         
	    pkeyutl           prime             rand              rehash            
	    req               rsa               rsautl            s_client          
	    s_server          s_time            sess_id           smime             
	    speed             spkac             srp               storeutl          
	    ts                verify            version           x509              

	    Message Digest commands (see the `dgst' command for more details)
	    blake2b512        blake2s256        gost              md4               
	    md5               rmd160            sha1              sha224            
	    sha256            sha3-224          sha3-256          sha3-384          
	    sha3-512          sha384            sha512            sha512-224        
	    sha512-256        shake128          shake256          sm3               

	    Cipher commands (see the `enc' command for more details)
	    aes-128-cbc       aes-128-ecb       aes-192-cbc       aes-192-ecb       
	    aes-256-cbc       aes-256-ecb       aria-128-cbc      aria-128-cfb      
	    aria-128-cfb1     aria-128-cfb8     aria-128-ctr      aria-128-ecb      
	    aria-128-ofb      aria-192-cbc      aria-192-cfb      aria-192-cfb1     
	    aria-192-cfb8     aria-192-ctr      aria-192-ecb      aria-192-ofb      
	    aria-256-cbc      aria-256-cfb      aria-256-cfb1     aria-256-cfb8     
	    aria-256-ctr      aria-256-ecb      aria-256-ofb      base64            
	    bf                bf-cbc            bf-cfb            bf-ecb            
	    bf-ofb            camellia-128-cbc  camellia-128-ecb  camellia-192-cbc  
	    camellia-192-ecb  camellia-256-cbc  camellia-256-ecb  cast              
	    cast-cbc          cast5-cbc         cast5-cfb         cast5-ecb         
	    cast5-ofb         des               des-cbc           des-cfb           
	    des-ecb           des-ede           des-ede-cbc       des-ede-cfb       
	    des-ede-ofb       des-ede3          des-ede3-cbc      des-ede3-cfb      
	    des-ede3-ofb      des-ofb           des3              desx              
	    rc2               rc2-40-cbc        rc2-64-cbc        rc2-cbc           
	    rc2-cfb           rc2-ecb           rc2-ofb           rc4               
	    rc4-40            seed              seed-cbc          seed-cfb          
	    seed-ecb          seed-ofb          sm4-cbc           sm4-cfb           
	    sm4-ctr           sm4-ecb           sm4-ofb

### openssl rsa -help

	    Usage: rsa [options]
	    Valid options are:
	     -help              Display this summary
	     -inform format     Input format, one of DER PEM
	     -outform format    Output format, one of DER PEM PVK
	     -in val            Input file
	     -out outfile       Output file
	     -pubin             Expect a public key in input file
	     -pubout            Output a public key
	     -passout val       Output file pass phrase source
	     -passin val        Input file pass phrase source
	     -RSAPublicKey_in   Input is an RSAPublicKey
	     -RSAPublicKey_out  Output is an RSAPublicKey
	     -noout             Don't print key out
	     -text              Print the key in text
	     -modulus           Print the RSA key modulus
	     -check             Verify key consistency
	     -*                 Any supported cipher
	     -pvk-strong        Enable 'Strong' PVK encoding level (default)
	     -pvk-weak          Enable 'Weak' PVK encoding level
	     -pvk-none          Don't enforce PVK encoding
	     -engine val        Use engine, possibly a hardware device

### openssl x509 -help

	    Usage: x509 [options]
	    Valid options are:
	     -help                 Display this summary
	     -inform format        Input format - default PEM (one of DER or PEM)
	     -in infile            Input file - default stdin
	     -outform format       Output format - default PEM (one of DER or PEM)
	     -out outfile          Output file - default stdout
	     -keyform PEM|DER      Private key format - default PEM
	     -passin val           Private key password/pass-phrase source
	     -serial               Print serial number value
	     -subject_hash         Print subject hash value
	      -issuer_hash          Print issuer hash value
	     -hash                 Synonym for -subject_hash
	     -subject              Print subject DN
	     -issuer               Print issuer DN
	     -email                Print email address(es)
	     -startdate            Set notBefore field
	     -enddate              Set notAfter field
	     -purpose              Print out certificate purposes
	     -dates                Both Before and After dates
	     -modulus              Print the RSA key modulus
	     -pubkey               Output the public key
	     -fingerprint          Print the certificate fingerprint
	     -alias                Output certificate alias
	     -noout                No output, just status
	     -nocert               No certificate output
	     -ocspid               Print OCSP hash values for the subject name and public key
	     -ocsp_uri             Print OCSP Responder URL(s)
	     -trustout             Output a trusted certificate
	     -clrtrust             Clear all trusted purposes
	     -clrext               Clear all certificate extensions
	     -addtrust val         Trust certificate for a given purpose
	     -addreject val        Reject certificate for a given purpose
	     -setalias val         Set certificate alias
	     -days int             How long till expiry of a signed certificate - def 30 days
	     -checkend intmax      Check whether the cert expires in the next arg seconds
	                           Exit 1 if so, 0 if not
	     -signkey infile       Self sign cert with arg
	     -x509toreq            Output a certification request object
	     -req                  Input is a certificate request, sign and output
	     -CA infile            Set the CA certificate, must be PEM format
	     -CAkey val            The CA key, must be PEM format; if not in CAfile
	     -CAcreateserial       Create serial number file if it does not exist
	     -CAserial val         Serial file
	     -set_serial val       Serial number to use
	     -text                 Print the certificate in text form
	     -ext val              Print various X509V3 extensions
	     -C                    Print out C code forms
	     -extfile infile       File with X509V3 extensions to add
	     -rand val             Load the file(s) into the random number generator
	     -writerand outfile    Write random data to the specified file
	     -extensions val       Section from config file to use
	     -nameopt val          Various certificate name options
	     -certopt val          Various certificate text options
	     -checkhost val        Check certificate matches host
	     -checkemail val       Check certificate matches email
	     -checkip val          Check certificate matches ipaddr
	     -CAform PEM|DER       CA format - default PEM
	     -CAkeyform format     CA key format - default PEM
	     -sigopt val           Signature parameter in n:v form
	     -force_pubkey infile  Force the Key to put inside certificate
	     -next_serial          Increment current certificate serial number
	     -clrreject            Clears all the prohibited or rejected uses of the certificate
	     -badsig               Corrupt last byte of certificate signature (for test)
	     -*                    Any supported digest
	     -subject_hash_old     Print old-style (MD5) issuer hash value
	     -issuer_hash_old      Print old-style (MD5) subject hash value
	     -engine val           Use engine, possibly a hardware device
	     -preserve_dates       preserve existing dates when signing

### openssl aes128

	    enter aes-128-cbc encryption password:
	    Verifying - enter aes-128-cbc encryption password:
	    *** WARNING : deprecated key derivation used.
	    Using -iter or -pbkdf2 would be better.
	    asdddddddfjjjjjjjjjjkaaaaaaaajjjjjjjj
	    Salted__Q�!R���G�A�i����0�����A�h���>	���u�I�����n��z�0"m}%                                                                                                                                               


### openssl dgst -help

	    Usage: dgst [options] [file...]
	      file... files to digest (default is stdin)
	     -help               Display this summary
	     -c                  Print the digest with separating colons
	     -r                  Print the digest in coreutils format
	     -out outfile        Output to filename rather than stdout
	     -passin val         Input file pass phrase source
	     -sign val           Sign digest using private key
	     -verify val         Verify a signature using public key
	     -prverify val       Verify a signature using private key
	     -signature infile   File with signature to verify
	     -keyform format     Key file format (PEM or ENGINE)
	     -hex                Print as hex dump
	     -binary             Print in binary form
	     -d                  Print debug info
	     -debug              Print debug info
	     -fips-fingerprint   Compute HMAC with the key used in OpenSSL-FIPS fingerprint
	     -hmac val           Create hashed MAC with key
	     -mac val            Create MAC (not necessarily HMAC)
	     -sigopt val         Signature parameter in n:v form
	     -macopt val         MAC algorithm parameters in n:v form or key
	     -*                  Any supported digest
	     -rand val           Load the file(s) into the random number generator
	     -writerand outfile  Write random data to the specified file
	     -engine val         Use engine e, possibly a hardware device
	     -engine_impl        Also use engine given by -engine for digest operations


### openssl dgst file

			SHA256(file)= 9d63c3b5b7623d1fa3dc7fd1547313b9546c6d0fbbb6773a420613b7a17995c8


### openssl sha512 file

		SHA512(file)= 62f1c73922ba448579d9229f932e747c23d53400a6fb826c6ea5f478247420c62b681cd636840e0ae8556bcde856a24c0123c501aa3967c42530e3be8cb6de75

### openssl sha512 -out file.hash file

	==> ls -al

	    total 16
	    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  4 09:13 .
	    drwxr-xr-x 3 cybersecurity cybersecurity 4096 Jun  2 15:07 ..
	    -rw-r--r-- 1 cybersecurity cybersecurity   15 Jun  2 15:09 file
	    -rw-r--r-- 1 cybersecurity cybersecurity  143 Jun  4 09:13 file.hash

	==> cat file.hash

		SHA512(file)= 62f1c73922ba448579d9229f932e747c23d53400a6fb826c6ea5f478247420c62b681cd636840e0ae8556bcde856a24c0123c501aa3967c42530e3be8cb6de75


### openssl rand 100

		�����yT�E.k���ѡ�哹��7�|��܀�W�_Y��~�֨�K	Q���e�;��@Ti�!�
                                                           &䕤�nt^|����
                                                                       c�A%

### openssl rand -base64  100

		gVsU+iVzEkYBgbmALqLV5a7Z9HlPWqVZABPt/fhvFLH6N3ZBM64wDxBCK9wc5Dwa
		9TOiSC+OVbBwzmwKiSv0uCyGd7lpzoxI7p7aX5UbrlG4Tc3gk8HWvPIH5ie6MJS7
		Q1896w==


### openssl genrsa -help

	    Usage: genrsa [options]
	    Valid options are:
	     -help               Display this summary
	     -3                  Use 3 for the E value
	     -F4                 Use F4 (0x10001) for the E value
	     -f4                 Use F4 (0x10001) for the E value
	     -out outfile        Output the key to specified file
	     -rand val           Load the file(s) into the random number generator
	     -writerand outfile  Write random data to the specified file
	     -passout val        Output file pass phrase source
	     -*                  Encrypt the output with any supported cipher
	     -engine val         Use engine, possibly a hardware device
	     -primes +int        Specify number of primes


### openssl gendsa -help

	    Usage: gendsa [args] dsaparam-file
	    Valid options are:
	     -help               Display this summary
	     -out outfile        Output the key to the specified file
	     -passout val        Output file pass phrase source
	     -rand val           Load the file(s) into the random number generator
	     -writerand outfile  Write random data to the specified file
	     -*                  Encrypt the output with any supported cipher
	     -engine val         Use engine, possibly a hardware device
