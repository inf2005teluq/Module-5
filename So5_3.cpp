#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <iostream>
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_LINE+3)
#define NEWLINE "\n"
using namespace std;
int main()
{
    int socketDescriptor;
    int numRead;
    unsigned short int serverPort;
    struct sockaddr_in serverAddress;
    struct hostent *hostInfo;
    struct timeval timeVal;
    fd_set readSet;
    char buf[LINE_ARRAY_SIZE], c;
    cout << "entrer le nom du serveur ou son adresse IP: ";
    memset(buf, 0x0, LINE_ARRAY_SIZE); 
    // Zero out the buffer.
    cin.get(buf, MAX_LINE, '\n');
    // gethostbyname() takes a host name or ip address in "numbers and
    // dots" notation, and returns a pointer to a hostent structure,
 // which we'll need later. It's not important for us what this
 // structure is actually composed of.
 hostInfo = gethostbyname(buf);
 if (hostInfo == NULL) 
 {
     cout << "probleme pour connaitre le host: " << buf << "\n";
     exit(1);
     
 }
     cout << "Entrer le numero de port du serveur: ";
     cin >> serverPort;
     cin.get(c); 
     // Creation de socket
     socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);
     if (socketDescriptor < 0) 
     {
         cerr << "ne peut pas créer de socket\n";
         exit(1);
         
     }
     serverAddress.sin_family = hostInfo->h_addrtype;
     memcpy((char *) &serverAddress.sin_addr.s_addr,hostInfo->h_addr_list[0], hostInfo->h_length);
     serverAddress.sin_port = htons(serverPort);
     cout << "\nEnter some lines, and the server will modify them and\n";
     cout << "send them back. When you are done, enter a line with\n";
     cout << "just a dot, and nothing else.\n";
     cout << "If a line is more than " << MAX_LINE << " characters, then\n";
     cout << "only the first " << MAX_LINE << " characters will be used.\n\n";
     cout << "Input: ";
     memset(buf, 0x0, LINE_ARRAY_SIZE); 
     // Zero out the buffer.
     cin.get(buf, MAX_LINE, '\n');
     while (cin.get(c) && c != '\n');
     // Stop when the user inputs a line with just a dot.
     while (strcmp(buf, "."))
     {
         // Send the line to the server.
         if (sendto(socketDescriptor, buf, strlen(buf), 0,(struct sockaddr *) &serverAddress,
sizeof(serverAddress)) < 0) {
  cerr << "cannot send data ";
  close(socketDescriptor);
  exit(1);
} // wait until answer comes back, for up to 1 secondFD_ZERO(&readSet);
FD_SET(socketDescriptor, &readSet);
timeVal.tv_sec = 1;
timeVal.tv_usec = 0;
if (select(socketDescriptor+1, &readSet, NULL, NULL, &timeVal))
{
    // Read the modified line back from the server.
    memset(buf, 0x0, LINE_ARRAY_SIZE);
    // Zero out the buffer.
    numRead = recv(socketDescriptor, buf, MAX_LINE, 0);
    if (numRead < 0) 
    {
    cerr << "pas de reponse du serveur?";
    close(socketDescriptor);
    exit(1);
        
    }
    cout << "modification: " << buf << "\n";}
    else 
    {
        cout << "** le serveur ne reponds pas dans une seconde.\n";
        
    }
        cout << "Input: ";
        memset(buf, 0x0, LINE_ARRAY_SIZE); 
        cin.get(buf, MAX_LINE, '\n');
        while (cin.get(c) && c != '\n');
         
     }
        close(socketDescriptor);
        return 0;
    
}
