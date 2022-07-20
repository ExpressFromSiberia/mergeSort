#include <iostream>
#include <vector>

void Merge(std::vector<int>& A, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    std::vector<int> tmp(r - p + 1);

    for (int step = 0; step < r - p + 1; step++) {
        if ((j > r) || ((i <= q) && (A[i] < A[j]))) {
            tmp[step] = A[i];
            i++;
        }
        else {
            tmp[step] = A[j];
            j++;
        }
    }

    for (int step = 0; step < r - p + 1; step++)
        A[p + step] = tmp[step];
}

void Sort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Sort(A, p, q);
        Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}
int main() {
    setlocale(0, "");
    int size = 0;

    std::cout << "Укажите размер массива." << std::endl;
    std::cin >> size;
    std::vector<int> A(size);

    std::cout << "Введите элементы массива через пробел." << std::endl;
    for (int i = 0; i < size; i++)
        std::cin >> A[i];

    std::cout << "Исходный массив размера " << size << std::endl;
    for (int i = 0; i < size - 1; i++)
        std::cout << A[i] << " ";
    std::cout << A[size - 1] << std::endl;

    Sort(A, 0, size - 1);

    std::cout << "Результат сортировки:" << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";

    return 0;
}
