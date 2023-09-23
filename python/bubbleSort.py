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
vetorcp = []
entrada(vetor)

for c in range(3):
    vetorcp = vetor.copy()

    inicio = time.perf_counter()
    bubbleSort(vetorcp)
    fim = time.perf_counter()

    #print(vetor)
    
    arquivo = open('python/output/bubbleSort.txt', 'a')
    arquivo.write(f"{(fim - inicio) * 1000}\t")

arquivo.write("\n")
arquivo.close()
