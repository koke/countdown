#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_from = 10;

void sig_handler(int signo)
{
  if (signo == SIGINT) {
    printf(u8"\33[2K\r🚫 Canceled.\n");
    exit(1);
  }
}

void read_options(int argc, char **argv)
{
    int c;

    while ((c = getopt(argc, argv, "n:")) != -1 ) {
        switch (c)
        {
            case 'n':
                count_from = atoi(optarg);
                break;
        
            default:
                break;
        }
    }
}

int main(int argc, char **argv)
{
    read_options(argc, argv);
    signal(SIGINT, sig_handler);
    for(int i = count_from; i > 0; i--) {
        printf(u8"\33[2K\r⏱  Starting in %i...", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\33[2K\r🚀 Starting now.\n");
    return 0;
}
