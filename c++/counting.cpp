#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip> 

void counting(std::vector<int>& arr) {
    int max = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::vector<int> count(max + 1, 0);
    std::vector<int> output(n);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
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

    counting(arr);

    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); 

    std::cout << "Tempo de execução: " << std::fixed << std::setprecision(5) << duration.count() / 1000.0 << " milliseconds." << std::endl;

    return 0;
}
