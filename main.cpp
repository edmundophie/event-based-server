#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <err.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <string.h>

#include <event.h>
#include <evhttp.h>
#include <fstream>
using namespace std;


int port=8080;
string html_dir="html/";

void generic_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *buf;
    const char *uri = evhttp_request_get_uri(req);
    struct evhttp_uri *decoded = NULL;
    const char *path;
    struct stat st;
    int fd = -1;
    const char* filepath;

    decoded = evhttp_uri_parse(uri);
    
    if (!decoded) {
        printf("It's not a good URI. Sending BADREQUEST\n");
        evhttp_send_error(req, HTTP_BADREQUEST, 0);
        return;
    }

    path = evhttp_uri_get_path(decoded);
    
    if (!path) path = "/";
    if(strcmp(path, "/")==0) { 
        filepath = (html_dir + "index.html").c_str();
    } else {
        string temp = path;
        temp = html_dir + temp.substr(1, strlen(path)-1);
        filepath = temp.c_str();
    }

    cout << "path: " << path << endl;
    cout << "filepath: " << filepath << endl;

    buf = evbuffer_new();

    if (buf == NULL)
        err(1, "failed to create response buffer");

    if ((fd = open(filepath, O_RDONLY)) < 0) {
        perror("open");
        evhttp_send_error(req, 404, "Document was not found");
        if (fd>=0)
            close(fd);
    }

    if (stat(filepath, &st)<0) {
        evhttp_send_error(req, 404, "Document was not found");
        if (fd>=0)
            close(fd);
    }

    const char *type = "text/html";
    evhttp_add_header(evhttp_request_get_output_headers(req), "Content-Type", type);
    evbuffer_add_file(buf, fd, 0, st.st_size);
    // evbuffer_add_printf(buf, "Requested: %sn", evhttp_request_uri(req));
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

int main(int argc, char **argv)
{
	ifstream myfile ("server.config");
	string line;
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
		  if(line.substr(0,4)=="port") 
		  	port=stoi(line.substr(5, line.length()-5));
		  if(line.substr(0,11)=="html folder") 
		  	html_dir=line.substr(12, line.length()-12);
		}
		myfile.close();
	}

	cout << "port: " << port << endl;
	cout << "html_dir: " << html_dir << endl;

    struct evhttp *httpd;
    struct event_base *base;
    
    event_init();
    
    httpd = evhttp_start("127.0.0.1", port);

    /* Set a callback for requests to "/specific". */
    /* evhttp_set_cb(httpd, "/specific", another_handler, NULL); */

    /* Set a callback for all other requests. */
    evhttp_set_gencb(httpd, generic_handler, NULL);

    event_dispatch();
    evhttp_free(httpd);
    
    return 0;
}