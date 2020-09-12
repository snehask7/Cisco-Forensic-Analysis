#CC=	gcc
CFLAGS=	-Wall -g -O0 -I/opt/libressl/include
LDFLAGS=	-L/opt/libressl/lib -ltls -lssl -lcrypto
all:
	${CC} server.c -o server ${CFLAGS} ${LDFLAGS} 
	${CC} client.c -o client ${CFLAGS} ${LDFLAGS} 
