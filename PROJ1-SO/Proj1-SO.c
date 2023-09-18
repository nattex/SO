#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define FIBER_STACK (1024 * 64)

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t semaforo;
int transferencias_ativas = 1;

int random_send_receive() {
    return rand() % 2;
}

void* transferencia(void* arg)
{
    sem_wait(&semaforo);

    pthread_mutex_lock(&mutex);

    if (from.saldo <= 0 || to.saldo <= 0) {
        transferencias_ativas = 0;
    }

    int send = random_send_receive();
    
    if (transferencias_ativas) {
        if (send) {
            if (from.saldo >= valor) {
                from.saldo -= valor;
                to.saldo += valor;
                printf("Transferência (envio) concluída com sucesso!\n");
            } else {
                printf("Transferência (envio) falhou - saldo insuficiente em from.\n");
                transferencias_ativas = 0;
            }
        } else {
            if (to.saldo >= valor) {
                to.saldo -= valor;
                from.saldo += valor;
                printf("Transferência (recebimento) concluída com sucesso!\n");
            } else {
                printf("Transferência (recebimento) falhou - saldo insuficiente em to.\n");
                transferencias_ativas = 0;
            }
        }
    }

    if (transferencias_ativas) {
        printf("Saldo de c1: %d\n", from.saldo);
        printf("Saldo de c2: %d\n", to.saldo);
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&semaforo);

    return NULL;
}

int main()
{
    void* stack;
    pthread_t threads[100];
    int i;

    stack = malloc(FIBER_STACK);
    if (stack == 0) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    from.saldo = 100;
    to.saldo = 100;

    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    sem_init(&semaforo, 0, 100);

    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        pthread_create(&threads[i], NULL, transferencia, NULL);
    }

    for (i = 0; i < 100; i++) {
        pthread_join(threads[i], NULL);
    }

    free(stack);
    sem_destroy(&semaforo);
    pthread_mutex_destroy(&mutex);

    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}
