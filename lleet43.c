char* multiply(char* num1, char* num2) {
    int n1, n2,i,j;
    n1 = strlen(num1);
    n2 = strlen(num2);
    
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) { //pra qnd for 0
        char *result = malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int t = n1 + n2;

    int *v = calloc(t, sizeof(int));

    
    for (i = n1 - 1; i >= 0; i--) { //prod deles
        for (j = n2 - 1; j >= 0; j--) {

            int a = num1[i] - '0';
            int b = num2[j] - '0';

            v[i + j + 1] += a * b;
        }
    }

    //o vai um
    for (i = t - 1; i > 0; i--) {
        v[i - 1] += v[i] / 10;
        v[i] %= 10;
    }

    //onde começa o número
    int inicio = 0;

    while (inicio < t - 1 && v[inicio] == 0) {
        inicio++;
    }

    
    char *result = malloc((t - inicio + 1) * sizeof(char)); //string de resultado

    int k = 0;

    for (i = inicio; i < t; i++) {
        result[k++] = v[i] + '0';
    }

    result[k] = '\0';

    free(v);

    return result;
}