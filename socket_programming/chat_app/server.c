#include "header.h"

int main(int argc, char **argv)
{
    if(argc != 3){
        printf("usage : ./a.out port_no ip_addr\n");
        return 1;
    }

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0){
        perror("socket");
        return 1;
    }
    perror("socket");

    struct sockaddr_in server_id, client_id;
    server_id.sin_family = AF_INET;
    server_id.sin_port = htons(atoi(argv[1]));
    server_id.sin_addr.s_addr = inet_addr(argv[2]);

    int len = sizeof(server_id);

    if(bind(fd, (struct sockaddr*)&server_id, len) < 0){
        perror("bind");
        return 1;
    }
    perror("bind");

    if(listen(fd, 5) < 0){
        perror("listen");
        return 1;
    }
    perror("listen");

    printf("\nwaiting for connection...\n");

    int nfd = accept(fd, (struct sockaddr*)&client_id, &len);
    if(nfd < 0){
        perror("accept");
        close(fd);
        return 1;
    }
    perror("accept");

    return 0;
}