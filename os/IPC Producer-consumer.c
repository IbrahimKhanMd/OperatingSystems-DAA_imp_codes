#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define buff_max 25
#define mod %
struct item
{
    int data;
};
struct item shared_buff[buff_max]; 
int free_index = 0;
int full_index = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int running = 1; // Global variable to control the program loop
void *producer(void *arg)
{
    struct item new_item;
    while (running)
    {
        new_item.data = rand() % 100; // Example item data generation

        usleep(100000);   
        while (((free_index + 1) mod buff_max) == full_index && running)
        {
            usleep(100000); // 100 milliseconds
        }
        if (!running)
            break; // Exit the loop if running is false
        pthread_mutex_lock(&mtx);

        shared_buff[free_index] = new_item;
        free_index = (free_index + 1) mod buff_max;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}
void *consumer(void *arg)
{
    struct item consumed_item;
    while (running)
    {
        while (free_index == full_index && running)
        {
            usleep(100000); // 100 milliseconds
        }
        if (!running)
            break; // Exit the loop if running is false
        pthread_mutex_lock(&mtx);
        consumed_item = shared_buff[full_index];
        full_index = (full_index + 1) mod buff_max;
        pthread_mutex_unlock(&mtx);
        printf("Consumed item with data: %d\n", consumed_item.data);
        usleep(100000); // 100 milliseconds
    }
    return NULL;
}
int main()
{
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    sleep(1);
    running = 0;
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
