# Table of Contents
-   [Running a webserver with SSL](#running-a-webserver-with-ssl)
    -   [Start nginx](#start-nginx)
    -   [Copy keys into an accessible area. in this case we are choosing
        ../server](#copy-keys-into-an-accessible-area-in-this-case-we-are-choosing-server)
    -   [Modify /etc/nginx/nginx.conf](#modify-etcnginxnginxconf)
    -   [Verify nginx configuration and reload
        nginx](#verify-nginx-configuration-and-reload-nginx)
    -   [Green Lock Or Not!!](#green-lock-or-not)


# Running a webserver with SSL

Now we will use our new certificate to run a HTTPS server.

## Start nginx

Check if nginx is running

==> service nginx status

    ● nginx.service - A high performance web server and a reverse proxy server
       Loaded: loaded (/lib/systemd/system/nginx.service; enabled; vendor preset: enabled)
       Active: inactive (dead) since Sat 2019-07-06 14:39:16 IST; 6min ago
         Docs: man:nginx(8)
      Process: 7942 ExecStartPre=/usr/sbin/nginx -t -q -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
      Process: 7954 ExecStart=/usr/sbin/nginx -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
      Process: 8317 ExecStop=/sbin/start-stop-daemon --quiet --stop --retry QUIT/5 --pidfile /run/nginx.pid (code=exited, status=0/SUCCESS)
     Main PID: 7956 (code=exited, status=0/SUCCESS)


==> sudo service nginx start

==> service nginx status

    ● nginx.service - A high performance web server and a reverse proxy server
       Loaded: loaded (/lib/systemd/system/nginx.service; enabled; vendor preset: enabled)
       Active: active (running) since Sat 2019-07-06 14:47:25 IST; 3s ago
         Docs: man:nginx(8)
      Process: 8630 ExecStartPre=/usr/sbin/nginx -t -q -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
      Process: 8640 ExecStart=/usr/sbin/nginx -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
     Main PID: 8644 (nginx)
        Tasks: 2 (limit: 4915)
       Memory: 2.6M
       CGroup: /system.slice/nginx.service
               ├─8644 nginx: master process /usr/sbin/nginx -g daemon on; master_process on;
               └─8645 nginx: worker process


Open up Firefox and go to http://localhost. You should see the basic nginx page.

Go to https://localhost. You should not see any website there.

## Copy keys into an accessible area. in this case we are choosing ../server

==> mkdir ../server/

==> cp serverkey.key server-example.crt ../server/

Note that the serverkey.key and server-example.crt come from the previous worksheet on signed server keys and certificates.

==> chmod 400 ../server/serverkey.key

Concatenate the intermediate sub-ca.crt into the server certificate.

==> cat root-ca/sub-ca.crt >> ../server/server-example.crt

==> ls -al ../server

    total 20
    drwxr-xr-x  2 cybersecurity cybersecurity 4096 Jul  6 13:47 .
    drwxr-xr-x 14 cybersecurity cybersecurity 4096 Jul  6 14:06 ..
    -rw-r--r--  1 cybersecurity cybersecurity 6445 Jul  6 13:47 server-example.crt
    -r--------  1 cybersecurity cybersecurity 1679 Jul  6 13:47 serverkey.key


## Modify /etc/nginx/nginx.conf

We need to now provide the location of the key and certificate and start
HTTPS server at port 443. Make the following changes in
/etc/nginx/nginx.conf.

First back up nginx.conf

==> sudo cp /etc/nginx/nginx.conf ./nginx.conf

==> sudo vi /etc/nginx/nginx.conf

Add the following lines in the "http {..}" block, using the diff format
below.

* SSL settings: The below lines set up the location of the key and certificate.

        # SSL Settings
             	##

            +        ssl_certificate     <path>/server/server-example.crt;
            +        ssl_certificate_key <path>/server/serverkey.key;
            +        ssl_ciphers         EECDH+AESGCM:EDH+AESGCM:AES256+EECDH:AES256+EDH;
             	ssl_protocols TLSv1 TLSv1.1 TLSv1.2 TLSv1.3; # Dropping SSLv3, ref: POODLE
             	ssl_prefer_server_ciphers on;

* Start HTTPS server: The below lines start SSL server at port 443 and
  provide a servername

        include /etc/nginx/conf.d/*.conf;
             	include /etc/nginx/sites-enabled/*;

            +	server {
            +    		listen              443 ssl default_server;
            +    		listen              [::]:443 ssl default_server ;
            +	}
             }

## Verify nginx configuration and reload nginx

Verify configuration

==> sudo nginx -t

    nginx: the configuration file /etc/nginx/nginx.conf syntax is ok
    nginx: configuration file /etc/nginx/nginx.conf test is successful


==> sudo nginx -s reload

Now go to http://localhost and verify that the website still works.

Now go to https://localhost. You will notice that Firefox gives an
error. Why?

## Green Lock Or Not!!

Click on Advanced. Now open the certificate shown. Verify that the
certificate matches the server-example.crt info.

Unless this certificate is signed by a chain of certificates going
back to mozilla's trust store, Firefox will issue an error.

You can now add an exception for this certificate. Going forward
firefox will no longer give an error for this certificate. But the
lock is still not green. The lock shows an error. Click on the lock
for more information.

The lock tells you that the connection is not secure and gives you the
opportunity to remove the exception you added.
