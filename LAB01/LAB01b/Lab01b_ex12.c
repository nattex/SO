#include <stdio.h>
#include <string.h>

int main() {
   char frase[100];
   char caracter;
   int posicao = -1;

   printf("Digite uma frase: ");
   fgets(frase, sizeof(frase), stdin);

   printf("Digite um caracter que deseja encontrar: ");
   scanf("%c", &caracter);

   for (int i = 0; i < strlen(frase); i++) {
      if (frase[i] == caracter) {
         posicao = i;
         break;
      }
   }

   if (posicao != -1) {
      printf("O caractere '%c' foi encontrado na posição %d.\n", caracter, posicao);
   } else {
      printf("O caractere '%c' não foi encontrado na frase.\n", caracter);
   }

   return 0;
}
