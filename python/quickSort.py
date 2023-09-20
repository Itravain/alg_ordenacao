import sys
import time

def entrada(vetor):
    try:
        while True:
            vetor.append(int(input())) 
    except EOFError:
        print("Arquivo lido com sucesso!")

def troca(vetor, x, y):
    aux = vetor[x]
    vetor[x] = vetor[y]
    vetor[y] = aux

def quickSort(vetor, inicio, fim):
    if inicio < fim:
        q = partition(vetor, inicio, fim)
        quickSort(vetor, inicio, q-1)
        quickSort(vetor, q+1, fim)


def partition(vetor, q, r):
    i = q-1
    for j in range (q, r):
        if vetor[j] < vetor[r]:
            i += 1
            troca(vetor, i, j)
    troca(vetor, i+1, r)
    return i + 1
    
    

#recebe a primeira linha do arquivo
nome_arquivo = input()

vetor = []
entrada(vetor)
inicio = time.perf_counter()
quickSort(vetor, 0, len(vetor) - 1)
fim = time.perf_counter()

print(vetor)

with open('output/int_python.txt', 'a') as arquivo:
    arquivo.write(f"{nome_arquivo}\n\tAlgoritmo de ordenacao: quickSort\n\tTempo de execucao: {(fim - inicio) * 1000} ms\n\tQuantidade de numeros: {len(vetor)}\n\n")


