#include <stdio.h>
#include <ctype.h>

int main(){
    char str[100];
    int i;

    printf("Digite uma string: ");
    scanf("%s",str);


    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }

    printf("A nova string: %s\n",str);



    return 0;
}

