#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define qtd_num 100
#define num_tam 10
#define nome_arq "aleatorios.txt"

int main(){
    srand(time(NULL));
    FILE *arquivo;

    arquivo = fopen(nome_arq, "w");

    if (arquivo == NULL) {
        printf("O arquivo não foi aberto com sucesso");
        return 1;
    }

    //escreve o primeiro numero no arquivo
    fprintf(arquivo, "%d\n", qtd_num);

    for (int i = 0; i < qtd_num; i++){
        fprintf(arquivo, "%d\n", rand()%num_tam);
    }

    fclose(arquivo);



    return 0;
}