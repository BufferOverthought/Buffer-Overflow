// SafePass Manager Demo - Vulnerable Backend (for educational use only)
//
// Simulates a classic stack-based buffer overflow vulnerability
// Use at your own risk. DO NOT deploy in production environments.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

// Secret function: Called only if stack is overwritten correctly
void secret_function() {
    // In a real CTF, this could print a flag or open a shell
    system("/bin/sh");
}

// Vulnerable authentication function
void handle_client(int client_sock) {
    char username[32];
    char password[32];
    char welcome_msg[] =
        "=== Welcome to SafePass Manager (Demo) ===\n"
        "This is a simple password manager.\n"
        "For demo purposes, use the credentials: admin / admin123\n\n";

    send(client_sock, welcome_msg, strlen(welcome_msg), 0);

    // Ask for username
    send(client_sock, "Username: ", 10, 0);
    // VULNERABILITY: Oversized recv, stack overflow possible here!
    recv(client_sock, username, 200, 0);

    // Ask for password
    send(client_sock, "Password: ", 10, 0);
    // VULNERABILITY: Oversized recv, stack overflow possible here!
    recv(client_sock, password, 200, 0);

    // Simple check (demo only)
    if (strncmp(username, "admin", 5) == 0 && strncmp(password, "admin123", 8) == 0) {
        send(client_sock, "Authentication successful!\n", 27, 0);
    } else {
        send(client_sock, "Invalid credentials.\n", 21, 0);
    }

    send(client_sock, "Goodbye!\n", 9, 0);
    close(client_sock);
}

int main() {
    int server_fd, client_sock;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind and listen
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("SafePass Manager backend running on port 8080...\n");

    // Main server loop: Handle one client at a time
    while (1) {
        client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }
        handle_client(client_sock);
    }
    return 0;
}
