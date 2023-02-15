/*Задание Дан двумерный массив с размерами 10 на 10,
заполненный случайными числами от 0 до 100.
Задача 1
Напишите программу, которая считает сумму
каждого отдельного ряда и выводит все найденные суммы в консоль.
Задача 2
Пользователь вводит число N от 0 до 9. Программа
сортирует соответствующий ряд массива и выводит его.
Пример: N = 4, значит программа сортирует 4 ряд
двумерного массива и выводит результат сортировки.*/



#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "rus");
    const int ROWS = 10;
    const int COLS = 10;
    int arr[ROWS][COLS];
    int sum[ROWS];
    int a = 0;
    int b = 100;
    int N;

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % (b + 1 - a) + a;
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }


    std::cout << "Сумма строк массива:" << '\t';
    for (int i = 0; i < ROWS; i++) {
        sum[i] = 0;
        for (int j = 0; j < COLS; j++)
        {
            sum[i] += arr[i][j];
        }
        std::cout << sum[i] << '\t';
    }    

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            for (int k = j; k < COLS; k++) {
                if (arr[i][j] > arr[i][k])
                {
                    std::swap(arr[i][j], arr[i][k]);
                }
            }
        }
    }
    std::cout << "Введите номер ряда:" << '\t';
    std::cin >> N;
    std::cout << "Отсортированный ряд:" << '\t';
    for (int i = N - 1; i < N; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << '\t';
        }
    }
    return 0;

}