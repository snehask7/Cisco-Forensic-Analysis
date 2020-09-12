# Table of Contents
-   [Key Pair Usage - hands on](#key-pair-usage---hands-on)
    -   [Generate RSA key pair](#generate-rsa-key-pair)
    -   [Generate ECC key pair](#generate-ecc-key-pair)
    -   [PEM vs DER and other formats](#pem-vs-der-and-other-formats)
    -   [Sign and verify using keys](#sign-and-verify-using-keys)
        -   [Sign](#sign)
        -   [Verify Good File](#verify-good-file)
        -   [Verify Bad File](#verify-bad-file)
    -   [Encrypt and Decrypt using keys](#encrypt-and-decrypt-using-keys)
        -   [Encryption](#encryption)
        -   [Decryption](#decryption)
#	Key Pair Usage - hands on
##	Generate RSA key pair

1. openssl genrsa: generate RSA keypair

	    Generating RSA private key, 2048 bit long modulus (2 primes)
	    .....+++++
	    ..........+++++
	    e is 65537 (0x010001)
	    -----BEGIN RSA PRIVATE KEY-----
	    MIIEpgIBAAKCAQEA7Nk5LpuPA1ZiWqCHfwVi1holwLTkb2hTwX4iOarC8fEfWMLk
	    heqfvi7Aik7PZOKtLVl4q8jebjqxBm2hnow+TcBfPCGiJGlzFn9ABGO122qtJ20e
	    YsjhB7kronG/DG82b/pc7ostT3ZBpjEykt8ytTPBxAt5+pFclXzj65eP4ERki25w
	    RMqCzFKWzc/q++fWfun053m+T26HeP4zCHMkPV9vTIJuI+dtuJ0Xa19k8kf61KBU
	    7wFDuDbo3rfs7dk3Nv1b68/IxSo2aLl8vMhJ5S1bM6F4ifUcZqfh9cDpqfw0L1jl
	    xaI9nJkbQzJ5jnqDncSAVtERHNSu4zOxsXxLkQIDAQABAoIBAQCMkLL2LU5oLal7
	    ndAsm5a3+Ja1UuZMFD+5E1HepbDDBFaVSD12GPQrW/XbX8CIYFtlEbejRDh2dRDA
	    /umvfg4v+N7Mgi2HrKmoDWeB82dnzFztjD4/ZHbhLY1vAFDhYVOOi6kBzcnbYhS+
	    PG6Gaj7e+dOitSj0g7bN5WwjUzUJZIlG/VKKWnRGZtstXX5jm0wQew6PW561tv8Y
	    s/J2AAab/2THcHQQ5tqsaCwyCLimSBvE7DoYxcf9LKIpTEuZOpA5Bz66PJdgnYzY
	    EXutIw8DU1iA6Uw5KZHaAl0ByAitpCezfThLjJkSkVP5fKRrsek9sDRIygtVa3Qa
	    nEEVwMjdAoGBAP+sKcVtLOqtRMcEzPqksd1gNX1Dxy99Hb+3VmVrJuFukssEDGKM
	    BPaaE5cCzSDRZJ4p7Bt+Xpp4qAMDnA2a4VWEMTCbVdvEgOTxSGBPvLpYqcpt3cQA
	    gLC2TLWlVgWDi08BJdLiwBBnBSajT72RveUeMyFyh3QLgWrvRvIHHiDXAoGBAO0m
	    4z8NymYt6+KYN0yBWYfBjuXlOZVjVAURcKcrnQrQ6zB/KT7IzR+NkSA/JwmCv454
	    pIbPLyAYtvqdi8wEIwC1ROvB0dra6kVuUTlKLSjy6wvKq1NEibFptJf42JtvsqHZ
	    y3NzH/Zw25ha7jGilwfgPR3vj1+cMlA6Ph19RSHXAoGBAPxrPiZDnmfnPxL6I2GF
	    vnDgbo7Intu8u+Uunaatfopsf5Ld4VheAvxwq8yYoGq5MIySuR9/yOjbHI01QBmS
	    gsvKIkJp6f96ZwMhUCJ+NscHiEJp69t535QXt25S2LXC5IPQj0ZARf0rqMM30x9G
	    x2NwSGzKRP8F6PTpXXLQIierAoGBANtoBAy9HImmaLtuqpK8hXGFEUj+52SfzgcW
	    WIxBXHy6Ry3KKAWvT5+moSMdamdxMPqGAWm721StqPR6t/DbzuqDyqz318jMirwL
	    0VfYmalt/Soeqp1SJrYeHvgPQY+lKrZ1QragR20AgxoU3pTLYUHnI4RDs/j4ENCK
	    4hb0Y/ZnAoGBAIoAitJHM6tCypiQB+wMvBjmTeV90smglGoq20a7MiwKMHlidxxI
	    YcY5AVMCeahOxpIA7cNMWTMvgZru+rQblLXCWD/tZ3Gd9MQzf0sunxWKJhUV/Mk0
	    mPX/HkBJaXu2kN5gkFXAHCs9E8SJLWy6FG4tKox+Uw9wo0G1Br+WVAHQ
	    -----END RSA PRIVATE KEY-----


2. openssl genrsa -aes128 2048: Generate the keys and encrypt them
   using aes128 with a password.


	    Generating RSA private key, 2048 bit long modulus (2 primes)
	    .........................................................................+++++
	    .......................................................+++++
	    e is 65537 (0x010001)
	    Enter pass phrase:
	    Verifying - Enter pass phrase:
	    -----BEGIN RSA PRIVATE KEY-----
	    Proc-Type: 4,ENCRYPTED
	    DEK-Info: AES-128-CBC,340F7B75AA2A289A828F7AC1E20DB68B

	    xTxjUWV5xvlYKneT/XRif2Hj8s/xtJHPEjn4gt5ceKcfJdMNnVam1cWM96d+gS2W
	    u8aDw5dT3zCSnLpQAMK5bhBTWWN3/pBktvRfDXLTo+PpJEYvCppTYhM42kb8Q4+y
	    09jdFwPFHBHwy9a9nbR3Nlb0TIpwZgEQ0/dXX4GVyjfJe9cwxI4FTfSip58rrs8V
	    e+5dOL+3K+CfMB71jGb/z9KWzkD/6veVbnwMuqmBVN5RxnepH8ozNHhrLDJ9Z2Xd
	    cifFB0SFXZljFAGXZs2NH9LlkzCasYhgmLSxkBz/zz6qKgUaWERF9Zvgkja/jMfO
	    iavQUdOg+DKxTH1beDU3Aol1f7IOTTdnzNjbAABDe6VXsCphy7u7Aj8dWdfGDD9V
	    NCNPCNcw2DAlSRmJHOXZLQJH2YLuY8HbY53KAVAzZrZQ/8tz7oKCQTKCY/jx8nt7
	    fCEa6Z7W5/KgJ/eaWMb4KUkVkcPTWruz1X8P2GGBOjXJKL4XB1fQavi8HLFZyDc6
	    ccv2QODlXT+KMunAURxJw7Pe/cVA1JDHrCTLlgwQ1nkGSl7vSytaVnuZrG1MAb5C
	    azduzCvrq87L3kTuDFZzYTNAyxAwkMw3BxrD7QmDXhQY6IJldR5pWufarDtJBNwA
	    vMvKT6BPo2P1nrP/cVpOsTY5+7hryO+/A2blM2ErOMHtYswyQ1kQtBnOibwXTW0V
	    bd4FEBMy09Vuh0a6fFaramFtcCpQiKowJ+2a7QYQySi8Wl+y+iKvo7dKW7q9nHBj
	    3VOgv424i2NsAmx3xw3VvHI4DX2HWVSu65QVqZbCqcHnbGNlv20wb+rIwkSSJtN1
	    wakbqdkafs3WR4R+N7uYMpx4sI69FmXVwWnmNSru9ng3dNBLDPzBDBltoyQ5j8L2
	    ud5WWApziitWURg9YR5wie1jsvWKyJG1oVE8OQ+ekzn89yPyYyLqzjzkksPZOwWA
	    pBpWs6hwkTXuEeWqUz+MRhMq7r8yk59BaAgTcFc6z18MOyAGwCYZbM8U4OP/Fcay
	    /ZZj89HSJY8Z/Qre/5EH5b1Hz3taTa4UwIbWOxJSSuhJP6MF4P9wyYwG6CjFLzz1
	    4Rwzi66nmGiEHZNX3kN16zEeie8PrOyDqIQmz+h3C7n3SotYc2LYkJHrCPNYTAjs
	    kjg6hOwrs00WNfSprRENuxf9/JcbeTJ9iLN9jwn12MoHQLOmxH4vEk3QVF0nSdIH
	    iQFKAWiamw8DpVxoaDFoFoc8ABGJjokc6f90pDgNpi0XIxh/27aI1X/Su9cPLW3/
	    vVScgV8HuRev3W7E0KwUkXVqR701E2CEoz7y5VYiEkTU9oicC2A2MpcsvmUDqIBr
	    EvAkRyzGr0FW00cvic50iE1PlZyPA4MBVOk4z6KYpbEgNuO/Cyxgr80L14LnUMSx
	    +ww80AinfqB8hBDZApLheXk7MpRFGuPd29ECDfnA3cWI9jRWGQdt6ZQ8NWkjmiUV
	    oWjx8OIQzdkUTNtZLiSGWz6jMcnP8IyOUqOrN2qC2Yji340L17RyJNp49VYIZUhv
	    vMT64WAEVTPsEFpaFDsuf4SPbv8cO/8OVbzdhho63wSb51fmufVZBiYESRTWE3hA
	    -----END RSA PRIVATE KEY-----


1. The PRIVATE key encodes the public key also. The data format is
PEM. You can store the data into a file.

==> openssl genrsa  -out key.pem 2048

		Generating RSA private key, 2048 bit long modulus (2 primes)
		.............................................................+++++
		...+++++
		e is 65537 (0x010001)

==> ls -al

    total 12
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  4 09:39 .
    drwxr-xr-x 4 cybersecurity cybersecurity 4096 Jun  4 09:16 ..
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  4 09:39 key.pem

==> cat key.pem

    -----BEGIN RSA PRIVATE KEY-----
    MIIEowIBAAKCAQEAq6+k7R+C9pnwk8tXu82FCG3aMEw8piWUS+oucUUMymKOpNH+
    zEriyBj9rSNf5qPwtFepb+k4yuRCr+1zshU6BBpA9udATGlTJZXKnURuBVbPe7nW
    V59YYQEAwf7+fhCWjyzYFjM5njdPw5t3Ablw6hDHcYEpGSVQJXES9SwxjWEmOQls
    mM14AKpqzwxcJweJDNEGWpGSb28uJEbwmaN3KezSOE2Rqvu2f149tOs+e5YOOqmP
    SFsL5Fthut1lo+kzFJ6GlAHjaYPweJw+KDK4WBm6LPKbLSp75+xYHrT8WjkkrgqO
    JhXOGfCw17DDkAM4Zkpbuqjx1tOUmP28TWfCYQIDAQABAoIBAFX4WRzIB7tWcGqB
    i0gmbLRA1d4TftcvwCeXd3QOwI3jdkxAP1erNA5AvV5idVY3x4N21giM/3xRerc/
    rwyAppGBWACK4d6haxpJ/LBtoK4Zv0HUV+l+iDHi369E8cjMo6fEK9xKAFMinVV0
    1s3NPyZmCojixWKrFYv6KCUO4S1Ko3FnrtVMua/u2mX9DEQY9LHmvLDFF6kgqVI1
    oGPEdz17902dyRzc0IN6RKr51WZ5xOC0Vzq6n5rr9ARexdXHPNcRonREIh+waU+O
    Q/LojeHsyJY6jRFgvkhYF1HKtWCu8031ox2FevZL8vXOCnaopJnwfgbMUuXwMZ9F
    mHqBAIUCgYEA0+Mv9XsTURu8wbKjd7AKJUHPZIkVIrbPn4QnEN/zx9G+nI5C3/7x
    sAMu09GZtlJn1+6YAUMNmQzidqHc9ohXpijCiWfq0VoodXCWjjoOCjOyjlPFBljB
    GCCBmVTQRXohj7gQyc5ygpFWRe0s6MwNs24weF01/Xm9aJkvsAiT388CgYEAz23g
    BCHHe9EaK2jYvSPAz2YZZYmMaL7ahyc+QOWzIAMmWRlP67aGKDawdDLiEhPEEjju
    cZgLkWSvvjuHovCf2DZsfs6pqSneQveM1y7E7zaI5ens5P/dIiZdpnlvdWxdOlLa
    VDo9W5bnHwoNx232Oi2RO78I5ZI5pUxwRqpGFs8CgYAPsLIbdnquteQbX9QVB9co
    fSATbMdA49KqGEogSMUvlcuMokg3eBSDmSi9jLbaNm30InnlFgcKv1aBvGi1ZNFA
    v6HwNN7Bk/CNCcJMU+Y4QS3GtlNPrgDWfYm7RfmKO4oCr3mmx//YxVRjJzX9Iycc
    k1tJfnWCCKLK/RT37xqsJwKBgQCTOfVqeV9RbpUYgo5zkNDlZB5ah0p1fiE1FJGH
    FoIREqtBSkoDj8Wg/VA46XS0R/s+w9HaJoTvaXujljUrXYbWu6o+Rwj83I65EWOR
    x8xXzWlVZreRwll+R6To6ABIY+W34967MasjOvRIf6ZQCqhdmsIemfUCnMr1nE+E
    mI6u2QKBgDkE5G8RDrlRYrHUSCyTVmf7xngk3eTnjDIVfDBTpYJ8ZgCBtB7moLEz
    RahjYxy26c9V7LJOfDGgP07PPFffnj4xpMPhQaQA8Yc0wReEcVbHE9Hg4sLJ2q5h
    YjZGDMM3YitYfHmLtq3XVE6MeLX72HE4g2Va5Ndg2s+jWvtxHEaq
    -----END RSA PRIVATE KEY-----



1. See the details of the key in ASN.1 format.

==> openssl  asn1parse  -inform pem -in key.pem

    0:d=0  hl=4 l=1187 cons: SEQUENCE          
        4:d=1  hl=2 l=   1 prim: INTEGER           :00
        7:d=1  hl=4 l= 257 prim: INTEGER           :ABAFA4ED1F82F699F093CB57BBCD85086DDA304C3CA625944BEA2E71450CCA628EA4D1FECC4AE2C818FDAD235FE6A3F0B457A96FE938CAE442AFED73B2153A041A40F6E7404C69532595CA9D446E0556CF7BB9D6579F58610100C1FEFE7E10968F2CD81633399E374FC39B7701B970EA10C7718129192550257112F52C318D612639096C98CD7800AA6ACF0C5C2707890CD1065A91926F6F2E2446F099A37729ECD2384D91AAFBB67F5E3DB4EB3E7B960E3AA98F485B0BE45B61BADD65A3E933149E869401E36983F0789C3E2832B85819BA2CF29B2D2A7BE7EC581EB4FC5A3924AE0A8E2615CE19F0B0D7B0C3900338664A5BBAA8F1D6D39498FDBC4D67C261
      268:d=1  hl=2 l=   3 prim: INTEGER           :010001
      273:d=1  hl=4 l= 256 prim: INTEGER           :55F8591CC807BB56706A818B48266CB440D5DE137ED72FC0279777740EC08DE3764C403F57AB340E40BD5E62755637C78376D6088CFF7C517AB73FAF0C80A6918158008AE1DEA16B1A49FCB06DA0AE19BF41D457E97E8831E2DFAF44F1C8CCA3A7C42BDC4A0053229D5574D6CDCD3F26660A88E2C562AB158BFA28250EE12D4AA37167AED54CB9AFEEDA65FD0C4418F4B1E6BCB0C517A920A95235A063C4773D7BF74D9DC91CDCD0837A44AAF9D56679C4E0B4573ABA9F9AEBF4045EC5D5C73CD711A27444221FB0694F8E43F2E88DE1ECC8963A8D1160BE48581751CAB560AEF34DF5A31D857AF64BF2F5CE0A76A8A499F07E06CC52E5F0319F45987A810085
      533:d=1  hl=3 l= 129 prim: INTEGER           :D3E32FF57B13511BBCC1B2A377B00A2541CF64891522B6CF9F842710DFF3C7D1BE9C8E42DFFEF1B0032ED3D199B65267D7EE9801430D990CE276A1DCF68857A628C28967EAD15A287570968E3A0E0A33B28E53C50658C11820819954D0457A218FB810C9CE7282915645ED2CE8CC0DB36E30785D35FD79BD68992FB00893DFCF
      665:d=1  hl=3 l= 129 prim: INTEGER           :CF6DE00421C77BD11A2B68D8BD23C0CF661965898C68BEDA87273E40E5B320032659194FEBB6862836B07432E21213C41238EE71980B9164AFBE3B87A2F09FD8366C7ECEA9A929DE42F78CD72EC4EF3688E5E9ECE4FFDD22265DA6796F756C5D3A52DA543A3D5B96E71F0A0DC76DF63A2D913BBF08E59239A54C7046AA4616CF
      797:d=1  hl=3 l= 128 prim: INTEGER           :0FB0B21B767AAEB5E41B5FD41507D7287D20136CC740E3D2AA184A2048C52F95CB8CA248377814839928BD8CB6DA366DF42279E516070ABF5681BC68B564D140BFA1F034DEC193F08D09C24C53E638412DC6B6534FAE00D67D89BB45F98A3B8A02AF79A6C7FFD8C554632735FD23271C935B497E758208A2CAFD14F7EF1AAC27
      928:d=1  hl=3 l= 129 prim: INTEGER           :9339F56A795F516E9518828E7390D0E5641E5A874A757E213514918716821112AB414A4A038FC5A0FD5038E974B447FB3EC3D1DA2684EF697BA396352B5D86D6BBAA3E4708FCDC8EB9116391C7CC57CD695566B791C2597E47A4E8E8004863E5B7E3DEBB31AB233AF4487FA6500AA85D9AC21E99F5029CCAF59C4F84988EAED9
     1060:d=1  hl=3 l= 128 prim: INTEGER           :3904E46F110EB95162B1D4482C935667FBC67824DDE4E78C32157C3053A5827C660081B41EE6A0B13345A863631CB6E9CF55ECB24E7C31A03F4ECF3C57DF9E3E31A4C3E141A400F18734C117847156C713D1E0E2C2C9DAAE616236460CC337622B587C798BB6ADD7544E8C78B5FBD8713883655AE4D760DACFA35AFB711C46AA


1. Get text equivalent of the RSA key.

==> openssl rsa -in key.pem -inform pem -noout -text

    RSA Private-Key: (2048 bit, 2 primes)
    modulus:
        00:ab:af:a4:ed:1f:82:f6:99:f0:93:cb:57:bb:cd:
        85:08:6d:da:30:4c:3c:a6:25:94:4b:ea:2e:71:45:
        0c:ca:62:8e:a4:d1:fe:cc:4a:e2:c8:18:fd:ad:23:
        5f:e6:a3:f0:b4:57:a9:6f:e9:38:ca:e4:42:af:ed:
        73:b2:15:3a:04:1a:40:f6:e7:40:4c:69:53:25:95:
        ca:9d:44:6e:05:56:cf:7b:b9:d6:57:9f:58:61:01:
        00:c1:fe:fe:7e:10:96:8f:2c:d8:16:33:39:9e:37:
        4f:c3:9b:77:01:b9:70:ea:10:c7:71:81:29:19:25:
        50:25:71:12:f5:2c:31:8d:61:26:39:09:6c:98:cd:
        78:00:aa:6a:cf:0c:5c:27:07:89:0c:d1:06:5a:91:
        92:6f:6f:2e:24:46:f0:99:a3:77:29:ec:d2:38:4d:
        91:aa:fb:b6:7f:5e:3d:b4:eb:3e:7b:96:0e:3a:a9:
        8f:48:5b:0b:e4:5b:61:ba:dd:65:a3:e9:33:14:9e:
        86:94:01:e3:69:83:f0:78:9c:3e:28:32:b8:58:19:
        ba:2c:f2:9b:2d:2a:7b:e7:ec:58:1e:b4:fc:5a:39:
        24:ae:0a:8e:26:15:ce:19:f0:b0:d7:b0:c3:90:03:
        38:66:4a:5b:ba:a8:f1:d6:d3:94:98:fd:bc:4d:67:
        c2:61
    publicExponent: 65537 (0x10001)
    privateExponent:
        55:f8:59:1c:c8:07:bb:56:70:6a:81:8b:48:26:6c:
        b4:40:d5:de:13:7e:d7:2f:c0:27:97:77:74:0e:c0:
        8d:e3:76:4c:40:3f:57:ab:34:0e:40:bd:5e:62:75:
        56:37:c7:83:76:d6:08:8c:ff:7c:51:7a:b7:3f:af:
        0c:80:a6:91:81:58:00:8a:e1:de:a1:6b:1a:49:fc:
        b0:6d:a0:ae:19:bf:41:d4:57:e9:7e:88:31:e2:df:
        af:44:f1:c8:cc:a3:a7:c4:2b:dc:4a:00:53:22:9d:
        55:74:d6:cd:cd:3f:26:66:0a:88:e2:c5:62:ab:15:
        8b:fa:28:25:0e:e1:2d:4a:a3:71:67:ae:d5:4c:b9:
        af:ee:da:65:fd:0c:44:18:f4:b1:e6:bc:b0:c5:17:
        a9:20:a9:52:35:a0:63:c4:77:3d:7b:f7:4d:9d:c9:
        1c:dc:d0:83:7a:44:aa:f9:d5:66:79:c4:e0:b4:57:
        3a:ba:9f:9a:eb:f4:04:5e:c5:d5:c7:3c:d7:11:a2:
        74:44:22:1f:b0:69:4f:8e:43:f2:e8:8d:e1:ec:c8:
        96:3a:8d:11:60:be:48:58:17:51:ca:b5:60:ae:f3:
        4d:f5:a3:1d:85:7a:f6:4b:f2:f5:ce:0a:76:a8:a4:
        99:f0:7e:06:cc:52:e5:f0:31:9f:45:98:7a:81:00:
        85
    prime1:
        00:d3:e3:2f:f5:7b:13:51:1b:bc:c1:b2:a3:77:b0:
        0a:25:41:cf:64:89:15:22:b6:cf:9f:84:27:10:df:
        f3:c7:d1:be:9c:8e:42:df:fe:f1:b0:03:2e:d3:d1:
        99:b6:52:67:d7:ee:98:01:43:0d:99:0c:e2:76:a1:
        dc:f6:88:57:a6:28:c2:89:67:ea:d1:5a:28:75:70:
        96:8e:3a:0e:0a:33:b2:8e:53:c5:06:58:c1:18:20:
        81:99:54:d0:45:7a:21:8f:b8:10:c9:ce:72:82:91:
        56:45:ed:2c:e8:cc:0d:b3:6e:30:78:5d:35:fd:79:
        bd:68:99:2f:b0:08:93:df:cf
    prime2:
        00:cf:6d:e0:04:21:c7:7b:d1:1a:2b:68:d8:bd:23:
        c0:cf:66:19:65:89:8c:68:be:da:87:27:3e:40:e5:
        b3:20:03:26:59:19:4f:eb:b6:86:28:36:b0:74:32:
        e2:12:13:c4:12:38:ee:71:98:0b:91:64:af:be:3b:
        87:a2:f0:9f:d8:36:6c:7e:ce:a9:a9:29:de:42:f7:
        8c:d7:2e:c4:ef:36:88:e5:e9:ec:e4:ff:dd:22:26:
        5d:a6:79:6f:75:6c:5d:3a:52:da:54:3a:3d:5b:96:
        e7:1f:0a:0d:c7:6d:f6:3a:2d:91:3b:bf:08:e5:92:
        39:a5:4c:70:46:aa:46:16:cf
    exponent1:
        0f:b0:b2:1b:76:7a:ae:b5:e4:1b:5f:d4:15:07:d7:
        28:7d:20:13:6c:c7:40:e3:d2:aa:18:4a:20:48:c5:
        2f:95:cb:8c:a2:48:37:78:14:83:99:28:bd:8c:b6:
        da:36:6d:f4:22:79:e5:16:07:0a:bf:56:81:bc:68:
        b5:64:d1:40:bf:a1:f0:34:de:c1:93:f0:8d:09:c2:
        4c:53:e6:38:41:2d:c6:b6:53:4f:ae:00:d6:7d:89:
        bb:45:f9:8a:3b:8a:02:af:79:a6:c7:ff:d8:c5:54:
        63:27:35:fd:23:27:1c:93:5b:49:7e:75:82:08:a2:
        ca:fd:14:f7:ef:1a:ac:27
    exponent2:
        00:93:39:f5:6a:79:5f:51:6e:95:18:82:8e:73:90:
        d0:e5:64:1e:5a:87:4a:75:7e:21:35:14:91:87:16:
        82:11:12:ab:41:4a:4a:03:8f:c5:a0:fd:50:38:e9:
        74:b4:47:fb:3e:c3:d1:da:26:84:ef:69:7b:a3:96:
        35:2b:5d:86:d6:bb:aa:3e:47:08:fc:dc:8e:b9:11:
        63:91:c7:cc:57:cd:69:55:66:b7:91:c2:59:7e:47:
        a4:e8:e8:00:48:63:e5:b7:e3:de:bb:31:ab:23:3a:
        f4:48:7f:a6:50:0a:a8:5d:9a:c2:1e:99:f5:02:9c:
        ca:f5:9c:4f:84:98:8e:ae:d9
    coefficient:
        39:04:e4:6f:11:0e:b9:51:62:b1:d4:48:2c:93:56:
        67:fb:c6:78:24:dd:e4:e7:8c:32:15:7c:30:53:a5:
        82:7c:66:00:81:b4:1e:e6:a0:b1:33:45:a8:63:63:
        1c:b6:e9:cf:55:ec:b2:4e:7c:31:a0:3f:4e:cf:3c:
        57:df:9e:3e:31:a4:c3:e1:41:a4:00:f1:87:34:c1:
        17:84:71:56:c7:13:d1:e0:e2:c2:c9:da:ae:61:62:
        36:46:0c:c3:37:62:2b:58:7c:79:8b:b6:ad:d7:54:
        4e:8c:78:b5:fb:d8:71:38:83:65:5a:e4:d7:60:da:
        cf:a3:5a:fb:71:1c:46:aa


==> openssl rsa -in key.pem -inform pem -pubout > key.pub

    writing RSA key

==> cat key.pub


    -----BEGIN PUBLIC KEY-----
    MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAq6+k7R+C9pnwk8tXu82F
    CG3aMEw8piWUS+oucUUMymKOpNH+zEriyBj9rSNf5qPwtFepb+k4yuRCr+1zshU6
    BBpA9udATGlTJZXKnURuBVbPe7nWV59YYQEAwf7+fhCWjyzYFjM5njdPw5t3Ablw
    6hDHcYEpGSVQJXES9SwxjWEmOQlsmM14AKpqzwxcJweJDNEGWpGSb28uJEbwmaN3
    KezSOE2Rqvu2f149tOs+e5YOOqmPSFsL5Fthut1lo+kzFJ6GlAHjaYPweJw+KDK4
    WBm6LPKbLSp75+xYHrT8WjkkrgqOJhXOGfCw17DDkAM4Zkpbuqjx1tOUmP28TWfC
    YQIDAQAB
    -----END PUBLIC KEY-----


##	Generate ECC key pair

1. Generate ECC key pair
==> openssl ecparam -name prime256v1 -genkey -noout -out eckey.pem

==>  ls -al

    total 20
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  4 10:04 .
    drwxr-xr-x 4 cybersecurity cybersecurity 4096 Jun  4 09:16 ..
    -rw------- 1 cybersecurity cybersecurity  227 Jun  4 10:04 eckey.pem
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  4 09:39 key.pem
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  4 10:02 key.pub

==> cat eckey.pem

    -----BEGIN EC PRIVATE KEY-----
    MHcCAQEEIIb7hLwl5YPa/+j0IltBXEA1a9O/NgUtc6UeoD7tlEuKoAoGCCqGSM49
    AwEHoUQDQgAEB3Z84qs6VIVKiUcaiEMaL+PtZSFkVfwY7qpO42uNvbfrG4nTE/nK
    QoNBtSDWHrdzYD7ZkPN9fPULdVBvwQ4t2w==
    -----END EC PRIVATE KEY-----

==> openssl ec -inform pem -in eckey.pem -pubout > eckey.pub

    read EC key
    writing EC key

==> cat eckey.pub

    -----BEGIN PUBLIC KEY-----
    MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEB3Z84qs6VIVKiUcaiEMaL+PtZSFk
    VfwY7qpO42uNvbfrG4nTE/nKQoNBtSDWHrdzYD7ZkPN9fPULdVBvwQ4t2w==
    -----END PUBLIC KEY-----

##	PEM vs DER and other formats
Different encoding types

  * Distinguished Encoding Rules: A binary format to encode ASN.1 data structures.
Decoders: https://lapo.it/asn1js//


  * Privacy Enhanced Mail
Base64 encoded file, making it easy to send the data by different methods, such as emails.

While base64 is a great format to send binary information as text, it
is also used by malwares for encoding javascript or other code. This
code in ASCII format can then can be converted to binary on the device
and run as binary code.


##	Sign and verify using keys
### Sign

==> cat textfile

    This is a test file"

==> openssl dgst -sha256 textfile

    SHA256(textfile)= 20cc6041b36a9e2471c3712aa139ed7633d4fd5ff91fcbbbf4c5ab0f3e6d406c

==> openssl dgst -sha256 -sign key.pem textfile

    �ͮ���ijG4�[���%                                                                                                                                                                                      

==> openssl dgst -sha256 -sign key.pem -out textfile.sha256.sign textfile

This creates a file with the signature, named textfile.sha256.

### Verify Good File

==> openssl dgst -sha256 -verify key.pub -signature textfile.sha256.sign textfile

    Verified OK

### Verify Bad File

==> cp textfile textfile.bad
==> echo "xx" >> textfile.bad
==> cat textfile.bad

    This is a test file"
    xx

==> cat textfile

    This is a test file"

 ==> openssl dgst -sha256 -verify key.pub -signature textfile.sha256.sign textfile.bad

    Verification Failure

1. Signature is a binary. Convert to text format for easy transportation.

==> base64 textfile.sha256.sign

    UuTfZRlswom7eG6qB8o5zUiBg5DyURdqAW/lAUMQjnk0Eubuf1ZOdvA+j6g7qf1JLzFJ1H906VRX
    jmN+LiSUvKrv3W/kwQBVsDw1+I0gXSK3J3IOH2yG9KkAzE/0SoQNc8fDwrmU68NVB78Bwdil8e44
    Jv5qO0215wGEB02VDnAP4tfpmmD6iBzUGdJdzxUPifHEOr9ngsWeMOsScPwJQFHV6c2IAMdYWrQi
    GhlhmW8rKQRkR9/keLU4xtn+8XH/AtxFwkRUY0HTpo2RJyOAsVmsZttiTTGS0m1jWH+bf0HComn6
    tjwz4wYdeFuAfmcNic2ulIXgaRlqRzTwW/TyzQ==

Hexdump of signature

==> hexdump textfile.sha256.sign

    0000000 e452 65df 6c19 89c2 78bb aa6e ca07 cd39
    0000010 8148 9083 51f2 6a17 6f01 01e5 1043 798e
    0000020 1234 eee6 567f 764e 3ef0 a88f a93b 49fd
    0000030 312f d449 747f 54e9 8e57 7e63 242e bc94
    0000040 efaa 6fdd c1e4 5500 3cb0 f835 208d 225d
    0000050 27b7 0e72 6c1f f486 00a9 4fcc 4af4 0d84
    0000060 c773 c2c3 94b9 c3eb 0755 01bf d8c1 f1a5
    0000070 38ee fe26 3b6a b54d 01e7 0784 954d 700e
    0000080 e20f e9d7 609a 88fa d41c d219 cf5d 0f15
    0000090 f189 3ac4 67bf c582 309e 12eb fc70 4009
    00000a0 d551 cde9 0088 58c7 b45a 1a22 6119 6f99
    00000b0 292b 6404 df47 78e4 38b5 d9c6 f1fe ff71
    00000c0 dc02 c245 5444 4163 a6d3 918d 2327 b180
    00000d0 ac59 db66 4d62 9231 6dd2 5863 9b7f 417f
    00000e0 a2c2 fa69 3cb6 e333 1d06 5b78 7e80 0d67
    00000f0 cd89 94ae e085 1969 476a f034 f45b cdf2
    0000100

##	Encrypt and Decrypt using keys

Encryption is done using public key by anyone wanting to send
confidential data to a receiver. Receiver will use the private key to
decrypt data.

### Encryption

==> openssl rsautl -in textfile -out textfile.enc -pubin -inkey key.pub -encrypt

==> ls -al

    total 40
    drwxr-xr-x 2 cybersecurity cybersecurity 4096 Jun  4 10:46 .
    drwxr-xr-x 4 cybersecurity cybersecurity 4096 Jun  4 09:16 ..
    -rw------- 1 cybersecurity cybersecurity  227 Jun  4 10:04 eckey.pem
    -rw-r--r-- 1 cybersecurity cybersecurity  178 Jun  4 10:05 eckey.pub
    -rw------- 1 cybersecurity cybersecurity 1675 Jun  4 09:39 key.pem
    -rw-r--r-- 1 cybersecurity cybersecurity  451 Jun  4 10:02 key.pub
    -rw-r--r-- 1 cybersecurity cybersecurity   21 Jun  4 10:11 textfile
    -rw-r--r-- 1 cybersecurity cybersecurity   24 Jun  4 10:25 textfile.bad
    -rw-r--r-- 1 cybersecurity cybersecurity  256 Jun  4 10:46 textfile.enc
    -rw-r--r-- 1 cybersecurity cybersecurity  256 Jun  4 10:15 textfile.sha256.sign

==> cat textfile.enc

    ��DG��v��Hg�i^8�y
    �Ht���#P����щ��r�3��w1[��?�V �El[q���4�+&��Y@�gd�.�ɶ�h�Q�6�<��
                                                                  ��	��\��~�b<��\b��*�3�%J�s�qj��&�(�ʋ:�GX��R
                                                                                                                    )@p����8�A��TW	��o��ږ�I���aT<$L@��}���,qM�2N�����%��/8��%UT��!�f��&
    ��i�b>�ԞԎ܆��#&�%                                                                                                                                                                                    ==> base64 textfile.enc

    p3sI4ZIDREcPi7J2i75IZ75pXjjzgHkKjwVIdKmcvSNQ4K7YzdXRianOcvKXM62RdzEYW4GoP59W
    IM1FbFtxzOHjNJArJgEPlhfKWUCHZ2QcrhEu7Mm272iUUcsHNpA8/4ALnqgHCfodgFyt534DimI8
    l69cG0dirgXsEyr1M6MlSgDkkHO2E3FqxsgmuxQo4YrKizqRFUdYjB3VUgwpQHC3h9YW4ziJQcPl
    VFcfCY23b/n/2pb4ScjH5GFUPCRMQPYWhn2Lgf4scU3oMk7n4JuM6wgTsiWiuy84mbwlVVSmmBIh
    l2bOxCYKgOyXaddiPoPUnh3UjtyGlhvP6iMm/g==

### Decryption

==> openssl rsautl -in textfile.enc -inkey key.pem -decrypt        

    This is a test file"
