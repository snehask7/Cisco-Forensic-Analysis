# Table of Contents
-   [Certificate](#certificate)
    -   [Create Key Pair](#create-key-pair)
    -   [Create CSR](#create-csr)
    -   [Options for CSR](#options-for-csr)
    -   [Self-sign certificate](#self-sign-certificate)
    -   [Extensions](#extensions)

#	Certificate

Certificate Signing Requests are formal requests asking a CA to sign a
certificate. The CSR is signed with the private key and internally the
CSR contains the details of the organization and the public key.

1. First you create a key pair.
2. Store the private key carefully
3. The public key must be given to the CA
4. Certificates also carry identity of the person / organization who owns the public - private key pair.
5. This identity must be verified, typically in an out-of-band way. For instance a domain is verified by running a domain query. User certificates must be identified by a personal identity card. And so on. Different CAs have different methods and requirements to verify identity. For web PKI and browser use of certificates, there are Baseline Requirements defined by the CA/Browser Forum.
6. Once the CA verifies the identity, they sign and issue a certificate
7. The certificate can also be self-signed but it's trustworthiness is dependent on the user.

Now we will go through the process.

##	Create Key Pair

Create a key pair and extract the public key into a separate file. Use
a password if you would like to.

==> openssl genrsa -out certkey.key 2048

    Generating RSA private key, 2048 bit long modulus (2 primes)
    ...+++++
    ....+++++
    e is 65537 (0x010001)

==> ls -al

    total 12
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  7 11:31 .
    drwxr-xr-x 5 cybersecurity cybersecurity 4096 Jun  7 11:26 ..
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  7 11:31 certkey.key

==> openssl rsa -pubout -out certpubkey.key -in certkey.key

    writing RSA key

==> ls -al

    total 16
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  7 11:32 .
    drwxr-xr-x 5 cybersecurity cybersecurity 4096 Jun  7 11:26 ..
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  7 11:31 certkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  7 11:32 certpubkey.key

##	Create CSR

==> openssl req -new -key certkey.key -out cert.csr

    You are about to be asked to enter information that will be incorporated
    into your certificate request.
    What you are about to enter is what is called a Distinguished Name or a DN.
    There are quite a few fields but you can leave some blank
    For some fields there will be a default value,
    If you enter '.', the field will be left blank.
    -----
    Country Name (2 letter code) [AU]:IN
    State or Province Name (full name) [Some-State]:Tamil Nadu
    Locality Name (eg, city) []:Chennai
    Organization Name (eg, company) [Internet Widgits Pty Ltd]:My Cool Company Ltd
    Organizational Unit Name (eg, section) []:Finance
    Common Name (e.g. server FQDN or YOUR name) []:www.coolcompany.example
    Email Address []:admin@coolcompany.example

    Please enter the following 'extra' attributes
    to be sent with your certificate request
    A challenge password []:
    An optional company name []:

==> ls -al

    total 20
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  7 11:38 .
    drwxr-xr-x 5 cybersecurity cybersecurity 4096 Jun  7 11:26 ..
    -rw-r--r-- 1 cybersecurity cybersecurity 1102 Jun  7 11:38 cert.csr
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  7 11:31 certkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  7 11:32 certpubkey.key


==> openssl req -in cert.csr -noout -text

    Certificate Request:
        Data:
            Version: 1 (0x0)
            Subject: C = IN, ST = Tamil Nadu, L = Chennai, O = My Cool Company Ltd, OU = Finance, CN = www.coolcompany.example, emailAddress = admin@coolcompany.example
            Subject Public Key Info:
                Public Key Algorithm: rsaEncryption
                    RSA Public-Key: (2048 bit)
                    Modulus:
                        00:df:c1:01:83:c4:6b:ae:bc:09:97:b7:08:05:3f:
                        8c:2f:46:aa:fb:49:ff:6a:17:87:a1:20:7b:5b:1b:
                        e5:3d:d8:20:38:01:e7:27:ce:91:0e:09:7a:ce:d1:
                        f1:a8:fa:95:bc:7a:e0:89:8b:c0:e0:93:be:5e:9f:
                        a4:95:17:6b:ce:48:4b:52:b1:69:58:e4:d6:70:ac:
                        0f:60:7c:5a:c9:f0:0f:b8:1f:d9:fc:7d:74:f9:29:
                        f3:a3:78:53:f8:f3:cb:83:47:be:d4:5e:ba:ab:d3:
                        20:e8:26:27:89:96:ac:0c:32:9a:5d:58:fa:34:89:
                        76:e5:2e:21:97:57:f8:14:79:30:b7:4d:21:ea:58:
                        24:fc:8a:90:0a:5c:da:f0:06:2c:a8:99:cd:1e:3e:
                        50:7d:1c:90:fc:0a:dd:c8:12:a5:d4:2d:02:32:7a:
                        aa:71:ce:92:7a:fe:88:72:be:31:bb:c0:3f:75:a3:
                        95:f3:79:d5:1e:7b:93:8a:7b:46:ba:39:b7:82:6b:
                        33:67:00:a9:67:68:63:a9:7a:c3:3c:4c:3e:3b:f5:
                        25:92:8d:bf:0c:92:24:9b:40:64:ed:5e:2e:5d:b8:
                        4e:cf:eb:6b:50:41:5b:f5:12:25:ea:f2:f4:70:d8:
                        87:a0:c2:e5:a6:38:90:08:52:18:cd:ce:ae:e4:11:
                        0d:f7
                    Exponent: 65537 (0x10001)
            Attributes:
                a0:00
        Signature Algorithm: sha256WithRSAEncryption
             8c:42:19:81:13:e3:38:1e:d6:fc:4d:37:6e:e5:43:7b:90:9f:
             03:83:55:49:6d:55:73:3d:f0:42:5d:0b:5e:92:fe:8f:43:bd:
             f6:d8:c7:34:4a:b5:43:c1:19:14:ae:c3:89:fb:75:4e:4e:50:
             65:af:64:92:11:92:7f:64:67:22:25:bc:53:76:f5:70:7c:f5:
             1b:de:d2:4f:1e:80:17:26:c8:3f:64:01:ba:57:28:a7:51:b9:
             d5:e6:92:27:8c:4a:ad:ac:77:19:17:d3:e7:d8:a1:fb:02:7a:
             35:c4:94:e9:72:31:b3:55:03:2a:09:7e:be:51:9c:6c:c9:9d:
             24:75:99:0e:96:db:a0:a6:55:18:d8:e8:75:f1:90:6a:dd:05:
             8b:f9:71:7d:d8:c5:c4:7e:8b:ec:03:6f:11:75:2e:ac:58:1b:
             35:bb:48:58:eb:ed:95:a8:20:1e:44:b9:1a:bf:8d:42:14:31:
             08:c9:6a:2c:f6:82:76:f8:0f:32:b3:4f:46:83:5d:cb:50:43:
             17:bb:6f:4e:16:1d:b4:b3:e6:a4:60:3e:b7:dc:0a:99:00:78:
             9e:aa:5f:02:fe:34:e1:7d:98:12:8d:7e:52:58:c9:d0:d6:3e:
             51:47:85:a1:06:3e:a4:4c:f1:30:38:bd:d1:39:1f:39:c2:32:
             1d:39:20:b3


The CSR is signed with the private key and contains the public
key. Signing with the private key shows proof of possession of the
private key. The signature is verified with the public key that is
already there in the CSR.

How does the CA know that you are the organization you claim to be and
verify that your key really is as defined in the CSR? This is an
operational question. This is handled using “human” approaches or by
verifying the ownership of the domain or by checking against the
person or … For websites, this mechanism is identified in the Baseline
Requirements of the CA/Browser Forum.

CAs can request proof of identity, and the ability to control the
domain using DNS to modify DNS resource records.

##	Options for CSR
There are many options for generating a CSR as described above. There
are two ways to fill the CSR request.

* Using openssl interactively as above is a manual approach. You have
to interactively enter the information.

* Instead you can setup a config file to automate this
process. Automation is important in order to regularly order new
certificates or renew existing ones.

Create a config file that has the information requested in the CSR
request generation and pass that config file to the openssl.


==> cat csr.cnf

    [req]
    prompt = no
    distinguished_name = dn
    [dn]
    CN = www.coolcompany.example
    emailAddress = admin@coolcompany.example
    O = My Cool Company Ltd
    OU = Finance
    L = Chennai
    C = IN
    ST = Tamil Nadu


==> openssl req -new -config csr.cnf -key certkey.key -out certwithconf.csr

==> ls -al

    total 28
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  7 12:36 .
    drwxr-xr-x 5 cybersecurity cybersecurity 4096 Jun  7 11:26 ..
    -rw-r--r-- 1 cybersecurity cybersecurity 1102 Jun  7 11:38 cert.csr
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  7 11:31 certkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  7 11:32 certpubkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity 1102 Jun  7 12:40 certwithconf.csr
    -rw-r--r-- 1 cybersecurity cybersecurity  191 Jun  7 12:36 csr.cnf

Question: There is a difference in SubjectName between cert.csr and certwithconf.csr. Identify it.

##	Self-sign certificate

Now we need to sign the certificates. There are two ways to do this:

* If the certificate is used internally within the organization, then
it can be self-signed. This only ensures that the information within
the certificate is not modified but doesn’t provide any security to
the outside world. For instance, I can create a certificate for
www.google.com and sign it myself. But that doesn’t make me
www.google.com. Nobody should look at a self signed certificate and
assume it is google.com.

* Use a Certificate Authority to sign the certificate. CAs are trusted
entities, who validate the information and make sure you are Google
Inc and you own the website www.google.com before signing and issuing
the certificate. This is similar to public notary service.  CA signed
certificates are needed to expose the service to the general
public. You have to specify the validity of the certificate in terms
of “Not Valid Before” and “Not Valid After”.

==> openssl x509 -req -days 365 -in cert.csr -signkey certkey.key -out cert.crt

    Signature ok
    subject=C = IN, ST = Tamil Nadu, L = Chennai, O = My Cool Company Ltd, OU = Finance, CN = www.coolcompany.example, emailAddress = admin@coolcompany.example
    Getting Private key

==> ls -al


    total 32
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  8 20:56 .
    drwxr-xr-x 5 cybersecurity cybersecurity 4096 Jun  7 11:26 ..
    -rw-r--r-- 1 cybersecurity cybersecurity 1415 Jun  8 20:56 cert.crt
    -rw-r--r-- 1 cybersecurity cybersecurity 1102 Jun  7 11:38 cert.csr
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  7 11:31 certkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  7 11:32 certpubkey.key
    -rw-r--r-- 1 cybersecurity cybersecurity 1102 Jun  7 12:40 certwithconf.csr
    -rw-r--r-- 1 cybersecurity cybersecurity  191 Jun  7 12:36 csr.cnf


==> cat cert.crt


    -----BEGIN CERTIFICATE-----
    MIID6TCCAtECFBd6XHDLuc9Yh6StlgbJH6F6yUXfMA0GCSqGSIb3DQEBCwUAMIGw
    MQswCQYDVQQGEwJJTjETMBEGA1UECAwKVGFtaWwgTmFkdTEQMA4GA1UEBwwHQ2hl
    bm5haTEcMBoGA1UECgwTTXkgQ29vbCBDb21wYW55IEx0ZDEQMA4GA1UECwwHRmlu
    YW5jZTEgMB4GA1UEAwwXd3d3LmNvb2xjb21wYW55LmV4YW1wbGUxKDAmBgkqhkiG
    9w0BCQEWGWFkbWluQGNvb2xjb21wYW55LmV4YW1wbGUwHhcNMTkwNjA4MTUyNjU3
    WhcNMjAwNjA3MTUyNjU3WjCBsDELMAkGA1UEBhMCSU4xEzARBgNVBAgMClRhbWls
    IE5hZHUxEDAOBgNVBAcMB0NoZW5uYWkxHDAaBgNVBAoME015IENvb2wgQ29tcGFu
    eSBMdGQxEDAOBgNVBAsMB0ZpbmFuY2UxIDAeBgNVBAMMF3d3dy5jb29sY29tcGFu
    eS5leGFtcGxlMSgwJgYJKoZIhvcNAQkBFhlhZG1pbkBjb29sY29tcGFueS5leGFt
    cGxlMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA38EBg8RrrrwJl7cI
    BT+ML0aq+0n/aheHoSB7WxvlPdggOAHnJ86RDgl6ztHxqPqVvHrgiYvA4JO+Xp+k
    lRdrzkhLUrFpWOTWcKwPYHxayfAPuB/Z/H10+Snzo3hT+PPLg0e+1F66q9Mg6CYn
    iZasDDKaXVj6NIl25S4hl1f4FHkwt00h6lgk/IqQClza8AYsqJnNHj5QfRyQ/Ard
    yBKl1C0CMnqqcc6Sev6Icr4xu8A/daOV83nVHnuTintGujm3gmszZwCpZ2hjqXrD
    PEw+O/Ulko2/DJIkm0Bk7V4uXbhOz+trUEFb9RIl6vL0cNiHoMLlpjiQCFIYzc6u
    5BEN9wIDAQABMA0GCSqGSIb3DQEBCwUAA4IBAQCp67cNF81VcZ+vyOG1iBpRU50P
    4dMMZZoX/qmHS6ECYAiKbuzuH9ROH8i9+Y3hgQ328oHCzMM38BdXHAiToE9u0iJq
    ebnDuy2tM8XnPVndAFxw9BpmzW8+o4j6Pk/qkKP5OCqJA38f8KytShj+tgMG5LyE
    iW54X61R2lkZORyNXl7uEbRP78w5SQCpYCWmGrT9hZpgFyQD7KA8Byi2DXrjgnDx
    wqA2yAfae40EBGV7gOkjL+Z5y8IJuGwuEXp8k8GOwyI9+Uy23rirIEyloTKAlsz0
    ZXHMwuh9ajAOO6suYzBZGpiYy6IEBB7KIRVOdU1eUE7xMYHzTfmvmtQpNWZD
    -----END CERTIFICATE-----

==> openssl x509 -in cert.crt -text -noout

    Certificate:
        Data:
            Version: 1 (0x0)
            Serial Number:
                17:7a:5c:70:cb:b9:cf:58:87:a4:ad:96:06:c9:1f:a1:7a:c9:45:df
            Signature Algorithm: sha256WithRSAEncryption
            Issuer: C = IN, ST = Tamil Nadu, L = Chennai, O = My Cool Company Ltd, OU = Finance, CN = www.coolcompany.example, emailAddress = admin@coolcompany.example
            Validity
                Not Before: Jun  8 15:26:57 2019 GMT
                Not After : Jun  7 15:26:57 2020 GMT
            Subject: C = IN, ST = Tamil Nadu, L = Chennai, O = My Cool Company Ltd, OU = Finance, CN = www.coolcompany.example, emailAddress = admin@coolcompany.example
            Subject Public Key Info:
                Public Key Algorithm: rsaEncryption
                    RSA Public-Key: (2048 bit)
                    Modulus:
                        00:df:c1:01:83:c4:6b:ae:bc:09:97:b7:08:05:3f:
                        8c:2f:46:aa:fb:49:ff:6a:17:87:a1:20:7b:5b:1b:
                        e5:3d:d8:20:38:01:e7:27:ce:91:0e:09:7a:ce:d1:
                        f1:a8:fa:95:bc:7a:e0:89:8b:c0:e0:93:be:5e:9f:
                        a4:95:17:6b:ce:48:4b:52:b1:69:58:e4:d6:70:ac:
                        0f:60:7c:5a:c9:f0:0f:b8:1f:d9:fc:7d:74:f9:29:
                        f3:a3:78:53:f8:f3:cb:83:47:be:d4:5e:ba:ab:d3:
                        20:e8:26:27:89:96:ac:0c:32:9a:5d:58:fa:34:89:
                        76:e5:2e:21:97:57:f8:14:79:30:b7:4d:21:ea:58:
                        24:fc:8a:90:0a:5c:da:f0:06:2c:a8:99:cd:1e:3e:
                        50:7d:1c:90:fc:0a:dd:c8:12:a5:d4:2d:02:32:7a:
                        aa:71:ce:92:7a:fe:88:72:be:31:bb:c0:3f:75:a3:
                        95:f3:79:d5:1e:7b:93:8a:7b:46:ba:39:b7:82:6b:
                        33:67:00:a9:67:68:63:a9:7a:c3:3c:4c:3e:3b:f5:
                        25:92:8d:bf:0c:92:24:9b:40:64:ed:5e:2e:5d:b8:
                        4e:cf:eb:6b:50:41:5b:f5:12:25:ea:f2:f4:70:d8:
                        87:a0:c2:e5:a6:38:90:08:52:18:cd:ce:ae:e4:11:
                        0d:f7
                    Exponent: 65537 (0x10001)
        Signature Algorithm: sha256WithRSAEncryption
             a9:eb:b7:0d:17:cd:55:71:9f:af:c8:e1:b5:88:1a:51:53:9d:
             0f:e1:d3:0c:65:9a:17:fe:a9:87:4b:a1:02:60:08:8a:6e:ec:
             ee:1f:d4:4e:1f:c8:bd:f9:8d:e1:81:0d:f6:f2:81:c2:cc:c3:
             37:f0:17:57:1c:08:93:a0:4f:6e:d2:22:6a:79:b9:c3:bb:2d:
             ad:33:c5:e7:3d:59:dd:00:5c:70:f4:1a:66:cd:6f:3e:a3:88:
             fa:3e:4f:ea:90:a3:f9:38:2a:89:03:7f:1f:f0:ac:ad:4a:18:
             fe:b6:03:06:e4:bc:84:89:6e:78:5f:ad:51:da:59:19:39:1c:
             8d:5e:5e:ee:11:b4:4f:ef:cc:39:49:00:a9:60:25:a6:1a:b4:
             fd:85:9a:60:17:24:03:ec:a0:3c:07:28:b6:0d:7a:e3:82:70:
             f1:c2:a0:36:c8:07:da:7b:8d:04:04:65:7b:80:e9:23:2f:e6:
             79:cb:c2:09:b8:6c:2e:11:7a:7c:93:c1:8e:c3:22:3d:f9:4c:
             b6:de:b8:ab:20:4c:a5:a1:32:80:96:cc:f4:65:71:cc:c2:e8:
             7d:6a:30:0e:3b:ab:2e:63:30:59:1a:98:98:cb:a2:04:04:1e:
             ca:21:15:4e:75:4d:5e:50:4e:f1:31:81:f3:4d:f9:af:9a:d4:
             29:35:66:43

Question: Identify the difference between CSR and Certificate.

##	Extensions
You can add extensions to the certificate. A common extension is
Subject Alternate Name (SAN). This lists all the possible names that
the certificate can be used for. In the case of Web PKI, it lists all
the domain names, such as www.coolcompany.example,
my.coolcompany.example, coolcompany.example and so on. There are many
other extensions possible, such as what the key can be used for.

When creating the certificate, you can create an extensions file and
use that as part of the certificate creation.

==> cat > cert.ext

    subjectAltName = DNS:*.coolcompany.example, DNS:coolcompany.example

==>  openssl x509 -req -days 365 -in cert.csr -signkey certkey.key -out certext.crt -extfile cert.ext

    Signature ok
    subject=C = IN, ST = Tamil Nadu, L = Chennai, O = My Cool Company Ltd, OU = Finance, CN = www.coolcompany.example, emailAddress = admin@coolcompany.example
    Getting Private key
