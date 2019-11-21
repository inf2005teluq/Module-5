#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_message_function( void *ptr );
main(){pthread_t thread1, thread2;char *message1 = "Thread 1";
char *message2 = "Thread 2";
int iret1, iret2;
//Création de deux threads qui vont afficher chacun leur message 
iret1 = pthread_create( &thread1, NULL, print_message_function, (void*)message1);
iret2 = pthread_create( &thread2, NULL, print_message_function, (void*)message2);
//On attend que les threads soient prêts 
pthread_join( thread1, NULL);
pthread_join( thread2, NULL);
//On affiche la valeur de retour des threads 
cout << "Thread 1 returns: \n" << iret1;
cout << "Thread 2 returns: \n" << iret2;
exit(0);
    
}
void *print_message_function( void *ptr )
{
    char *message;
    message = (char *) ptr;
cout<< "%s \n" << message;
    
}
