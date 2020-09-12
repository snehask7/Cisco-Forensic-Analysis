/* libtls_util.c */

#include <stdio.h>
#include <time.h>
#include <err.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <tls.h>

int
setup_socket(int port)
{
	int sock, sock_ret;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return(-1);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) != 0)
		return(-1);

	if (listen(sock, 3) != 0)
		return(-1);

	len = sizeof(client);
	if ((sock_ret = accept(sock, (struct sockaddr *) &client, &len)) == -1)
		return(-1);

	return sock_ret;
}

int
dump_session_info(struct tls *ctx, const char *name)
{
	const char *p;
	time_t time;
	struct tm *tm;

	if (tls_peer_cert_provided(ctx) == 1)
		printf("tls_peer_cert_provided: YES\n");
	else {
		printf("tls_peer_cert_provided: NO\n");
		return(-1);
	}
	
	if (tls_peer_cert_contains_name(ctx, name) == 1)
		printf("tls_peer_cert_contains_name: %s\n", name);
	else
		printf("tls_peer_cert_contains_name: invalid\n");

	if ((p = tls_peer_cert_issuer(ctx)) == NULL)
		err(1, "tls_peer_cert_issuer: %s", tls_error(ctx));
	printf("tls_peer_cert_issuer: %s\n", p);

	if ((p = tls_peer_cert_subject(ctx)) == NULL)
		err(1, "tls_peer_cert_subject: %s", tls_error(ctx));
	printf("tls_peer_cert_subject: %s\n", p);

	if ((p = tls_peer_cert_hash(ctx)) == NULL)
		err(1, "tls_peer_cert_hash: %s", tls_error(ctx));
	printf("tls_peer_cert_hash: %s\n", p);

	if ((time = tls_peer_cert_notbefore(ctx)) < 0)
		err(1, "tls_peer_cert_notbefore: %s", tls_error(ctx));
	tm = localtime(&time);
	printf("tls_peer_cert_notbefore: %04d/%02d/%02d %02d:%02d:%02d\n",
		1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);

	if ((time = tls_peer_cert_notafter(ctx)) < 0)
		err(1, "tls_peer_cert_notafter: %s", tls_error(ctx));
	tm = localtime(&time);
	printf("tls_peer_cert_notafter: %04d/%02d/%02d %02d:%02d:%02d\n",
		1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);

	if ((p = tls_conn_version(ctx)) == NULL)
		err(1, "tls_conn_version: %s", tls_error(ctx));
	printf("tls_conn_version: %s\n", p);

	if ((p = tls_conn_cipher(ctx)) == NULL)
		err(1, "tls_conn_cipher: %s", tls_error(ctx));
	printf("tls_conn_cipher: %s\n", p);

	return(0);
}
