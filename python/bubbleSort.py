import sys
import time

def entrada(vetor):

    try:
        while True:
            vetor.append(int(input())) 
    except EOFError:
        print("Arquivo lido com sucesso!")

def bubbleSort(vetor):
    for j in range(len(vetor), 1, -1):
        for i in range(1, j):
            if vetor[i] < vetor[i-1]:
                aux = vetor[i]
                vetor[i] = vetor[i-1]
                vetor[i-1] = aux


#recebe a primeira linha do arquivo
nome_arquivo = input()

vetor = []
entrada(vetor)
inicio = time.perf_counter()
bubbleSort(vetor)
fim = time.perf_counter()

print(f"O tempo de execucao foi {(fim - inicio) * 1000} ms")

with open('output/int_python.txt', 'a') as arquivo:
    arquivo.write(f"{nome_arquivo}\n\tAlgoritmo de ordenacao: BubbleSort\n\tTempo de execucao: {(fim - inicio) * 1000} ms\n\tQuantidade de numeros: {len(vetor)}\n\n")


