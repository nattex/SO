#include <stdio.h>
#include <string.h>

void removeCharAtPosition(char str[], int position) {
    int len = strlen(str);
    
    if (position < 0 || position >= len) {
        printf("Posição inválida.\n");
        return;
    }
    
    for (int i = position; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    
    str[len - 1] = '\0';
}

int main(void) {
    char Str[100] = "orn*ito**rr*in**co*";
    int position = 3; // Posição do caractere a ser removido
    
    printf("String original: %s\n", Str);
    removeCharAtPosition(Str, position);
    printf("String modificada: %s\n", Str);
    
    return 0;
}

