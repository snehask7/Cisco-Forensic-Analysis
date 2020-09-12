/* libtls_client.c */

#include <stdio.h>
#include <string.h>
#include <err.h>
#include <tls.h>

int
main(int argc, char *argv[])
{
	struct tls_config *cfg = NULL;
	struct tls *ctx = NULL;
	uint8_t *mem;
	size_t mem_len;
	ssize_t writelen;
	unsigned char buf[BUFSIZ] = "Hello libtls.";

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
	if (tls_config_set_ca_file(cfg, "test_ca.pem") != 0)
		err(1, "tls_config_set_ca_file:");

	/*
	** initiate client context
	*/

	if ((ctx = tls_client()) == NULL)
		err(1, "tls_client:");

	/*
	** apply config to context
	*/

	if (tls_configure(ctx, cfg) != 0)
		err(1, "tls_configure: %s", tls_error(ctx));

	/*
	** connect to server
	*/

	if (tls_connect(ctx, "localhost.test_dummy.com", "12345") != 0)
		err(1, "tls_connect: %s", tls_error(ctx));

	/*
	** send message to server
	*/

	if((writelen = tls_write(ctx, buf, strlen(buf))) < 0)
		err(1, "tls_write: %s", tls_error(ctx));

	printf("sent message: [%*.*s]\n", writelen, writelen, buf);

	/*
	** dump session informations
	*/

	dump_session_info(ctx, "localhost.test_dummy.com");

	/*
	** clean up all
	*/

	if (tls_close(ctx) != 0)
		err(1, "tls_close: %s", tls_error(ctx));
	tls_free(ctx);
	tls_config_free(cfg);

	return(0);
}
