/* libtls_server.c */

#include <stdio.h>
#include <errno.h>
#include <err.h>
#include <tls.h>

int
main(int argc, char *argv[])
{
	struct tls_config *cfg = NULL;
	struct tls *ctx = NULL, *cctx = NULL;
	uint8_t *mem;
	size_t mem_len;
	int clfd;
	ssize_t readlen;
	unsigned char buf[BUFSIZ];

	/*
	** initialize libtls
	*/

	if (tls_init() != 0)
		err(1, "tls_init:");

	/*
	** configure libtls
	*/

	if ((cfg = tls_config_new()) == NULL)
		err(1, "tls_config_new:");

	/* set root certificate (CA) */
	if ((mem = tls_load_file("test_ca.pem", &mem_len, NULL)) == NULL)
		err(1, "tls_load_file(ca):");
	if (tls_config_set_ca_mem(cfg, mem, mem_len) != 0)
		err(1, "tls_config_set_ca_mem:");

	/* set server certificate */
	if ((mem = tls_load_file("test_server_cert.pem", &mem_len, NULL)) == NULL)
		err(1, "tls_load_file(server):");
	if (tls_config_set_cert_mem(cfg, mem, mem_len) != 0)
		err(1, "tls_config_set_cert_mem:");
	
	/* set server private key */
	if ((mem = tls_load_file("test_server_key.pem", &mem_len, "test-server-pass")) == NULL)
		err(1, "tls_load_file(serverkey):");
	if (tls_config_set_key_mem(cfg, mem, mem_len) != 0)
		err(1, "tls_config_set_key_mem:");
	
	/*
	** initiate server context
	*/

	if ((ctx = tls_server()) == NULL)
		err(1, "tls_server:");

	/*
	** apply config to context
	*/

	if (tls_configure(ctx, cfg) != 0)
		err(1, "tls_configure: %s", tls_error(ctx));

	/*
	** create and accept socket
	*/

	printf("setting up socket ...\n");
	if ((clfd = setup_socket(12345)) < 0)
		err(1, "setup_socket: %d", errno);

	printf("accept socket ...\n");
	if (tls_accept_socket(ctx, &cctx, clfd) != 0)
		err(1, "tls_accept_socket: %s", tls_error(ctx));

	/*
	** receive message from client
	*/

	printf("waiting message from client ...\n");
	if((readlen = tls_read(cctx, buf, sizeof(buf))) < 0)
		err(1, "tls_read: %s", tls_error(cctx));

	printf("received message: [%*.*s]\n", readlen, readlen, buf);

	/*
	** clean up all
	*/

	if (tls_close(cctx) != 0)
		err(1, "tls_close: %s", tls_error(cctx));
	tls_free(cctx);
	tls_free(ctx);
	tls_config_free(cfg);

	return(0);
}
