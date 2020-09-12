#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <poll.h>

#include <tls.h>

int main(int argc, char **argv) {

	struct tls_config *config = NULL;
	struct tls *tls = NULL;
	unsigned int protocols = 0;
	struct sockaddr_in server, client;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	int opt = 1;
	int b;
	struct tls *tls2 = NULL;
	ssize_t outlen = 0;
	char bufs[1000], bufc[1000];
	int sc;
	char *msg = "HELLO TLS CLIENT\n";

	char *ciphers = "ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384";

	struct pollfd pfd[2];

	if(tls_init() < 0) {
		printf("tls_init error\n");
		exit(1);
	}

	config = tls_config_new();
	if(config == NULL) {
		printf("tls_config_new error\n");
		exit(1);
	}

	tls = tls_server();
	if(tls == NULL) {
		printf("tls_server error\n");
		exit(1);
	}


	if(tls_config_parse_protocols(&protocols, "secure") < 0) {
		printf("tls_config_parse_protocols error\n");
		exit(1);
	}

	tls_config_set_protocols(config, protocols);

	if(tls_config_set_ciphers(config, ciphers) < 0) {
		printf("tls_config_set_ciphers error\n");
		exit(1);
	}

	if(tls_config_set_key_file(config, "sneha.pem") < 0) {
		printf("tls_config_set_key_file error\n");
		exit(1);
	}

	if(tls_config_set_cert_file(config, "snehasigncsr.pem") < 0) {
		printf("tls_config_set_cert_file error\n");
		exit(1);
	}

	if(tls_configure(tls, config) < 0) {
		printf("tls_configure error: %s\n", tls_error(tls));
		exit(1);
	}


	bzero(&server, sizeof(server));
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(9000);
	server.sin_family = AF_INET;

	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, 4);
	b = bind(sock, (struct sockaddr *) &server, sizeof(server));
	if(b < 0) {
		printf("erro bind\n");
		exit(1);
	}
	listen(sock, 10);

	socklen_t client_size = sizeof(client);

	sc = accept(sock, (struct sockaddr *) &client, &client_size);

	if(tls_accept_socket(tls, &tls2, sc) < 0) {
		printf("tls_accept_socket error\n");
		exit(1);
	}

	tls_write(tls2, msg, strlen(msg));

	pfd[0].fd = 0;
	pfd[0].events = POLLIN;
	pfd[1].fd = sc;
	pfd[1].events = POLLIN;

	while(bufc[0] != ':' && bufc[1] != 'q') {

		poll(pfd, 2, -1);

		bzero(bufs, 1000);
		bzero(bufc, 1000);

		if(pfd[0].revents & POLLIN) {
			int q = read(0, bufc, 1000);
			tls_write(tls2, bufc, q);
		}

		if(pfd[1].revents & POLLIN) {
			if((outlen = tls_read(tls2, bufs, 1000)) <= 0) break;
			printf("Mensagem (%lu): %s\n", outlen, bufs);
		}


	}

	tls_close(tls);
	tls_free(tls);
	tls_config_free(config);

	return 0;

}
