#include <stdio.h>
#include <pthread.h>
void *samplejob()
{
    printf("This is Pthread");
}
int main(int argc, char *argv[])
{
    pthread_t first_thread;
    pthread_create(&first_thread, NULL, &samplejob, NULL);
    pthread_join(first_thread, NULL);
    return 0;
}
