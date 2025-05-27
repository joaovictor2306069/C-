#include <stdio.h>
int main(){

int numeros[101];
    // n + 1
    int i;

for (i=0;i<101;i++){
numeros[i] = i;
}
for (i=0;i<101;i++) {
    if (numeros[i] % 2 == 0 ){
        printf("%i", numeros[i]);
    }
}
return 0;

}
