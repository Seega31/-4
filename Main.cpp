#include <iostream>

template <typename T>
void mirror_arr(T arr[], int length) {
    for (int i = 0; i < length / 2; i++) {        
        std::swap(arr[i], arr[length - i - 1]);
    }
}
template <typename T>
T range_sum(T arr1[], int length1, T arr2[], int length2, T start_range, T end_range) {
    T sum = 0;   
    for (int i = 0; i < length1; i++) {
        if (arr1[i] >= start_range && arr1[i] <= end_range) {
            sum += arr1[i];
        }
    }   
    for (int i = 0; i < length2; i++) {
        if (arr2[i] >= start_range && arr2[i] <= end_range) {
            sum += arr2[i];
        }
    }
    return sum;
}
template <typename T>
void max2(const T arr[], int length, T& first_max, T& second_max) {
    if (length < 2) {
        std::cout << "Массив должен содержать как минимум два элемента." << std::endl;
        return;
    }
    first_max = second_max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > first_max) {
            second_max = first_max;
            first_max = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != first_max) {
            second_max = arr[i];
        }
    }
}
bool isPerfect(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}
void perfect_range(int start_range, int end_range) {
    if (start_range > end_range) {
        std::swap(start_range, end_range);
    }
    std::cout << "Совершенные числа в диапазоне [" << start_range << ", " << end_range << "]: ";
    for (int i = start_range; i <= end_range; i++) {
        if (isPerfect(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


int main() {
    setlocale(LC_ALL, "Russian");




    //Задача 1
    int my_array[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(my_array) / sizeof(my_array[0]);
    mirror_arr(my_array, length);
   
    for (int i = 0; i < length; i++) {
        std::cout << my_array[i] << " ";
    }

    //Задача 2
    int arr1[] = { 1, 2, 3, 4, 5 };
    int length1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = { 6, 7, 8, 9, 10 };
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    int start_range = 3;
    int end_range = 7;
    int result = range_sum(arr1, length1, arr2, length2, start_range, end_range);
    std::cout << "Сумма элементов в диапазоне [" << start_range << ", " << end_range << "] равна: " << result << std::endl;

   //Задача 3
    int my_array1[] = { 3, 7, 2, 8, 5 };
    int length3 = sizeof(my_array1) / sizeof(my_array1[0]);
    int first_max, second_max;
    max2(my_array, length, first_max, second_max);
    std::cout << "Первый максимальный элемент: " << first_max << std::endl;
    std::cout << "Второй максимальный элемент: " << second_max << std::endl;

    //Задача 4
    int start_range1, end_range1;
    std::cout << "Введите начало диапазона: ";
    std::cin >> start_range1;
    std::cout << "Введите конец диапазона: ";
    std::cin >> end_range1;
    perfect_range(start_range1, end_range1);

    

    return 0;
}