#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 8

int m, n;
int thread_count;
double **A; 
double *x; 
double *y; 

void *Pth_mat_vect(void *rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main() {
    int i;
    pthread_t my_threads[MAX_THREADS];
    thread_count = 4; // Defina o número de threads
    for (i = 0; i < thread_count; i++) {
        pthread_create(&my_threads[i], NULL, Pth_mat_vect, (void *) i);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(my_threads[i], NULL);
    }
    return 0;
}
