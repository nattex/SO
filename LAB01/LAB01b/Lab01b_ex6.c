#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //exercicio 6
  
  int linha, coluna;
  
  printf("\nDigite o numero de linha(s) da matriz:");
  scanf("%d", &linha);

  printf("\nDigite o numero de coluna(s) da matriz:");
  scanf("%d", &coluna);

  int matriz[linha][coluna];

  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      printf ("\n Digite o Elemento[%d][%d] = ", i, j);
      scanf ("%d", &matriz[i][j]);
    }
  }

  int transposta[coluna][linha];

  for(int i=0;i<linha;i++){ 
    for(int j=0; j<coluna; j++)
    {
      transposta[j][i] = matriz[i][j];
    }
  }

  printf("\n\nMatriz Transposta:\n");
  for (int i=0; i<linha; i++ ){ 
    for (int j=0; j<coluna; j++ )
    {
      printf ("%d ", transposta[ i ][ j ]);
    }
    printf("\n");
  }
  return 0;
}
