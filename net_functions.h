#ifndef NET_FUNCTIONS_H_INCLUDED
#define NET_FUNCTIONS_H_INCLUDED

#include "constants.h"
#include "queue_fig.h"

int socket_wrapper(int domain, int type, int protocol);
void bind_wrapper(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void listen_wrapper(int sockfd, int backlog);
int accept_wrapper(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int connect_wrapper(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void inet_pton_wrapper(int af, const char *src, void *dst);
int write_wrapper(int sockfd, Fig_send_t* figtosend, size_t len);
int write_seed(int sockfd, char seed, size_t len);
int read_seed(int sockfd, char* seed, size_t len);
int read_wrapper(int sockfd, Fig_send_t** figtosend, size_t len);
int read_wrapper2(int sockfd, Fig_send_t** figtosend, size_t len);
int read_wrapper3(int sockfd, Fig_send_t** figtoget, size_t len);

#endif // NET_FUNCTIONS_H_INCLUDED
