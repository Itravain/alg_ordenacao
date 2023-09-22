#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip> 

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
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

    bubbleSort(arr);

    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); 

    std::cout << "Tempo de execução: " << std::fixed << std::setprecision(5) << duration.count() / 1000.0 << " milliseconds." << std::endl;

    return 0;
}
