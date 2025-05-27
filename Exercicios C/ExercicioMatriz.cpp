int main() {
    int matrizA[2][2] = {{1,2},{2,3}};
    int matrizB[2][2] = {{5,6},{7,8}};
    int matrizC[2][2];

    // Somar as matrizes
    for (int i = 0;   i < 2 ; i++) {
        for (int j = 0;  j < 2; i++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    imprimirMatriz(2,2,matrizC);
    return 0;
}
