import sys
import time

def entrada(vetor):
    try:
        while True:
            vetor.append(int(input())) 
    except EOFError:
        print("Arquivo lido com sucesso!")

def mergeSort(vetor):
    print()

#recebe a primeira linha do arquivo
nome_arquivo = input()

vetor = []
entrada(vetor)
inicio = time.perf_counter()
mergeSort(vetor)
fim = time.perf_counter()

print(vetor)

with open('output/int_python.txt', 'a') as arquivo:
    arquivo.write(f"{nome_arquivo}\n\tAlgoritmo de ordenacao: mergeSort\n\tTempo de execucao: {(fim - inicio) * 1000} ms\n\tQuantidade de numeros: {len(vetor)}\n\n")


