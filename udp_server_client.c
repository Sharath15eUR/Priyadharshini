//server side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define MAXLINE 1024

int main() {
    int server_socket;
    char buffer[MAXLINE];
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d\n", PORT);

    while (1) {
        int n = recvfrom(server_socket, (char *)buffer, MAXLINE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        sendto(server_socket, (const char *)"Hello from udp_server", strlen("Hello from udp_server"), 0, (const struct sockaddr *)&client_addr, client_addr_len);
        printf("udp_server: Hello message sent to client\n");
    }

    close(server_socket);

    return 0;
}

//client side
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define MAXLINE 1024

int main() {
    int client_socket;
    char buffer[MAXLINE];
    struct sockaddr_in server_addr;

    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int n, len;
    printf("Enter message to send to udp_server: ");
    fgets(buffer, MAXLINE, stdin);

    sendto(client_socket, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("udp_client: Message sent to udp_server\n");

    n = recvfrom(client_socket, (char *)buffer, MAXLINE, 0, NULL, NULL);
    buffer[n] = '\0';
    printf("udp_server: %s\n", buffer);

    close(client_socket);

    return 0;
}

