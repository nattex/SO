#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int thread_count;
int n;
double sum;
pthread_mutex_t mutex;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) // i é par
        factor = 1.0;
    else // i é impar
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        pthread_mutex_lock(&mutex);
        sum += factor/(2*i+1);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    long thread;
    pthread_t* thread_handles;

    thread_count = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);

    thread_handles = malloc(thread_count*sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    sum = 0.0;
    for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);

    for (thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    sum = 4.0*sum;

    printf("Com %d threads, nosso valor calculado de pi é %.15f\n", thread_count, sum);

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    return 0;
}
