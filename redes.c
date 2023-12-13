#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <stdio.h>

struct meio{
  int livre;
  int mensagem;
};

int main(){
  struct meio *at = malloc(sizeof(struct meio));
  int id = shmget(IPC_PRIVATE, sizeof(at), IPC_CREAT | 0666);
  at = (struct meio*) shmat(id, NULL, 0);
  at->livre=1;
  fork();
  srandom(getpid());
  while(1){
    while(!(at->livre));
    at->livre = 0;
    int cc = random()%100;
    at->mensagem = cc;
    printf("id: %d   atual: %d\n", getpid(), at->mensagem);
    if(cc != at->mensagem) {
      printf("colidiu com id: %d\n", getpid());
    }
    at->livre = 1;
    sleep(3);
  }
  at->livre=1;
  sleep(1);
}
