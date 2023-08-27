#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define N 3
// Function to send a packet
void send_packet(int sockfd, char *packet, int seq_num) {
 // Send the packet
 int n = send(sockfd, packet, strlen(packet), 0);
 // Check if the send was successful
 if (n < 0) {
 perror("send");
 exit(1);
 }
 // Update the sequence number
 seq_num++;
}
// Function to receive a packet
char *receive_packet(int sockfd, int *seq_num) {
 // Receive the packet
 char *packet = malloc(BUFFER_SIZE);
 int n = recv(sockfd, packet, BUFFER_SIZE, 0);
 // Check if the receive was successful
 if (n < 0) {
 perror("recv");
 exit(1);
 }
 // Update the sequence number
 *seq_num = packet[0];
 // Return the packet
 return packet + 1;
}
int main(int argc, char *argv[]) {
 // Check if the user has provided the correct number of arguments
 if (argc != 2) {
 fprintf(stderr, "Usage: %s <port>\n", argv[0]);
 exit(1);
 }
 // Create a socket
 int sockfd = socket(AF_INET, SOCK_STREAM, 0);
 // Bind the socket to the specified port
 struct sockaddr_in addr;
 addr.sin_family = AF_INET;
 addr.sin_port = htons(atoi(argv[1]));
 addr.sin_addr.s_addr = INADDR_ANY;
 bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
 // Listen for incoming connections
 listen(sockfd, 1);
 // Accept an incoming connection
 int client_fd = accept(sockfd, NULL, NULL);
 // Initialize the sequence number
 int seq_num = 0;
 // Send N packets
 for (int i = 0; i < N; i++) {
 // Send the packet
 send_packet(client_fd, "Hello, world!", seq_num);
 // Update the sequence number
 seq_num++;
 }
 // Receive N packets
 while (1) {
 // Receive the packet
 char *received_packet = receive_packet(client_fd, &seq_num);
 // If the packet is not corrupted, print it
 if (received_packet[0] == seq_num) {
 printf("Received packet: %s\n", received_packet);
 }
 // If the packet is corrupted, discard it
 else {
 free(received_packet);
 }
 }
 // Close the sockets
 close(sockfd);
 close(client_fd);
 return 0;
}