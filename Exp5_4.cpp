#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_LINE+3
)using namespace std;
int main(){
    int listenSocket, i;
    unsigned short int listenPort;
    socklen_t clientAddressLength;
    struct sockaddr_in clientAddress, serverAddress;
    char line[LINE_ARRAY_SIZE];
    cout << " donnez le numéro d’écoute (entre 1500 et 65000): ";
    cin >> listenPort;
    ///  Création  de  socket  en  écoute  et  attente  des  requêtes  des clients
    listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (listenSocket < 0) {
        cerr << "cannot create listen socket";exit(1);
        
    }
        // /Connexion du socket au port en écoute.
        //  /On  commence  par  initialiser  les  champs  de  la  structure serverAddress puis
        //  /on  appelle  bind().Les  fonctions  htonl()  et  htons() convertissent respectivement les entiers 
        /// longs et les entiers courts du rangement hôtes
        erverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddress.sin_port = htons(listenPort);
        if (bind(listenSocket,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) 
        {
            cerr << "cannot bind socket";
        exit(1);
            
        }
 // Attente des requêtes clients.
 //  C'est  un  appel  non-bloquant  ;  c'est-à-dire  qu'il  enregistre ce programme
 //  auprès  du système  comme  devant  attendre  des  connexions  sur cette socket avec
 // cette tâche. Puis, l'exécution se poursuit.
 listen(listenSocket, 5);
 cout << "Waiting for request on port " << listenPort << "\n";
 while (1) 
 {
     clientAddressLength = sizeof(clientAddress);
     // Mise à zéro du tampon de façon à connaître le délimiteur
     // de fin de chaîne.
     memset(line, 0x0, LINE_ARRAY_SIZE);
     if (recvfrom(listenSocket, line, LINE_ARRAY_SIZE, 0,(struct sockaddr *) &clientAddress,&clientAddressLength) < 0) 
     {
         cerr << " I/O Problem";
         exit(1);
         
     }
     // Affichage de l'adresse IP du client.
     cout << " de " << inet_ntoa(clientAddress.sin_addr);
     // Affichage du numéro de port du client.
     cout << ":" << ntohs(clientAddress.sin_port) << "\n";
     // Affichage de la ligne reçue
     cout << " Reçu: " << line << "\n";
     // Conversion de cette ligne en majuscules.
     for (i = 0; line[i] != '\0'; i++)
     line[i] = toupper(line[i]);
     // Renvoi de la ligne convertie au client.
     if (sendto(listenSocket, line, strlen(line) + 1, 0,(struct sockaddr *) &clientAddress,sizeof(clientAddress)) < 0)
     cerr << "Error: Ne peut envoyés ces données";
     memset(line, 0x0, LINE_ARRAY_SIZE); 
     // Mise à zéro du tampon
     }
    
}
