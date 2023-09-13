import sys


vetor = []

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




entrada(vetor)
bubbleSort(vetor)
print(vetor)


