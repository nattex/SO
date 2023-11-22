#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); //Quantidades de 0 a serem colocados
    int pessoas[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pessoas[i][0], &pessoas[i][1]);
    }
    int direcao_atual = pessoas[0][1];
    int tempo_atual = pessoas[0][0];
    for (int i = 0; i < N; i++) {
        if (pessoas[i][1] != direcao_atual) {
            tempo_atual += 10;
            direcao_atual = pessoas[i][1];
        }
        if (pessoas[i][0] > tempo_atual) {
            tempo_atual = pessoas[i][0];
        }
        tempo_atual += 10;
    }
    printf("%d\n", tempo_atual); //resultado final
    return 0;
}
