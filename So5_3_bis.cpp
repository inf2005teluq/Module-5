//server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#define MAX_MSG 100
using namespace std;
int main()
{
    int listenSocket, i;
    unsigned short int listenPort;
    socklen_t clientAddressLength;
    struct sockaddr_in clientAddress, serverAddress;
    char line[(MAX_MSG+1)];
    cout << "entrer le numero de port d'écoute (between 1500 and 65000): ";
    cin >> listenPort;
    // Create socket for listening for client connection requests.l
    istenSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (listenSocket < 0) 
    {
        cerr << "ne peut pas créer une socket d'écoute";
        exit(1);
        
    }
        serverAddress.sin_family = PF_INET;serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddress.sin_port = htons(listenPort);
        if (bind(listenSocket,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) 
        {
            cerr << "ne peut pas lier la socket";
            exit(1);

}
listen(listenSocket, 5);
cout << "attente de requete sur le port ouvert " << listenPort << "\n";
while (1) {
  clientAddressLength = sizeof(clientAddress);
  memset(line, 0x0, (MAX_MSG + 1));
  if (recvfrom(listenSocket, line, MAX_MSG, 0, (struct sockaddr * ) & clientAddress, & clientAddressLength) < 0) {
    cerr << " I/O Problemes";
    exit(1);
  }
  cout << " from " << inet_ntoa(clientAddress.sin_addr); 
  // Show the client's port number.
  cout << ":" << ntohs(clientAddress.sin_port) << "\n";
  // Show the line
  cout << " Received: " << line << "\n";// Convert line to upper case.
  for (i = 0; line[i] != '\0'; i++)
  line[i] = toupper(line[i]);
  if (sendto(listenSocket, line, strlen(line) + 1, 0,(struct sockaddr *) &clientAddress,sizeof(clientAddress)) < 0)
  cerr << "Error: ne peut pas modifier les données";
  memset(line, 0x0, (MAX_MSG+1));
  // set line to all zeroes
  }
    
}
