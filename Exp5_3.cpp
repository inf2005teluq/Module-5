#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#define MAX_LINE 100
#define LINE_ARRAY_SIZE (MAX_LINE+3)
using namespace std;
int main(){
    int socketDescriptor;
    int numRead;
    unsigned short int serverPort;
    struct sockaddr_in serverAddress;
    struct hostent *hostInfo;
    struct timeval timeVal;
    fd_set readSet;
    char buf[LINE_ARRAY_SIZE], c;
    cout << "Donnez le nom du serveur ou son adresse IP: ";
    memset(buf, 0x0, LINE_ARRAY_SIZE); 
    // Mettre à zero le tampon
    cin.get(buf, MAX_LINE, '\n');
    //gethostbyname() reçoit un nom d'hôte ou une adresse IP sur 4    
    //octets et renvoie un pointeur sur une structure hostent. 
    hostInfo = gethostbyname(buf);
    if (hostInfo == NULL) 
    {
        cout << "interprétation du problème " << buf << "\n";
        exit(1);
        
    }
        cout << "entrer le numéro de port du serveur: ";

cin >> serverPort;
cin.ignore(1, '\n'); 
// suppression du saut de ligne
// Création de socket de domaine internet "AF_INET" c'est-à-dire  
//  IPv4  et  de  type  datagramme  "SOCK_DGRAM"  en  utilisant  le protocole 
// UDP la valeur 0 indique qu'un seul protocole sera utilisé avec  
// cette socket.
socketDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
if (socketDescriptor < 0)
{
    cerr << "cannot create socket\n";
    exit(1);
    
}
// Initialisation des champs de  serverAddress
serverAddress.sin_family = hostInfo->h_addrtype;
memcpy((char *) &serverAddress.sin_addr.s_addr,hostInfo->h_addr_list[0], hostInfo->h_length);
serverAddress.sin_port = htons(serverPort);
cout << "\nEntrez quelques caractères au clavier.\n";
cout << "Le serveur les modifiera et les renverra.\n";
cout  <<  "Pour  sortir,  entrez  une  ligne  avec  le  caractère  '.' uniquement\n";
cout << "Si une ligne dépasse " << MAX_LINE << " caractères,\n";
cout << "seuls les " << MAX_LINE << " premiers caractères seront utilisés.\n\n";
//  Invite  de  commande  pour  l'utilisateur  et  lecture  des caractères  
//  jusqu'à  la  limite  MAX_LINE.  Puis suppression  du saut de ligne.
cout << "Input: ";
memset(buf, 0x0, LINE_ARRAY_SIZE); 
cin.get(buf, MAX_LINE, '\n');
//  suppression  des  caractères  supplémentaires  et  du  saut  de ligne
cin.ignore(1000,'\n');
//  Arrêt  lorsque  l'utilisateur  saisit  une  ligne  ne  contenant qu'un
// point
while (strcmp(buf, "."))
{
// Envoi de la ligne saisie au serveur
if (sendto(socketDescriptor, buf, strlen(buf), 0,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0)
{cerr << "cannot send data ";
close(socketDescriptor);
exit(1);
} // Attente de la réponse pendant une seconde.FD_ZERO(&readSet);FD_SET(socketDescriptor, &readSet);timeVal.tv_sec = 1;
timeVal.tv_usec = 0;
if (select(socketDescriptor+1, &readSet, NULL, NULL, &timeVal)) 
{
// Lecture de la ligne modifiée par le serveur.
memset(buf, 0x0, LINE_ARRAY_SIZE); 
numRead = recv(socketDescriptor, buf, MAX_LINE, 0);
if (numRead < 0) {cerr << "pas de reponse du serveur ?";
close(socketDescriptor);
exit(1);
    
}
cout << "Modified: " << buf << "\n";
    
}
else 
{
cout << "—pas de réponse du serveur  dans 1 seconde.\n";
    
}
//  Invite  de  commande  pour  l'utilisateur  et  lecture  des caractères  
//  jusqu'à  la  limite  MAX_LINE.  Puis  suppression  du saut de ligne. 
// Comme ci-dessus.
cout << "Input: ";
memset(buf, 0x0, LINE_ARRAY_SIZE); 
// Mise à zéro du tampon
cin.get(buf, MAX_LINE, '\n');
//  Suppression  des  caractères  supplémentaires  et  du  saut  de ligne
cin.ignore(1000,'\n');}
close(socketDescriptor);    
// Fermeture de la socket
return 0;
}
