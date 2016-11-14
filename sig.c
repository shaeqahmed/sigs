#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler (int sig);

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("PID: %d\n",getpid());
    sleep(1);
  }
}

void sighandler(int sig){
  if (sig == SIGINT){
    printf("\nSignal: %d -----> EXIT\n", sig);
    int file = open("sig.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char* msg = "\nSIGINT Occured!";
    write(file, msg, sizeof(msg));
    close(file);
    exit(0);
  } else if (sig == SIGUSR1) {
    printf("PARENT PID: %d\n", getppid());
  }
}
