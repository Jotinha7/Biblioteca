#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <stdio.h>

struct pacote {
  int destino[6];
  int origem[6];
  int type;
  int dados[1500];
};

struct meio{
  int livre;
  struct pacote atual;
};

int main(){
  struct meio *at = malloc(sizeof(struct meio));
  int id = shmget(IPC_PRIVATE, sizeof(at), IPC_CREAT | 0666);
  if(id < 0) {
    printf("nao alocado\n");
  }
  at = (struct meio*) shmat(id, NULL, 0);
  at->livre=1;
  pid_t k = fork();
  
  if(k == 0) {
    
    for(int i = 0; i < 8; i++) {
      fork();
    }
    
    srandom(time(NULL));
    
    while(1){
      
      while(!(at->livre));
      
      at->livre = 0;
      struct pacote guarda;
      for (int i = 0; i < 6; i++) {
        guarda.destino[i] = (rand() % 256);
        guarda.origem[i] = (rand() % 256);
      }
      for (int i = 0; i < 1500; i++) {
        guarda.dados[i] = 256 + rand() % 100000;
      }
      
      at->atual = guarda;
      printf("origem atual: ");
      for (int i = 0; i < 6; i++) {
        printf("%d ", guarda.origem[i]);
      }
      printf("\ndestino atual: ");
      for (int i = 0; i < 6; i++) {
        printf("%d ", guarda.destino[i]);
      }
      
      if(at->atual.dados != guarda.dados) {
        printf("colidiu!!!!!!!!");
      }
      
      at->livre = 1;
      sleep(2);
    }
  } else {
    printf("processo pai\n");
  }
}
