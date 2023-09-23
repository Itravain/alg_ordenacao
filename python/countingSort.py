import sys
import time

def entrada(vetor_a):
    try:
        while True:
            vetor_a.append(int(input())) 
    except EOFError:
        print("Arquivo lido com sucesso!")

def countingSort(vetor_a, vetor_b, x, tam):
    vetor_c = [0] * (x+1)

    for j in range(tam):
        vetor_c[vetor_a[j]] += 1

    for i in range(1, x+1):
        vetor_c[i] += vetor_c[i-1]

    for j in range(tam-1, 0, -1):
        vetor_b[vetor_c[vetor_a[j]]-1] = vetor_a[j]
        vetor_c[vetor_a[j]] -= 1


vetor_a = []
vetor_a_cp = []

#recebe a primeira linha do arquivo
nome_arquivo = input()

entrada(vetor_a)
x = max(vetor_a)
tam = len(vetor_a)


for c in range (3):
    vetor_a_cp = vetor_a.copy()
    vetor_b = [0] * tam 

    inicio = time.perf_counter()
    countingSort(vetor_a_cp, vetor_b, x, tam)
    fim = time.perf_counter()

    arquivo = open('python/output/countingSort.txt', 'a')
    arquivo.write(f"{(fim - inicio) * 1000}\t")

arquivo.write("\n")
arquivo.close()