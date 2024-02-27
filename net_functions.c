#include "net_functions.h"


int socket_wrapper(int domain, int type, int protocol)
{
    int res = socket(domain, type, protocol);
    if (res == -1) {
        perror("socket fail");
        exit(EXIT_FAILURE);
    }
    return res;
}

void bind_wrapper(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = bind(sockfd, addr, addrlen);
    if (res == -1) {
        perror("bind fail");
        exit(EXIT_FAILURE);
    }
}

void listen_wrapper(int sockfd, int backlog)
{
    int res = listen(sockfd, backlog);
    if (res == -1) {
        perror("listen fail");
        exit(EXIT_FAILURE);
    }
}

int accept_wrapper(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int res = accept(sockfd, addr, addrlen);
    if (res == -1) {
        perror("accept fail");
        exit(EXIT_FAILURE);
    }
    return res;
}

int connect_wrapper(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = connect(sockfd, addr, addrlen);
    /*
    if (res == -1) {
        perror("connect fail");
        exit(EXIT_FAILURE);
    }
    */
    return res;
}

void inet_pton_wrapper(int af, const char *src, void *dst)
{
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("inet_pton fail: 0");
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton fail: -1");
        exit(EXIT_FAILURE);
    }
}

int write_wrapper(int sockfd, Fig_send_t* figtosend, size_t len)
{
    char* buf = (char*)figtosend;
    int bytes_sended;
    bytes_sended = send(sockfd, buf, len, 0);
    return bytes_sended;
}

int write_seed(int sockfd, char seed, size_t len)
{
    int bytes_sended;
    bytes_sended = send(sockfd, &seed, len, 0);
    return bytes_sended;
}

int read_seed(int sockfd, char* seed, size_t len)
{
    int received_bytes;
    received_bytes = recv(sockfd, seed, len, 0);
    return received_bytes;
}


int read_wrapper(int sockfd, Fig_send_t** figtoget, size_t len)
{
    int cnt;
    int received_bytes;
    char* buf = (char*)malloc(sizeof(char)*len);

    cnt = len;
    while(cnt > 0)
    {
        received_bytes = recv(sockfd, buf, cnt, 0);
        if (received_bytes < 0)
        {
            return -1;
        }
        if (received_bytes == 0)
        {
            return len - cnt;
        }
        cnt -= received_bytes;
        buf += received_bytes;
    }
    *figtoget = (Fig_send_t*)buf;
    return len;
}

int read_wrapper2(int sockfd, Fig_send_t** figtoget, size_t len)
{
    int received_bytes;
    char* buf = (char*)malloc(sizeof(char)*len);

    received_bytes = recv(sockfd, buf, len, 0);
    *figtoget = (Fig_send_t*)buf;
    return len;
}

int read_wrapper3(int sockfd, Fig_send_t** figtoget, size_t len)
{
    int received_bytes;
    char* buf = (char*)malloc(sizeof(char)*len);
    int ptr = 0;
    int cnt = len;

    while(cnt > 0)
    {
        received_bytes = recv(sockfd, &buf[ptr], 1, 0);
        if (received_bytes < 0)
        {
            return -1;
        }
        if (received_bytes == 0)
        {
            return 0;
        }
        cnt -= received_bytes;
        ptr++;
    }
    *figtoget = (Fig_send_t*)buf;
    return len;
}



