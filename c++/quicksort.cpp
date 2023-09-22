#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip> 

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    std::vector<int> arr;
    int num;

    while (inputFile >> num) {
        arr.push_back(num);
    }

    inputFile.close();

    std::cout << "Array com " << arr.size() << " elementos" << std::endl;

    auto start = std::chrono::high_resolution_clock::now(); 

    quickSort(arr, 0, arr.size() - 1);

    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); 

    std::cout << "Tempo de execução: " << std::fixed << std::setprecision(5) << duration.count() / 1000.0 << " milliseconds." << std::endl;

    return 0;
}
