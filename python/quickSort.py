import sys
import time

sys.setrecursionlimit(10**6)

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
vetorcp = []
entrada(vetor)

for c in range(3):
    vetorcp = vetor.copy()

    inicio = time.perf_counter()
    quickSort(vetorcp, 0, len(vetor) - 1)
    fim = time.perf_counter()

    #print(vetor)

    arquivo = open('python/output/quickSort.txt', 'a')
    arquivo.write(f"{(fim - inicio) * 1000}\t")

arquivo.write("\n")
arquivo.close()

