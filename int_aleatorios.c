#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int main(){
    srand(time(NULL));   
    int tam_num, qtd_num;
    FILE *arquivo;
    int qtd_arquivos;
    char nome_arq[30] = "";

    printf("Quantos arquivos serao feitos? ");
    scanf("%d", &qtd_arquivos);

    for (int j = 1; j < qtd_arquivos+1; j++){
        sprintf(nome_arq, "inputs/int_aleatorio%d", j);
        arquivo = fopen(nome_arq, "w");

        printf("Digite a quantidade de números para o arquivo%d\n", j);
        scanf("%d", &qtd_num);
        printf("Digite o tamanho dos numeros do arquivo%d\n", j);
        scanf("%d", &tam_num);


        if (arquivo == NULL) {
            printf("O arquivo não foi aberto com sucesso");
            return 1;
        }


        //cabecalho
        fprintf(arquivo, "%s\n", nome_arq);

        //imprime os numeros inteiros
        for (int i = 0; i < qtd_num; i++){
            fprintf(arquivo, "%d\n", rand()%tam_num + 1);
        }

        fclose(arquivo);

    }
    

    return 0;
}