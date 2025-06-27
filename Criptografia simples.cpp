#include <stdio.h>
#include <string.h>
#include <ctype.h>  // para tolower e isdigit

int main() {
    char frase[101]; // ler uma frase no maximo 100 caracterer + 0 por isso 101

    printf("Digite uma frase : "); // pedindo ao usuario
    fgets(frase, sizeof(frase), stdin);


    printf("Frase modificada:\n"); // exibir a frase modificada nesse printf

    // Percorrer a string via ponteiro de char
    char *p;
    for(p = frase; *p != '\0'; p++) {
        char c = *p; // caractere atual
        char lower_c = tolower(c); // converter para minúscula

        // Primeiro verificamos se é vogal
        if(lower_c == 'a' || lower_c == 'e' || lower_c == 'i' ||
           lower_c == 'o' || lower_c == 'u') {

            switch(lower_c) {
                case 'a': printf("2"); break; // esse break para nao ler todas as vogais quando precisar ser criptografado
                case 'e': printf("3"); break; // Assim quando for por exemplo a vogal E, ele nao le o restante
                case 'i': printf("4"); break;
                case 'o': printf("5"); break;
                case 'u': printf("6"); break;
            }

            // Depois verificamos se é um dígito
           } else if(isdigit(c)) {
               // Utilizei letras aleatorias para ficar relativamente mais complexo e sem logicas para analisar
               switch(c) { // utilizando a mesma logica para fazer a substituição das vogais por numeros
                   case '0': printf("y"); break;
                   case '1': printf("r"); break;
                   case '2': printf("o"); break;
                   case '3': printf("p"); break;
                   case '4': printf("E"); break;
                   case '5': printf("w"); break;
                   case '6': printf("E"); break;
                   case '7': printf("K"); break;
                   case '8': printf("Z"); break;
                   case '9': printf("X"); break;
                   default: printf("%c", c); break;
               }

               // Se não é vogal nem número, imprime o caractere original
           } else {
               printf("%c", c);
           }
    }

    printf("\n");
    return 0;
}

