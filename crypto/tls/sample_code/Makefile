# Makefile

all :: libtls_server libtls_client

libtls_server : libtls_server.o libtls_util.o
	$(CC) -g -o $@ $^ -I/opt/libressl/include -L/opt/libressl/lib -ltls -lssl -lcrypto

libtls_client : libtls_client.o libtls_util.o
	$(CC) -g -o $@ $^ -I/opt/libressl/include -L/opt/libressl/lib -ltls -lssl -lcrypto

.c.o :
	$(CC) -g -c -o $@ $< -I/opt/libressl/include

clean :
	/bin/rm -f libtls_server libtls_client libtls_*.o
