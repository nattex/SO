#include <stdio.h>
#include <string.h>

void insertCharAtPosition(char str[], int position, char character) {
    int len = strlen(str);
    
    if (position < 0 || position > len) {
        printf("Posição inválida.\n");
        return;
    }
    
    // Deslocar os caracteres à direita para abrir espaço para o novo caractere
    for (int i = len; i >= position; i--) {
        str[i + 1] = str[i];
    }
    
    str[position] = character;
}

int main(void) {
    char Str[100] = "ornitooincoc";
    int position = 4; // Posição onde o caractere será inserido
    char character = '*'; // Caractere a ser inserido
    
    printf("String original: %s\n", Str);
    insertCharAtPosition(Str, position, character);
    printf("String modificada: %s\n", Str);
    
    return 0;
}

