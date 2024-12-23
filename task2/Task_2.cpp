#include <cstring>
#include <iostream>
#include <cctype>
#include <limits>

void change(char* a, const char* b, int d);

int main() {
    std::cout << "Подготовил Белоусов Ашраф. Вариант 2. (На латинице) напишите свой текст, после чего вы пишите слова какой длины вы хотите заменить и на какое слово хотите заменить\n";
    std::cout << "Напишите свой текст:\n";

    int maxLength = 3000;
    char* arr = new char[maxLength];
    std::cin.getline(arr, maxLength);

    std::cout << "Введенный текст: " << arr << std::endl;
    std::cout << "Длина текста: " << strlen(arr) << std::endl;

    int MaxSlovo = 50;
    char* ar = new char[MaxSlovo];
    std::cout << "Введите слово для замены:\n";
    std::cin.getline(ar, MaxSlovo);

    int u;
    std::cout << "Введите длину слов, которые хотите заменить:\n";
    while (!isdigit(std::cin.peek())) {
        std::cin.ignore(1);
        std::cout << "Input a NUMBER. >> ";
    }
    std::cin >> u;

    change(arr, ar, u);

    std::cout << "Измененный текст: " << arr << std::endl;

    delete[] arr;
    delete[] ar;
    return 0;
}

void change(char* a, const char* b, int d) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int newLenA = lenA;

    for (int i = 0; i <= lenA - d; ++i) {
        bool match = true;
        for (int j = 0; j < d; ++j) {
            if (!isalpha(a[i + j])) {
                match = false;
                break;
            }
        }
        if (match && (i == 0 || !isalpha(a[i - 1])) && (i + d == lenA || !isalpha(a[i + d]))) {
            int diff = lenB - d;
            if (diff > 0) {
                for (int k = lenA; k >= i + d; --k) {
                    a[k + diff] = a[k];
                }
            } else if (diff < 0) {
                for (int k = i + d; k <= lenA; ++k) {
                    a[k + diff] = a[k];
                }
            }
            for (int j = 0; j < lenB; ++j) {
                a[i + j] = b[j];
            }
            i += lenB - 1; 
            newLenA += diff; 
            lenA = newLenA;
        }
    }
    a[newLenA] = '\0'; 
}