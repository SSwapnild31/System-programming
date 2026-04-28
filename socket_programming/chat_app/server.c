#include "header.h"
#define size 100

void* send_msg(void*);
void* recv_msg(void*);

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

    struct sockaddr_in server_id, client_id;
    server_id.sin_family = AF_INET;
    server_id.sin_port = htons(atoi(argv[1]));
    server_id.sin_addr.s_addr = inet_addr(argv[2]);

    socklen_t len = sizeof(server_id);

    if(bind(fd, (struct sockaddr*)&server_id, len) < 0){
        perror("bind");
        return 1;
    }

    if(listen(fd, 5) < 0){
        perror("listen");
        return 1;
    }

    printf(" waiting for connection...\n");

    int nfd = accept(fd, (struct sockaddr*)&client_id, &len);
    if(nfd < 0){
        perror("accept");
        close(fd);
        return 1;
    }
    
    printf("\n Connected with\n");
    printf("--------------------------\n");
    printf(" ip_addr : %s\n port_no : %d\n", inet_ntoa(client_id.sin_addr), ntohs(client_id.sin_port));
    printf("--------------------------\n");

    pthread_t sender, receiver;

    if(pthread_create(&sender, NULL, send_msg, &nfd) !=0){
        perror("pthread_create");
        close(fd);
        return 1;
    }

    if(pthread_create(&receiver, NULL, recv_msg, &nfd) !=0){
        perror("pthread_create");
        close(fd);
        return 1;
    }

    pthread_join(sender, NULL);
    pthread_join(receiver, NULL);

    close(nfd);
    close(fd);

    return 0;
}

void* send_msg(void *fd){
    
    char msg[size];
    while(1){
        printf(" you  ->  ");
        
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';

        send(*(int*)fd, msg, strlen(msg)+1, 0);

        if(strcmp(msg, "bye") == 0) break;
    }
    return NULL;
}

void* recv_msg(void *fd){
    
    char msg[size];
    while(1){
        int n = recv(*(int*)fd, msg, sizeof(msg), 0);
        
        if(n <= 0) continue;

        printf("\n friend  ->  %s\n",msg);

        if(strcmp(msg, "bye") == 0) break;
    }
    return NULL;
}