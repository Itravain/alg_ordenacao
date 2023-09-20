#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void decrescente(int tam_num, int qtd_num, FILE *arquivo, char nome_arq[30]){
    //cabecalho
    fprintf(arquivo, "%s\n", nome_arq);

    //imprime os números inteiros
    for (int i = qtd_num; i > 0; i--){
        fprintf(arquivo, "%d\n", i);
    }
}

void aleatorios(int tam_num, int qtd_num, FILE *arquivo, char nome_arq[30]){
    //cabecalho
    fprintf(arquivo, "%s\n", nome_arq);

    //imprime os números inteiros
    for (int i = 0; i < qtd_num; i++){
        fprintf(arquivo, "%d\n", rand() % tam_num + 1);
    }
}

void q_ordenado(int tam_num, int qtd_num, FILE *arquivo, char nome_arq[30]){
    //cabecalho
    fprintf(arquivo, "%s\n", nome_arq);

    //imprime os números inteiros
    for (int i = 0; i < qtd_num; i++) {
        if (i < qtd_num * 0.95) {
            fprintf(arquivo, "%d\n", i);
        } else {
            fprintf(arquivo, "%d\n", rand() % tam_num + 1);
        }
    }
}

void criar_arquivo(FILE **arquivo, int *tipo_arq, char nome_arq[30], int *qtd_num, int *tam_num, int *j){
    if (*tipo_arq == 1) {
        strcpy(nome_arq, "int_decrescente");
    }
    else if (*tipo_arq == 2) {
        strcpy(nome_arq, "int_aleatorio");
    }
    else if (*tipo_arq == 3) {
        strcpy(nome_arq, "int_95_ordenado");
    }
    else {
        printf("Tipo de arquivo invalido\n");
        exit(1);
    }

    printf("\nDigite a quantidade de números para o arquivo %d\n", *j);
    scanf("%d", qtd_num);
    printf("Digite o tamanho máximo dos números do arquivo %d\n", *j);
    scanf("%d", tam_num);

    // Cria o nome do arquivo
    char nome_completo[50];
    sprintf(nome_completo, "inputs/%s/%d_%d_%d.txt", nome_arq, *j, *qtd_num, *tam_num);

    // Abre o arquivo
    *arquivo = fopen(nome_completo, "w");
    if (*arquivo == NULL) {
        printf("O arquivo não pode ser aberto\n");
        exit(1);
    }

}

int main() {
    srand(time(NULL));
    int tam_num, qtd_num, tipo_arq;
    FILE *arquivo;
    int qtd_arquivos;
    char nome_arq[40] = "";

    // Quantidade de arquivos
    printf("Quantos arquivos serão feitos? ");
    scanf("%d", &qtd_arquivos);

    // Escolhe o tipo de arquivo
    printf("Qual o tipo de arquivo?\n1 - Decrescente\n2 - Aleatorio\n3 - 95 ordenado\n");
    scanf("%d", &tipo_arq);

    // Loop para imprimir a quantidade de arquivos desejada
    for (int j = 1; j <= qtd_arquivos; j++){
        criar_arquivo(&arquivo, &tipo_arq, nome_arq, &qtd_num, &tam_num, &j);
        if (tipo_arq == 1){
            decrescente(tam_num, qtd_num, arquivo, nome_arq);
        }
        else if (tipo_arq == 2){
            aleatorios(tam_num, qtd_num, arquivo, nome_arq);
        }
        else if (tipo_arq == 3){
            q_ordenado(tam_num, qtd_num, arquivo, nome_arq);
        }
        else{
            printf("Tipo de arquivo invalido\n");
            exit(1);
        }

        fclose(arquivo);
    }

    return 0;
}
