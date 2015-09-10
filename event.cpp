
#include <iostream>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <err.h>

#include <evhttp.h>
using namespace std;

void dump_request_cb(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf;
    buf = evbuffer_new();
    if (buf == NULL)
        err(1, "failed to create response buffer");
    evbuffer_add_printf(buf, "Requested: %sn", evhttp_request_uri(req));
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

int main() {
			
	struct event_base *base;
	struct evhttp *http;
	struct evhttp_bound_socket *handle;
	unsigned int port = 8080;

	// create an event base
	// event base is structure to hold state information
	base = event_base_new();

	if (!base) {
		fprintf(stderr, "Couldn't create an event_base: exiting\n");
		return 1;
	}

	// create new http server
	http = evhttp_new(base);

	if(!http) {
		fprintf(stderr, "couldn't create evhttp. Exiting.\n");
		return 1;
	}

	// evhttp_set_cb(http, "/dump", dump_request_cb, NULL);

	// set default arbitrary path callback
	evhttp_set_gencb(http, dump_request_cb, NULL);

	// bind https server to address and port
	// return a reference to the socket 
	handle = evhttp_bind_socket_with_handle(http, "127.0.0.1", port);
	
	if (!handle) {
		fprintf(stderr, "couldn't bind to port %d. Exiting.\n",
		    (int)port);
		return 1;
	}

}