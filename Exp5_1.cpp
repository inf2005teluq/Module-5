#include <stdio.h>       
#include <pthread.h>    
/*entête de la bibliothèque*//* fonction à exécuter par un nouveau thread */
void*do_loop(void* data)
{
    int i;
/*  compteur,  pour  imprimer  les  numéros */
int j;
/* compteur de délai        */
int IDthread = *((int*)data);     
/* identifiant de thread */
for (i=0; i<10; i++) 
{
    for (j=0; j<500000; j++) 
/*  */;
printf("'%d' -Got '%d'\n", IDthread, i);}

/* fin du thread*/ 
pthread_exit(NULL);
}

int main(int argc, char * argv[]) 
{
  int thr_id; 
  /* ID pour un nouveau thread */
 
  pthread_t p_thread; 
  /*  structure    du  thread                    */
  int a = 1; /* identifiant du thread 1  */
  int b = 2; /* identifiant du thread 2 */ 
  /* creation d'un nouveau thread qui execute 'do_loop()' */
  thr_id = pthread_create( & p_thread, NULL, do_loop, (void * ) & a); 
  /* exécuter 'do_loop()' dans le main thread  */
  do_loop((void * ) & b); 
  /* */
  return 0;
}
