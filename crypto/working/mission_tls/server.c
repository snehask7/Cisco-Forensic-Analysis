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

	if(tls_config_set_key_file(config, "MIIEpAIBAAKCAQEAu/WTbw0WllQAgUkwtoAJLeaAUNBdWh5QTQWNi7T2hdNOcS+6
vNddjZLgofjV7uOpZoT+L37BgOjTmfuiSqz7SC6XB3ib/qyBEloVDPjG+9TI0uYn
AHMF/jIDd/KiCUdXPfZPOPH/HiGdmIn7Lb2qui9AzYcQacmPAcH3ZTTjZF8CyjeY
624Q/IP8EZQsKYkAEYl9XX/Xn3SGwZmTaxKQBX9ak3XiyafP9yn3Ruc3PxgYmZjy
V0ltFmF783JliCfFQPAGRBItjvOIIBeKowF/MpbkMBo73F8GNABMDBh87ilewguP
73z/Q51phTwbFN+YjlAUStcIvxz/G1z+ZXOMAQIDAQABAoIBAA/CdH0wNL+gBXbR
ozL6I0rk88dS4TDoL8V1fLvFDZKE+CPHY7nnuOFg+lK6YX2pOw/sgL+Muj7Lxso3
bhEi1eLkfSdUNogxAJWAVhmDVnPREJGWWJjSDCOXH/FTt8BdafQ5DcVxjPmCygr7
LsNUDteTlLRm6bpk+wejstGakKJerA0rw8xItBKEAmiLAzzPp0SVMRJB89iG//to
c/PdPyinE4ktzHp7xsaNgcBVjknHCSvllMgoOXFvB31ZBZsIdVbQtGtrPHB62tWg
p8A1St83Vkt/tjPMOk2mVdJM9hhT1F2jRc22Nv+293p0VVcP6AFybXGBgjE4kJ9t
+sPiGY0CgYEA8q2zrCwtfH2cR/8b+KYeCPguhnxkHiI90waUMI80XHDABOouzvfk
7lvbi9Okp7jrTRDk4xl65zHwgBNVhbjEMoZMRk51B47mq6a1dEEtzowjOyb0Gych
whb9wDIj93pvy1wG62mtVYZW6tGxAi6p+Tvvvr2qbcg0c/c5LhOyMxMCgYEAxkbr
Nh7fqSumHH8LzTb46iL6Q6KWGx1jxnyGylDLSSfoRsmv6nubyDNy7i7a08J9uG+m
kGUgZXuwoFwDNOB70/xffN4Ch7VDWrRjGECDvduBbS2UjgabseFBL1hPuMdCpsHc
C0vO+kr/QNAoM2+V3p4/ZtaxKWVhHrtKDaKjUxsCgYEAvjJtcy9cpwk7hyHmJkbr
m1QIAtdTEFr94Xpygmx6OUkU9cUk0olvH3FW7Iv/rIQ9xrTK70J1FOYK/BYrHRbm
jkK7XQ74oefZ2gZaiLbc09j5c87f2rgcuSWT0yJ5Fekb3WJO+gplE3aqgHfAJ1mz
Vecny3KTNF+I3KqSYg6Fx4kCgYBH81hLbWywUPyYfqnjsD0nicXTYV6jPEkGsA2h
wSvjwi2R8oJ5zp07SyA7upkCGyPQGAQThf75lKcFqh4nxAZraLul7lJwuKBWe/sx
w8eKz+rpmY688zzwkdM7wQo8/WH8bYDSQJI9VZXHCUJtV+LExBwxz1q+sOFLa591
zz0BXQKBgQCuCCMqAtoLG8sDGeYWoRNuVeHr7KlnK+hU/a2JuAyw74zJufHAFKdt
wpxEOrZuvv87POtRkALLbSFW1RrhVI8tYfJvHJpsX2vHBLeLAxYgrSFkFotXYAx4
v8tpERBGObKCYGCyPnxzaXg8uw1v1Nwcn0wBKOrfAGvOFoahZcX9CQ==
") < 0) {
		printf("tls_config_set_key_file error\n");
		exit(1);
	}

	if(tls_config_set_cert_file(config, "MIICrjCCAZYCAQAwaTELMAkGA1UEBhMCSU4xEzARBgNVBAgMClRhbWlsIE5hZHUx
EDAOBgNVBAcMB0NoZW5uYWkxDDAKBgNVBAoMA1NTTjElMCMGCSqGSIb3DQEJARYW
c25laGFza2FubmFuQGdtYWlsLmNvbTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCC
AQoCggEBALv1k28NFpZUAIFJMLaACS3mgFDQXVoeUE0FjYu09oXTTnEvurzXXY2S
4KH41e7jqWaE/i9+wYDo05n7okqs+0gulwd4m/6sgRJaFQz4xvvUyNLmJwBzBf4y
A3fyoglHVz32Tzjx/x4hnZiJ+y29qrovQM2HEGnJjwHB92U042RfAso3mOtuEPyD
/BGULCmJABGJfV1/1590hsGZk2sSkAV/WpN14smnz/cp90bnNz8YGJmY8ldJbRZh
e/NyZYgnxUDwBkQSLY7ziCAXiqMBfzKW5DAaO9xfBjQATAwYfO4pXsILj+98/0Od
aYU8GxTfmI5QFErXCL8c/xtc/mVzjAECAwEAAaAAMA0GCSqGSIb3DQEBCwUAA4IB
AQC0u1lKF7VTLmi/eKSFwsgFx6CnqyrgnUxvvJX5hYz8ZKhXYc0HJlyr/5ksY7iN
2oZ63d+JrnjSyrVUopnw1O6QtXfsicVLgKfmK2HuuEg55xYVo58WYqkLoovxvUpC
V53HhTFR45MVANhyQ3H2rmjjEvhhZKuvUJei/Z/YaAfYybgsXTS5W0wJSmgBbrIg
SaECICp6BBNSPYMayA/rPY0yQe1op4gER1sxjTWlLiUW5zEJ9836SY/jbUrhFshg
Gx4dJq89o8kMN8tmLB9kcpWQM6WnkpARr5kHsWqmIot89AQyJZ1GqRz3n9kZkfwC
vZLZxugwNkuR9IkneGxwMt+L") < 0) {
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
